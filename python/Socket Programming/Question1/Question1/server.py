import socket

server_name = "Manoj's Server"
server_no = 34

s = socket.socket()

port = 2455

s.bind(("127.0.0.1",port))

s.listen(5)
print("Socket is listening")


while True:
    c,addr = s.accept()
    print("Got connection from", addr)

    message = c.recv(1024).decode()
    m = message.split(',')

    #1
    print("Clients Name:",m[0])
    print("Servers Name:",server_name)

    #2
    print("Client Number:",int(m[1]))
    print("Server Number:", server_no)
    print("Sum of numbers:",int(m[1])+server_no)

    #3
    c.send(f'{server_name},{server_no}'.encode())

    #4
    if(int(m[1]) > 100 and int(m[1]) < 1):
        c.close()
        break