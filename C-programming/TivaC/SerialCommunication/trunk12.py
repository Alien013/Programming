"""trunk12: 1 hosts at each end, with 2 trunk connections::

"""

from mininet.topo import Topo
from mininet.net import Mininet
from mininet.link import TCLink
from mininet.node import Node, Host, OVSSwitch, OVSKernelSwitch, Controller, RemoteController, DefaultController
from mininet.cli import CLI
from mininet.log import setLogLevel
import argparse

BANDWIDTH = 20  # in megabits per second
BANDWIDTH = 20


class TrunkNKTopo(Topo):
    "Two clusters of N hosts each, joined by K trunk lines."

    def _init_(self, **kwargs):
        "Create trunk topo."
        super(TrunkNKTopo, self)._init_(**kwargs)
        h = []
        s = []
        # t = []

        N = 1
        K = 2
        for key in kwargs:
            if key == 'N':
                N = kwargs[key]
            if key == 'K':
                K = kwargs[key]
        # Initialize topology
        # Topo._init_( self )

        # add 2K trunk switches
        # switches with i=0 and i=K are the "primary" path from top to bottom
        for i in range(2*K):
            s += [self.addSwitch('s' + str(i+1))]

        # add 2N entry/exit switches
        for i in range(2*N):
            s += [self.addSwitch('s' + str(2*K+i+1))]

        # add trunk links
        # should these be port 0?
        for i in range(K):
            self.addLink(s[i], s[i+K], bw=BANDWIDTH)

        # link the ti switches to the sj, both ends:
        for i in range(N):
            for j in range(K):
                self.addLink(s[2*K+i], s[j], bw=BANDWIDTH)
                self.addLink(s[2*K+N+i], s[K+j], bw=BANDWIDTH)

        # now start with the hosts

        # add 2N hosts
        for i in range(2*N):
            h += [self.addHost('h' + str(i+1))]

        # Add links from hi to ti, both layers
        # again, these ports should be 0??
        for i in range(N):
            self.addLink(h[i], s[2*K+i], bw=BANDWIDTH)
            self.addLink(h[N+i], s[2*K+N+i], bw=BANDWIDTH)


c = RemoteController('c', ip='127.0.0.1', port=6633)


topos = {'trunkNK': (lambda **kwargs: TrunkNKTopo(**kwargs))}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-N', '--N', type=int)
    parser.add_argument('-K', '--K', type=int)
    args = parser.parse_args()
    N = 1  # the defaults
    K = 3
    if args.N is not None:
        N = args.N
    if args.K is not None:
        K = args.K
    trunktopo = TrunkNKTopo(N=N, K=K)
    # setLogLevel('info')
    net = Mininet(topo=trunktopo, switch=OVSKernelSwitch, controller=RemoteController,
                  autoSetMacs=True,
                  link=TCLink
                  )  # ipBase = IPBASE
    c = RemoteController('c', ip='127.0.0.1', port=6633)
    net.addController(c)
    net.start()

    for i in range(2*N):
        hi = net['h' + str(i+1)]
        hi.cmd('/usr/sbin/sshd', '-D', '&')
        hi.cmd('/bin/netcat', '-kl', '5432', '>/dev/null', '2>&1', '&')
        # hi.cmd('/bin/netcat -kl 5432 >/dev/null 2>&1 &')

    CLI(net)
    net.stop()


setLogLevel('info')
main()
