"""
Requires nicira and packet-in conversion:

  ./pox.py openflow.discovery openflow.nicira --convert-packet-in log.level --WARNING forwarding.multitrunk --N=1 --K=2

           s1--------------------s3  
          /                        \
    h1--s5                          s6--h2
          \                        /
           s2--------------------s4  

In this version:
icmp/arp traffic goes via s1--s3
TCP connections from left to right are assigned paths through s1,s2 according to a rule
TCP traffic from right to left goes via s4--s1

The spanning tree is defined by flooders(s), and consists of all switches except for s2,s4
As links start up, linkUp establishes the ST route for icmp/arp/tcp.

As a
This forwards based on ethernet source and destination addresses.  
This component uses two tables on the switch -- one for source addresses
and one for destination addresses.  Specifically, we use tables 0 and 1
on the switch to implement the following logic:
0. Is this dest address known?
   NO:  flood
   YES: forward
   Either case: send to Table 1
1. Is this source address known?
   YES:  do nothing  (= drop)
   NO: send to controller

The map is created by calls to _handle_LinkEvent

Table initialization is done by _handle_ConnectionUp,
including a rule to forward unknown packets to the controller.
We then add new entries for ARP/ICMP traffic when such packets arrive.

To run:

  ./pox.py openflow.discovery openflow.nicira --convert-packet-in log.level --WARNING forwarding.multitrunkpox --N=1 --K=2

The N=1 and K=2 options are the defaults.
"""

from pox.core import core
from pox.lib.addresses import EthAddr
import pox.openflow.libopenflow_01 as of
import pox.openflow.nicira as nx
import pox.lib.packet as pkt
from pox.lib.revent import EventRemove
import pox.lib.util as util
import time
import threading
import signal

TCPstarted = False  # flag used to identify start of TCP traffic, which generally comes AFTER all hosts have been identified

BROADCAST = EthAddr('ff:ff:ff:ff:ff:ff')

SLEEPTIME = 10      # time in seconds

ICMP_IDLE_TIMEOUT = 0
TCP_IDLE_TIMEOUT = 0   # 10301  # 10301

# pld: should get N and K from the command line

N = 1
K = 3

# two SwitchNodes should be the same if their dpidvals are the same


class SwitchNode:
    # dpid, nmap, hmap
    def _init_(self, id, connection=None):
        self.dpidval = id
        self.nmap = {}   # map of (port, SwitchNode)
        self.hmap = {}   # map of (port, EthAddr)
        self.flagval = 0
        self.connexion = connection  # the openflow connection to the switch
        self.unknownports = []      # when all is done, this should be []

    def _str_(self):
        return "s" + str(self.dpidval)

    def _repl_(self):
        return "s" + str(self.dpidval)

    def dpid(self):
        return self.dpidval

    def switchPorts(self):  # returns list of ports that lead to other switches
        return self.nmap.keys()

    def hostPorts(self):    # returns list of ports that lead to hosts
        return self.hmap.keys()

    # list of switch's ports, without knowing what they connect to
    def setUnknownPorts(self, portlist):
        self.unknownports = []
        for p in portlist:
            if not (p in self.nmap) and not (p in self.hmap):
                self.unknownports.append(p)

    def switchNeighbors(self):  # returns list of all switch neighbors
        return self.nmap.values()

    def hostNeighbors(self):  # returns list of all switch neighbors
        return self.hmap.values()

    def addSwitchNeighbor(self, port, n):   # n is the neighbor SwitchNode
        # if not port in self.unknownports:
        #    print("{}.addSwitchNeighbor({},{}): port {} not reserved".format(self, port, n, port))
        self.nmap[port] = n
        if port in self.unknownports:
            self.unknownports.remove(port)

    def addHostNeighbor(self, port, n):     # n is an EthAddr
        # if not port in self.unknownports:
        #   print("{}.addHostNeighbor({},{}): port {} not reserved".format(self, port, n, port))
        self.hmap[port] = n
        if port in self.unknownports:
            self.unknownports.remove(port)

    def switchNeighbor(self, port):  # returns the switch reached by that port
        if port in self.nmap:
            return self.nmap[port]
        else:
            return None

    def hostNeighbor(self, port):   # returns the (EthAddr) host reached by that port
        if port in self.hmap:
            return self.hmap[port]
        else:
            return None
    # returns the port needed to reach the given switch (by SwitchNode), or None

    def portToSwitchNeighbor(self, switch):
        for p in self.nmap:
            if self.switchNeighbor(p) == switch:
                return p
        return None
    # returns the port needed to reach the given host (by EthAddr), or None

    def portToHostNeighbor(self, host):
        for p in self.hmap:
            if self.hostNeighbor(p) == host:
                return p
        return None

    def setFlag(self, val):
        self.flagval = val

    def setFlag0(self):
        self.flagval = 0

    def flag(self):
        return self.flagval

    def connection(self):
        return self.connexion

    def setConnection(self, conn):  # conn is the openflow connection to the switch
        self.connexion = conn

    def _hash_(self):
        return self.dpidval

    def _eq_(self, other):
        if isinstance(other, self._class_):
            return self.dpidval == other.dpidval
        else:
            return False

