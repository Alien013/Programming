import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 10000)
print('Starting up on {} port {}'.format(*server_address))
sock.bind(server_address)

while True:
    data, address = sock.recvfrom(4096)

    print('Received {} bytes from {}:{}'.format(len(data), *address))
    print(data.decode())

    message = input('Enter your message: ')
    sock.sendto(message.encode(), address)
