import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = (input('Enter the server IP address: '),int(input('Enter the server port number: ')))

while True:
    message = input('Enter your message: ')
    sock.sendto(message.encode(), server_address)

    data, address = sock.recvfrom(4096)
    print('Received {} bytes from {}:{}'.format(len(data), *address))
    print(data.decode())
