# import socket
# s = socket.socket()
# print("Socket successfully created")
# host = '127.0.0.1'
# port = 12345
# s.bind((host, port))
# print("socket binded to %s" % (port))
# s.listen(5)
# print("socket is listening")
# while True:
#     c, addr = s.accept()
#     print('Got connection from', addr)
#     c.send('Thank you for connecting'.encode())
#     c.close()
#     break


import socket
import random
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = socket.gethostname()
port = 1255
server = 'ManojvServer'
s.bind((host, port))
s.listen(5)
socketclient, address = s.accept()
print("got connection from ", address)
con = True
while con:
    msg = socketclient.recv(1024)
    msg = msg.decode("utf-8")
    num = input()
    print(msg)

    if (con == "quit"):
        s.close()


# print(server)
# print(random.randint(0,100))


# import socket
# import threading

# HEADER = 64
# PORT = 5050
# SERVER = socket.gethostbyname(socket.gethostname())
# ADDR = (SERVER, PORT)
# FORMAT = 'utf-8'
# DISCONNECT_MESSAGE = "!DISCONNECT"

# server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# server.bind(ADDR)


# def handle_client(conn, addr):
#     print(f"[NEW CONNECTION] {addr} connected.")

#     connected = True
#     while connected:
#         msg_length = conn.recv(HEADER).decode(FORMAT)
#         if msg_length:
#             msg_length = int(msg_length)
#             msg = conn.recv(msg_length).decode(FORMAT)
#             if msg == DISCONNECT_MESSAGE:
#                 connected = False

#             print(f"[{addr}] {msg}")
#             conn.send("Msg received".encode(FORMAT))

#     conn.close()


# def start():
#     server.listen()
#     print(f"[LISTENING] Server is listening on {SERVER}")
#     while True:
#         conn, addr = server.accept()
#         thread = threading.Thread(target=handle_client, args=(conn, addr))
#         thread.start()
#         print(f"[ACTIVE CONNECTIONS] {threading.activeCount() - 1}")


# print("[STARTING] server is starting...")
# start()
