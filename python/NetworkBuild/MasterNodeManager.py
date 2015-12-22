#!/usr/bin/env python3

## System imports
import asyncio
from   datetime import datetime
import os
from   socket import *
from   subprocess import *
import sys

## Local imports
import config
from   util import AsyncSocket, AsyncSocketcontext

#######################
## Global varibles
#######################
tasks = deque()
recv_wait = { } # Mapping sockets -> tasks (generators)
send_wait = { }


#######################
## Function definitions
#######################
def request_handler(client):
    data = yield from client.recv(size)
    if data:
        tup = data.split(', ', 1)
        cwd = os.path.abspath(tup[0])
        cmd = tup[1].rstrip()
        timestamp = str(datetime.now())
        sys.stdout.write(timestamp + ' Received data:\n')
        sys.stdout.write('  data:' + data + '\n')
        sys.stdout.write('   cwd:' + cwd + '\n')
        sys.stdout.write('   cmd:' + cmd + '\n')
        p1 = Popen(cmd.split(' '), stdout = PIPE, stderr = PIPE, cwd = cwd)
        stdout, stderr = p1.communicate()
        print('   Got: stdout =', stdout)
        print('   Got: stderr =', stderr)
        yield from client.send(stdout
            + '\n::END_STDOUT::BEGIN_STDERR::\n'
            + stderr)

def MasterNodeManager():
    host = config.HOST
    port = config.PORT
    size = config.SIZE
    backlog = config.BACKLOG

    with AsyncSocketcontext(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
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
            can_recv, can_send, [] = select(recv_wait, send_wait, [])
            for s in can_recv:
                tasks.append(recv_wait.pop(s))
            for s in can_recv:
                tasks.append(recv_wait.pop(s))
        task = tasks.popleft()
        try:
            why, what = next(task) # Run to the yeild
            if why == 'recv':
                # Must go wait somewhere
                recv_wait[what] = task
            elif why == 'send':
                send_wait[what] = task
            else:
                raise RuntimeError('ARG!')
        except StopIteration:
            print("task done")

#######################
## END OF SCRIPT
#######################
if __name__ == '__main__':
    sys.exit(run())
