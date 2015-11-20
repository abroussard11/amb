#!/usr/bin/env python

"""
A simple echo server
"""

from contextlib import contextmanager
from datetime import datetime
import socket
import sys

@contextmanager
def socketcontext(*args, **kw):
    s = socket.socket(*args, **kw)
    try:
        yield s
    finally:
        s.close()

###############
## Main Routine
###############
host = ''
port = 50000
backlog = 5
size = 1024
with socketcontext(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((host,port))
    s.listen(backlog)
    while 1:
        client, address = s.accept()
        data = client.recv(size)
        if data:
            sys.stdout.write(str(datetime.now()) + ' Received data:' + data + '\n')
            client.send(data)
        client.close()
