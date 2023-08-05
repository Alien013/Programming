import socket

s = socket.socket()
port = 2455

n = int(input("Enter number in range 1 to 100: "))

s.connect(("127.0.0.1",port))

client_name = "Client of Manoj"
message = f"{client_name},{n}"

s.send(message.encode())

server_message = s.recv(1024).decode()
m = server_message.split(',')

print("Clients Name:",client_name)
print("Servers Name:",m[0])
print("Server Number:",int(m[1]))
print("Client Number:", n)
print("Sum of numbers:",int(m[1])+n)

s.close()