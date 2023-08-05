import socket

SERVER = socket.gethostbyname(socket.gethostname())

PORT = 20001

HEADER = 1024

ADDR = (SERVER, PORT)


msgFromServer = "Hello UDP Client"

bytesToSend = str.encode(msgFromServer)


# Create a datagram socket

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


# Bind to address and ip

server.bind(ADDR)


print("UDP server up and listening")


# Listen for incoming datagrams

while (True):
    bytesAddressPair = server.recvfrom(HEADER)
    message = bytesAddressPair[0]
    address = bytesAddressPair[1]

    clientMsg = "Message from Client:{}".format(message)
    clientIP = "Client IP Address:{}".format(address)

    print(clientMsg)
    print(clientIP)

    # Sending a reply to client
    
    server.sendto(bytesToSend, address)
