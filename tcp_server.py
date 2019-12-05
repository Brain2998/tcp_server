import socket

sock=socket.socket()
sock.bind(('127.0.0.1', 11111))
sock.listen(1)
while True:
   conn, addr = sock.accept()
   conn.send('flag\n'.encode('utf-8'))
   conn.close()