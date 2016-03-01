#!/usr/bin/env python3

## System imports
import asyncio
from collections import deque
from   datetime import datetime
import os
from   socket import *
from   select import select
from   subprocess import *
import sys
import time

## Local imports
from . import config
from .util import AsyncSocket, AsyncSocketcontext

#######################
## Global varibles
#######################
tasks = deque()
recv_wait = { } # Mapping sockets -> tasks (generators)
send_wait = { }
future_wait = { }

future_notify, future_event = socketpair()

def future_done(future):
    tasks.append(future_wait.pop(future))
    future_notify.send(b'x')

def future_monitor():
    while True:
        yield 'recv', future_event
        future_event.recv(100)

#######################
## Function definitions
#######################
def request_handler(client):
    size = config.SIZE
    sockdata = yield from client.recv(size)
    data = sockdata.decode('ascii')
    if data:
        tup = data.split(', ', 1)
        cwd = os.path.abspath(tup[0])
        cmd = tup[1].rstrip()
        timestamp = str(datetime.now())
        sys.stdout.write(timestamp + ' Received data:\n')
        sys.stdout.write('  data:' + data + '\n')
        sys.stdout.write('   cwd:' + cwd + '\n')
        sys.stdout.write('   cmd:' + cmd + '\n')
        time.sleep(2)
        yield from client.send(sockdata)
        #p1 = Popen(cmd.split(' '), stdout = PIPE, stderr = PIPE, cwd = cwd)
        #stdout, stderr = p1.communicate()
        #print('   Got: stdout =', stdout)
        #print('   Got: stderr =', stderr)
        #yield from client.send(stdout
        #    + '\n::END_STDOUT::BEGIN_STDERR::\n'
        #    + stderr)

def MasterNodeManager():
    host = config.HOST
    port = config.PORT
    backlog = config.BACKLOG

    with AsyncSocketcontext(AF_INET, SOCK_STREAM) as sock:
        sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
        address = ('', port)
        sock.bind(address)
        sock.listen(backlog)
        while True:
            client, address = yield from sock.accept()
            print("Connection", address)
            tasks.append(request_handler(client))

#######################
## Main Routine
#######################
def run():
    tasks.append(MasterNodeManager())
    while any([tasks, recv_wait, send_wait]):
        while not tasks:
            # No active tasks to run
            # wait for I/O
            can_recv, can_send, can_other = select(recv_wait, send_wait, [])
            for s in can_recv:
                tasks.append(recv_wait.pop(s))
            for s in can_send:
                tasks.append(send_wait.pop(s))
        task = tasks.popleft()
        try:
            why, what = next(task) # Run to the yeild
            if why == 'recv':
                # Must go wait somewhere
                recv_wait[what] = task
            elif why == 'send':
                send_wait[what] = task
            elif why == 'future':
                future_wait[what] = task
                what.add_done_callback(future_done)
            else:
                raise RuntimeError('ARG!')
        except StopIteration:
            print("task done")

#######################
## END OF SCRIPT
#######################
if __name__ == '__main__':
    sys.exit(run())
