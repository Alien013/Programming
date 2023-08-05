import socket

import time

SERVER = socket.gethostbyname(socket.gethostname())

PORT = 20001

HEADER = 1024

ADDR = (SERVER, PORT)

# Create a UDP socket at client side

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

client.settimeout(1)

# Send to server using created UDP socket

rtts = []

packet_loss_rate = 0

for i in range(1, 11):

    send_time = time.time()

    msgFromClient = f"{send_time}"

    bytesToSend = str.encode(msgFromClient)

    client.sendto(bytesToSend, ADDR)

    try:
        msgFromServer = client.recvfrom(HEADER)

        recv_time = time.time()

        rtts.append(recv_time-send_time)


        msg = f"Message from Server {msgFromServer[0]}        Round Trip Time : {recv_time-send_time}"

        print(msg)

    except TimeoutError:
        packet_loss_rate = packet_loss_rate+1
        print("Stopped!")
        break