# represents a one-way flow, including ethernet and IPv4 addresses and TCP ports.


class Flow:
    def _init_(self, ethsrc, ethdst, srcip, dstip, srcport, dstport):
        self.ethsrc = ethsrc
        self.ethdst = ethdst
        self.srcip = srcip
        self.dstip = dstip
        self.srcport = srcport
        self.dstport = dstport

    def reverse(self):
        return Flow(self.ethdst, self.ethsrc, self.dstip, self.srcip, self.dstport, self.srcport)

    def _str_(self):
        return '(h{}->h{},{},{},{},{})'.format(hostnum(self.ethsrc), hostnum(self.ethdst), self.srcip, self.dstip, self.srcport, self.dstport)
        # return '({},{},{},{},{},{})'.format(self.ethsrc, self.ethdst,self.srcip, self.dstip, self.srcport, self.dstport)

    def _hash_(self):
        return hash((self.ethdst, self.ethsrc, self.dstip, self.srcip, self.dstport, self.srcport))

    def _eq_(self, other):
        return self.ethsrc == other.ethsrc and self.ethdst == other.ethdst and self.srcip == other.srcip and self.dstip == other.dstip and self.srcport == other.srcport

    def crosses(self):
        if hostnum(self.ethsrc) <= N and hostnum(self.ethdst) > N:
            return True
        if hostnum(self.ethsrc) > N and hostnum(self.ethdst) <= N:
            return True
        return False

    def top_to_bottom(self):
        if hostnum(self.ethsrc) <= N and hostnum(self.ethdst) > N:
            return True
        return False


def printpath(path):
    plen = len(path)
    for i in range(plen):
        node = path[i]
        if type(node) is EthAddr:
            node = 'h'+str(hostnum(node))
        print(node)
    print

# main dictionaries


switchmap = {}  # map of all switches, by dpid: <dpid, SwitchNode>

flow_to_path = {}   # map of (one-way) Flows to list from host to host.

known_hosts = []    # hostnums of known hosts

# Even a simple usage of the logger is much nicer than print!
log = core.getLogger()


def switchpeer(i):
    if i <= K:
        return i+K
    return i-K


def flooder(dpid):
    if dpid == 1 or dpid == K+1:
        return True
    # if dpid == 1: return True
    if dpid <= 2*K:
        #print("non-flooder: dpid=", dpid)
        return False
    return True

# frontline switches are the entry switches, eg s7-s16
# def frontline(dpid):
#    if dpid > 2*K: return True
#    return False


########### _handle_ConnectionUp  ##################

