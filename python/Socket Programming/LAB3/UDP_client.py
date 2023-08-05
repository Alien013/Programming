import time
import socket

count = 0
max = 0
min = 100000000000000000000
sum=0
for pings in range(10):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.settimeout(1.0)
    message = b'test'
    address = ("127.0.0.1", 12000)

    start = time.time()
    client_socket.sendto(message, address)

    count = count + 1
    print(count, "\n", "current time: ", start)

    try:
        data, server = client_socket.recvfrom(1024)
        end = time.time()
        elapsed = end - start
        print(f'{data} {pings} {elapsed}')

    except socket.timeout:
        print('REQUEST TIMED OUT')

    if start > max:
        max = start

    if min > start:
        min = start
    sum = sum+start

    avg = sum/10
print(max)
print(min)
print(avg)









# import socket

# name = input('enter your username : ')
# bytesToSend1 = str.encode(name)
# password = input('enter your password : ')
# bytesToSend2 = str.encode(password)

# serverAddrPort = ("127.0.0.1", 20001)
# bufferSize = 1024

# UDPClientSocket = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)

# UDPClientSocket.sendto(bytesToSend1, serverAddrPort)
# UDPClientSocket.sendto(bytesToSend2, serverAddrPort)

# msgFromServer = UDPClientSocket.recvfrom(bufferSize)
# msg = "Message from Server {}".format(msgFromServer[0].decode())
# print(msg)
