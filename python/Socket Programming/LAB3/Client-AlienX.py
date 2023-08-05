import socket
import sys
try:
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
except socket.error as err:
    print("Failed to create a socket")
    print("Reason"+str(err))
    sys.exit()
print("Socket created")

target_host=input("Enter the target hostname to connect ")
target_port=input("Enter the target port ")
try:
    s.connect((target_host, int(target_port)))
    print("Socket connected to %s"%(target_host+target_port))
    s.shutdown(2)
except socket.error as err:
    print("Failed to create a socket %s"+target_host+target_port)
    print("Reason"+str(err))
    sys.exit()




# import socket
# s = socket.socket()
# host = '127.0.0.1'
# port = 12345
# s.connect((host, port))
# print(s.recv(1024).decode())
# s.close()







# import socket
# s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# host = socket.gethostname()
# port = 1255
# s.connect((host,port))
# con = True
# while con:
#     msg = input("Enter message: ")
#     s.send(msg.encode("utf-8"))
#     if msg == "quit":
#         s.close()



# import socket

# HEADER = 64
# PORT = 5050
# DISCONNECT_MESSAGE = "!DISCONNECT"
# SERVER = "192.168.1.26"
# ADDR = (SERVER, PORT)

# client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client.connect(ADDR)


# def send(msg):
#     message = msg.encode("utf-8")
#     msg_length = len(message)
#     send_length = str(msg_length).encode("utf-8")
#     send_length += b' ' * (HEADER - len(send_length))
#     client.send(send_length)
#     client.send(message)
#     print(client.recv(2048).decode("utf-8"))


# send("Hello World!")
# input()
# send("Hello Everyone!")
# input()
# send("Hello Tim!")

# send(DISCONNECT_MESSAGE)