def _handle_ConnectionUp(event):
    # Initialize the forwarding rules for this switch.
    # After setting up, we send a barrier and wait for the response
    # before starting to listen to packet_ins for this switch -- before
    # the switch is set up, the packet_ins may not be what we expect,
    # and our responses may not work!

    connection = event.connection
    dpid = connection.dpid
    print("handle_ConnectionUP from dpid", dpid, util.dpid_to_str(dpid))
    portlist = connection.ports.values()
    # get port_no of each item in portlist
    portlist = map(lambda x: x.port_no, portlist)
    portlist = filter(lambda x: x < of.OFPP_MAX, portlist)
    # print("portlist:", portlist)
    # Turn on Nicira packet_ins
    msg = nx.nx_packet_in_format()
    connection.send(msg)
    # Turn on this switch's ability to specify tables in flow_mods
    msg = nx.nx_flow_mod_table_id()
    connection.send(msg)
    # Clear first table
    msg = nx.nx_flow_mod(command=of.OFPFC_DELETE, table_id=0)
    connection.send(msg)
    # Clear second table
    msg = nx.nx_flow_mod(command=of.OFPFC_DELETE, table_id=1)
    connection.send(msg)

    # this version sets default flooding actions only for ICMP and ARP packets
    # (though there IS a rule to send unknown packets to the controller)
    # Default rule for table 0: flood (IF a flooder) and send to table 1
    # Default rule for table 1: send to controller
    # match on packet type, but not on source
    msgi = nx.nx_flow_mod()  # icmp msg
    msga = nx.nx_flow_mod()  # arp msg
    msgi.table_id = msga.table_id = 0
    msgi.priority = msga.priority = 1  # Low priority
    msgi.idle_timeout = msga.idle_timeout = ICMP_IDLE_TIMEOUT

    msgi.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.IP_TYPE))
    msgi.match.append(nx.NXM_OF_IP_PROTO(pkt.ipv4.ICMP_PROTOCOL))
    msga.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.ARP_TYPE))

    if flooder(dpid):
        msgi.actions.append(of.ofp_action_output(port=of.OFPP_FLOOD))
        msga.actions.append(of.ofp_action_output(port=of.OFPP_FLOOD))
    msgi.actions.append(nx.nx_action_resubmit.resubmit_table(table=1))
    msga.actions.append(nx.nx_action_resubmit.resubmit_table(table=1))
    connection.send(msgi)
    connection.send(msga)

    # pld fallthrough rule for table 1: send to controller
    msgi = nx.nx_flow_mod()  # icmp msg
    msga = nx.nx_flow_mod()  # arp msg
    msgi.table_id = msga.table_id = 1
    msgi.priority = msga.priority = 1  # Low priority
    msgi.idle_timeout = msga.idle_timeout = ICMP_IDLE_TIMEOUT

    msgi.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.IP_TYPE))
    msgi.match.append(nx.NXM_OF_IP_PROTO(pkt.ipv4.ICMP_PROTOCOL))
    msga.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.ARP_TYPE))

    msgi.actions.append(of.ofp_action_output(port=of.OFPP_CONTROLLER))
    msga.actions.append(of.ofp_action_output(port=of.OFPP_CONTROLLER))
    connection.send(msgi)
    connection.send(msga)

    if flooder(dpid):   # create emtpy default action (applies mostly to TCP traffic)
        msgdef = nx.nx_flow_mod()
        msgdef.table_id = 0
        msgdef.priority = 0  # pld: MUST HAVE THIS
        msgdef.actions.append(of.ofp_action_output(port=of.OFPP_CONTROLLER))
        connection.send(msgdef)

    def ready(event):      # called right below, as parameter
        if event.ofp.xid != 0x80000000:
            # Not the right barrier
            return
        log.info("%s ready", event.connection)
        event.connection.addListenerByName("PacketIn", _handle_PacketIn)
        return EventRemove

    connection.send(of.ofp_barrier_request(xid=0x80000000))
    connection.addListenerByName("BarrierIn", ready)

    # now install switch
    if dpid in switchmap:
        sw = switchmap[dpid]
        if sw.connection() is None:
            sw.setConnection(connection)
    else:
        sw = SwitchNode(dpid, connection)
        switchmap[dpid] = sw
    # now add empty port list
    sw.setUnknownPorts(portlist)


########  _handle_PacketIn  #######################

# PacketIn should tell us what switch ports connect to HOSTS

TCPflows = []       # list of TCP connections starting at lefthand/upper side


