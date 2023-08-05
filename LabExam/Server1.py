import socket

host = '127.0.0.1'
port = 1001     
BUFFER_SIZE = 1024

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((host, port))
    s.listen()
    print(f'Server listening on {host}:{port}')
    conn, addr = s.accept()
    print(f'Connected by {addr}')
    with conn:
        while True:
            data = conn.recv(BUFFER_SIZE)
            if not data:
                break
            message = data.decode()
            with open('data.txt', 'a') as f:
                f.write(message + '\n')
            print(f'Received: {message}')
