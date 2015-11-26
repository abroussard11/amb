#!/usr/bin/env python

import sys
from util import socketcontext
import socket

def echo_client(i):
    host = 'choco'
    port = 50000
    size = 1024
    if len(build_cmd) >= size:
        sys.stderr.write('ERROR: The build command is too long\n')
        sys.exit(1)
    with socketcontext(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host,port))
        sentAt = datetime.now()
        s.send(build_cmd)
        data = s.recv(size)
        recvdAt = datetime.now()

if __name__ == '__main__':
    startedAt = datetime.now()
    for i in xrange(50):
        echo_client(i)
    endedAt = datetime.now()
    print 'Total time:', endedAt - startedAt
    sys.exit()



# """
# A simple echo client
# """
#
# from contextlib import contextmanager
# from datetime import datetime
# import socket
# import sys
#
# @contextmanager
# def socketcontext(*args, **kw):
#     s = socket.socket(*args, **kw)
#     try:
#         yield s
#     finally:
#         s.close()
#
# def echo_client(i):
#     host = 'choco'
#     port = 50000
#     size = 1024
#     with socketcontext(socket.AF_INET, socket.SOCK_STREAM) as s:
#         s.connect((host,port))
#         sentAt = datetime.now()
#         s.send('Hello, world')
#         data = s.recv(size)
#         recvdAt = datetime.now()
#
# if __name__ == '__main__':
#     startedAt = datetime.now()
#     for i in xrange(50):
#         echo_client(i)
#     endedAt = datetime.now()
#     print 'Total time:', endedAt - startedAt
#     sys.exit()