def _handle_PacketIn(event):
    global TCPstarted, flow_to_path, known_hosts
    packet = event.parsed
    packet_in = event.ofp    # The actual ofp_packet_in message.
    psrc = packet.src
    pdst = packet.dst
    inport = packet_in.in_port  # is this the same as event.port?
    assert inport == event.port, "inport {} not equal to event.port {}".format(
        inport, event.port)
    dpid = event.connection.dpid
    sw = switchmap[dpid]    # the switch should be in switchmap by now

    # handle_PacketIn ignores the trunk switches except for s[1]---s[K+1]
    # the other trunk paths are used ONLY when paths are created.
    if not flooder(dpid):
        return    # but frontline flooder switches can still install arbitrary paths

    if isdhcp(packet):
        return       # pld: ignore DHCP traffic

    # see if this packet came from a known switch
    if dpid in switchmap:
        switch = switchmap[dpid]
    else:
        switch = None
        print("unknown switch s{}".format(dpid))       # no point continuing?)

    # was this packet forwarded FROM another switch?
    isFromSwitch = (inport in switch.switchPorts())

    # if this port isn't in the switchport list, assume it's a direct host connection
    if not isFromSwitch:
        # if we have NOT seen psrc before as a host
        if not psrc in switch.hostNeighbors():
            if ishost(psrc):
                print("Adding host connection {}.{} <---> h{} [type {}]".format(
                    switch, inport, hostnum(psrc), format(packet.type, '04x')))
                switch.addHostNeighbor(inport, psrc)
                known_hosts.append(hostnum(psrc))
                print('known hosts:', known_hosts)
            else:  # from a host port but not a normal host
                udp = packet.find('udp')
                if udp is not None and udp.srcport != 67 and udp.dstport != 67:
                    print("{}: sees weird packet from {} via port {}".format(
                        switch, psrc, inport))
            #switch.addHostNeighbor(inport, psrc)

    icmp = packet.find('icmp')
    arp = packet.find('arp')
    ipv4 = packet.find('ipv4')
    tcp = packet.find('tcp')
    udp = packet.find('udp')

    if arp is not None:
        proto = 'ARP'
    elif icmp is not None:
        proto = 'ICMP'
    elif tcp is not None:
        proto = 'TCP'
    elif udp is not None:
        proto = 'UDP'
    elif ipv4 is not None:
        proto = 'IPv4 non-TCP'
    else:
        proto = 'unknown'

    print('packetIn received {} packet from s{}'.format(proto, dpid))
    if (icmp is not None or arp is not None):
        #print('installing entry for h{} into {} via {} packet'.format(hostnum(psrc), sw, proto))
        install_icmp_entry(event, psrc)
        return

    if tcp is None:
        if packet.type != 0x800:
            print("unknown packet type:", packet.type)
        else:
            if udp is None:
                print('unknown packet, not UDP or TCP')
            elif udp.srcport == 67 or udp.dstport == 67:    # dhcp
                pass
            else:
                print("unknown udp packet from ({},{}) to ({},{})".format(),
                      ipv4.srcip, udp.srcport, ip.dstip, udp.dstport)
        return

    # now we know it's a TCP packet
    if not TCPstarted and tcp is not None:
        TCPstarted = True
        # TCPstart()
    if tcp is not None:     # no reason to check this!
        # if hostnum(psrc) <= N and hostnum(pdst) >= N:
        flow = Flow(psrc, pdst, ipv4.srcip, ipv4.dstip,
                    tcp.srcport, tcp.dstport)
        if flow_to_path.get(flow) is not None:
            # we've seen this TCP connection before
            path = flow_to_path[flow]
            if sw not in path:
                return
            print('Retrying TCP flow:', flow, 'via switch', sw)
        else:
            trunkswitch = picktrunk(flow)
            path = findpath(flow, trunkswitch)
            flow_to_path[flow] = path
            # only consider rerouting left-to-right TCP connections
            if hostnum(flow.ethsrc) <= N and hostnum(flow.ethdst) > N:
                TCPflows.append(flow)
                if len(TCPflows) == 2:
                    print('starting second TCP connection')
                    moveTCPflow(TCPflows[0], switchmap[2])
            print("adding TCP route h{} -> h{} via {}".format(hostnum(flow.ethsrc),
                  hostnum(flow.ethdst), trunkswitch))
        # may fail if not all host ports are known yet
        result = create_path_entries(flow, path)
        if not result and sw in path:   # tell switch to flood if it's on the path?
            print('Flooding at', sw, 'on TCP connection', flow)
            msg = of.ofp_packet_out()
            msg.data = packet_in
            action = of.ofp_action_output(port=of.OFPP_FLOOD)
            msg.actions.append(action)
            event.connection.send(msg)
        # shortcut to creating the reverse path; NOT CURRENTLY USED
        # addTCProute(flow.reverse(), switchmap[3])  # try having the reverse traffic take a different path?


