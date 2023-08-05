# UDPPingerServer.py
# We will need the following module to generate randomized lost packets
import random

import socket

# Create a UDP socket
# Notice the use of SOCK_DGRAM for UDP packets

SERVER = socket.gethostbyname(socket.gethostname())

PORT = 20001

HEADER = 1024

ADDR = (SERVER, PORT)

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Assign IP address and port number to socket

serverSocket.bind(ADDR)

print("UDP server up and listening")


while True:
    # Generate random number in the range of 0 to 10

    rand = random.randint(0, 10)

    # Receive the client packet along with the address it is coming from

    message, address = serverSocket.recvfrom(HEADER)

    print(f"Message from Client : {message}        rand_value : {rand}")

    # Capitalize the message from the client

    message = message.upper()

    # If rand is less is than 4, we consider the packet lost and do not respond

    if rand < 4:
        continue

    # Otherwise, the server responds

    serverSocket.sendto(message, address)
