#!/usr/bin/env python

"""
A simple echo server
"""

from contextlib import contextmanager
from datetime import datetime
import socket
import sys
from subprocess import *


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
    cwd = ""
    cmd = ""
    while 1:
        client, address = s.accept()
        data = client.recv(size)
        if data:
            cwd, cmd = data.split(', ', 1)
            sys.stdout.write(str(datetime.now()) + ' Received data:\n   cwd:' + cwd + '\n   cmd:' + cmd + '\n')
            p1 = Popen(cmd.split(' '),
                       stdout=PIPE,
                       stderr=PIPE,
                       cwd=cwd)
            stdout, stderr = p1.communicate()
            client.send(stdout + '\n::END_STDOUT::BEGIN_STDERR::\n' + stderr)
        client.close()