lastTrunk = K       # guarantees next trunk assigned will be s1


def picktrunk(flow):    # returns a SwitchNode
    global lastTrunk
    ha = flow.ethsrc    # starting host
    if hostnum(ha) > N:     # righthand host
        return switchmap[1]
    else:
        if lastTrunk == K:
            lastTrunk = 1
        else:
            lastTrunk += 1
        return switchmap[lastTrunk]


def packet_type(packet):
    if packet.find('icmp'):
        return 'icmp'
    if packet.find('arp'):
        return 'arp'
    if packet.find('dhcp'):
        return 'dhcp'
    if packet.find('tcp'):
        return 'tcp'
    if packet.find('udp'):
        return 'udp'
    return 'unknown'

# this installs entries for ICMP traffic, and also ARP


def install_icmp_entry(event, psrc):
    # FINALLY add to the tables. Only ICMP and ARP packets should get here.

    # Add to destination table. pld: this is now table 0
    # add flow for ICMP
    msg = nx.nx_flow_mod()  # pld: was "lmsg": woe
    msg.match = nx.nx_match()   # pld: see pox dox "Using nx_match"
    msg.table_id = 0
    msg.match.append(nx.NXM_OF_ETH_DST(psrc))
    msg.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.IP_TYPE))
    msg.match.append(nx.NXM_OF_IP_PROTO(pkt.ipv4.ICMP_PROTOCOL))

    msg.actions.append(of.ofp_action_output(port=event.port))
    msg.actions.append(nx.nx_action_resubmit.resubmit_table(table=1))
    event.connection.send(msg)

    # Now add to source table. pld: this is now table 1
    msg = nx.nx_flow_mod()
    msg.match = nx.nx_match()   # pld: see pox dox "Using nx_match"
    msg.table_id = 1
    msg.match.append(nx.NXM_OF_ETH_SRC(psrc))
    msg.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.IP_TYPE))
    msg.match.append(nx.NXM_OF_IP_PROTO(pkt.ipv4.ICMP_PROTOCOL))
    # empty action list here, meaning no longer send to the controller
    event.connection.send(msg)

    # now add similar entries for ARP

    msg = nx.nx_flow_mod()
    msg.match = nx.nx_match()   # pld: see pox dox "Using nx_match"
    msg.table_id = 0
    msg.match.append(nx.NXM_OF_ETH_DST(psrc))
    msg.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.ARP_TYPE))
    msg.actions.append(of.ofp_action_output(port=event.port))
    msg.actions.append(nx.nx_action_resubmit.resubmit_table(table=1))
    event.connection.send(msg)

    msg = nx.nx_flow_mod()
    msg.match = nx.nx_match()   # pld: see pox dox "Using nx_match"
    msg.table_id = 1
    msg.match.append(nx.NXM_OF_ETH_SRC(psrc))
    msg.match.append(nx.NXM_OF_ETH_TYPE(pkt.ethernet.ARP_TYPE))
    # again an empty action list
    event.connection.send(msg)

    log.info("Learning %s on port %s of %s"
             % (psrc, event.port, event.connection))
    # req_flow_stats1(event.connection)

    # if dpid == mon_dpid and ishost(packet.src):
    ##   print("s"+str(dpid) +":", "packet from", packet.src, "arriving on port", event.port)


########  _handle_LinkEvent  #######################

# pld: LinkEvents don't need the "barrier" trick that PacketIn events do.
# Although we really would like to know when all the LinkEvents are received.

