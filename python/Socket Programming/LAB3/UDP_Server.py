# UDPPingerServer.py
# We will need the following module to generate randomized lost
from socket import *
import random
# Create a UDP socket
# Notice the use of SOCK_DGRAM for UDP packets
serverSocket = socket(AF_INET, SOCK_DGRAM)
# Assign IP address and port number to socket
serverSocket.bind(('', 12000))
while True:
    # Generate random number in the range of 0 to 10
      rand = random.randint(0, 10)
# Receive the client packet along with the address it is coming from
message, address = serverSocket.recvfrom(1024)
# Capitalize the message from the client
message = message.upper()
# If rand is less is than 4, we consider the packet lost and do
not respond
if rand < 4:
      print("No Packet Lost")
      Continue
else:
      print("Packet lost")
# Otherwise, the server responds
serverSocket.sendto(message, address)







# import socket

# localIP = "127.0.0.1"
# localPort = 20001
# bufferSize = 1024

# UDPServerSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
# UDPServerSocket.bind((localIP, localPort))
# print("UDP server up and listening")

# di = {'17BIT0382': 'vivek', '17BEC0647': 'shikhar', '17BEC0150': 'tanveer',
#       '17BCE2119': 'sahil', '17BIT0123': 'sidhant', '93': 'Manish'}

# while (True):
#     name, addr1 = UDPServerSocket.recvfrom(bufferSize)

#     pwd, addr1 = UDPServerSocket.recvfrom(bufferSize)

#     name = name.decode()
#     pwd = pwd.decode()
#     msg = 'welcome '+name + " \n your password is "+pwd
#     bytesToSend = str.encode(msg)


#     UDPServerSocket.sendto(bytesToSend, addr1)
