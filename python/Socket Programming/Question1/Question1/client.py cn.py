import socket
import threading
IP_ADDRESS = '127.0.0.1'
PORT = 5000
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind((IP_ADDRESS, PORT))


def receive_messages():
    while True:
        message, client_address = server_socket.recvfrom(1024)
        message = message.decode()
        print(f"Received message '{message}' from {client_address}")
        for address in client_addresses:
            if address != client_address:
                server_socket.sendto(message.encode(), address)


client_addresses = []