def _handle_LinkEvent(event):
    l = event.link
    # print(l)
    sw1 = l.dpid1
    sw2 = l.dpid2
    pt1 = l.port1
    pt2 = l.port2
    #  link from (sw1,pt1) to (sw2,pt2); may or may not be new
    # if sw2 < sw1: sw1,pt1,sw2,pt2 = sw2,pt2,sw1,pt1
    if sw2 < sw1:
        return
    sw1s = str(sw1)
    pt1s = str(pt1)
    sw2s = str(sw2)
    pt2s = str(pt2)
    #print('link added is %s'%event.added)
    #print('link removed is %s' %event.removed)
    if event.added:
        change = 'added'
    else:
        change = 'removed'
        return     # pld: TEMPORARILY don't do anything when links go down
    #print(change+':', 's'+sw1s+'.'+pt1s, '<-->', 's'+sw2s+'.'+pt2s)
    # look up switches in switchmap (or install them)
    if sw1 in switchmap:
        s1 = switchmap[sw1]
    else:
        s1 = SwitchNode(sw1)
        switchmap[sw1] = s1
    if sw2 in switchmap:
        s2 = switchmap[sw2]
    else:
        s2 = SwitchNode(sw2)
        switchmap[sw2] = s2
    s1pt1 = s1.switchNeighbor(pt1)   # old neighbor s1[pt1]

    # this is a new report if s1pt1 == None
    if s1pt1 != None and s1pt1 != s2:
        print("warning: switch {} changed port {} neighbor from {} to {}".format(
            s1, pt1, s1pt1, s2))
    else:
        pass
        #print("switch {} gets port {} neighbor {}".format(s1,pt1,s2))

    # if s1pt1 != None and s1pt1 == s2: do nothing
    if s1pt1 != s2:
        s1.addSwitchNeighbor(pt1, s2)

    s2pt2 = s2.switchNeighbor(pt2)  # old neighbor s2[pt2]
    if s2pt2 != None and s2pt2 != s1:
        print("warning: switch {} changed port {} neighbor from {} to {}".format(
            s2, pt2, s2pt2, s1))
    else:
        pass
        #print("switch {} gets port {} neighbor {}".format(s2,pt2,s1) )

    if s2pt2 != s1:
        s2.addSwitchNeighbor(pt2, s1)

    if s1pt1 == None and s2pt2 == None:
        print('adding switch connection:', 's'+sw1s +
              '.'+pt1s, '<-->', 's'+sw2s+'.'+pt2s)
    elif s1pt1 == None:   # but s2 has s1 as a neighbor already
        print('adding switch connection:', 's'+sw1s +
              '.'+pt1s, '--->', 's'+sw2s+'.'+pt2s)
    elif s2pt2 == None:
        print('adding switch connection:', 's'+sw2s +
              '.'+pt2s, '--->', 's'+sw1s+'.'+pt1s)

#######################  TCP handling ##########################

# ts here is one of s1,s2,s3


def findpath(flow, ts):
    ha = flow.ethsrc
    hb = flow.ethdst
    ida = hostnum(ha)
    idb = hostnum(hb)
    if ida <= N and idb <= N:   # both on upper side
        return path_both_upper(flow, ts)
    if ida > N and idb > N:     # both on lower side
        ts2 = switchmap[switchpeer(ts.dpid())]
        return path_both_lower(flow, ts2)
    if ida > N and idb <= N:     # lower to upper: just reverse the direction
        #print("swapping", ida, "and", idb)
        return revlist(path_upper_to_lower(flow.reverse(), ts))
    return path_upper_to_lower(flow, ts)


# creates TCP rules at each switch in the path.
# The first and last entries of the path must be hosts.
# switch entries on the path are of type SwitchNode, not dpids
# path must contain at least one switch!
# ha-->s1-->s2-->...->sM-->hb

def create_path_entries(flow, path):
    plen = len(path)
    print('create_path_entries: flow:', flow)
    print('create_path_entries: path:', )
    printpath(path)
    lastswitch = path[plen-2]
    port_to_host = lastswitch.portToHostNeighbor(path[plen-1])
    if port_to_host is None:
        print('*WARNING*: create_path_entries: switch {} has no port to host {}'.format(
            lastswitch, path[plen-1]))
        print('known_hosts:', known_hosts)
        return False
    addTCPrule(lastswitch, flow, port_to_host)
    i = plen-3
    while i > 0:
        sw = path[i]
        nsw = sw.portToSwitchNeighbor(path[i+1])   # n
