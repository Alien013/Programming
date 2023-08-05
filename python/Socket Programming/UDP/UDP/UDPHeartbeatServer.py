# UDPPingerServer.py
# We will need the following module to generate randomized lost packets
import random

import time

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

    rand = random.randint(0, 2)

    # Receive the client packet along with the address it is coming from

    recv_time = time.time()

    message, address = serverSocket.recvfrom(HEADER)

    print(f"Message from Client : {message}")

    # Capitalize the message from the client

    # message = message.upper()

    send_time = float(message)

    time_diff = (recv_time - send_time)+rand

    # If rand is less is than 4, we consider the packet lost and do not respond

    # if rand < 4:
    #     continue
    if time_diff > 1:
        print(f"Message from Client : {message}     RTT : {time_diff-1}      Client Stopped running!")
        break

    # Otherwise, the server responds

    serverSocket.sendto(message, address)
