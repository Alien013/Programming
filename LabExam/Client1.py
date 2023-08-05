import socket
import random
import time
host = '127.0.0.1' 
port = 1001      
BUFFER_SIZE = 1024
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((host, port))
    print(f'Connected to server at {host}:{port}')
    while True:
        h = random.randint(40, 70)
        t = random.randint(10, 30)
        message = f'[{h},{t}]'
        s.sendall(message.encode())
        print(f'Sent: {message}')
        time.sleep(5)