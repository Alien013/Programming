from mininet.topo import Topo
from mininet.net import Mininet
from mininet.node import OVSSwitch, RemoteController
from mininet.link import TCLink


class MyTopo(Topo):
    def __init__(self):
        Topo.__init__(self)

        # Add hosts
        h1 = self.addHost('h1')
        h2 = self.addHost('h2')

        # Add switches
        s1 = self.addSwitch('s1', cls=OVSSwitch)
        s2 = self.addSwitch('s2', cls=OVSSwitch)
        s3 = self.addSwitch('s3', cls=OVSSwitch)
        s4 = self.addSwitch('s4', cls=OVSSwitch)
        s5 = self.addSwitch('s5', cls=OVSSwitch)
        s6 = self.addSwitch('s6', cls=OVSSwitch)

        # Add links
        self.addLink(h1, s1)
        self.addLink(s1, s2)
        self.addLink(s1, s3)
        self.addLink(s2, s4)
        self.addLink(s3, s6)
        self.addLink(s4, s5)
        self.addLink(s5, s6)
        self.addLink(s6, h2)


topo = MyTopo()
net = Mininet(topo=topo, controller=None, link=TCLink)

# Start network
net.start()

# Start CLI
net.interact()

# Stop network
net.stop()
