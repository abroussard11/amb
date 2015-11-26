#!/usr/bin/env python

## System imports
from datetime import datetime
from subprocess import *
import sys

## Local imports
import config
from util import socketcontext

#host = ''
#port = 50000
#backlog = 5
#size = 1024


#######################
## Main Routine
#######################
def MasterNodeManager():
    host = config.HOST
    port = config.PORT
    size = config.SIZE
    backlog = config.BACKLOG

    with socketcontext(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((host, port))
        s.listen(backlog)
        cwd = ""
        cmd = ""
        while 1:
            client, address = s.accept()
            data = client.recv(size)
            if data:
                cwd, cmd = data.split(', ', 1)
                timestamp = str(datetime.now())
                sys.stdout.write(timestamp + ' Received data:\n')
                sys.stdout.write('   cwd:' + cwd + '\n')
                sys.stdout.write('   cmd:' + cmd + '\n')
                p1 = Popen(cmd.split(' '), stdout = PIPE, stderr = PIPE, cwd = cwd)
                stdout, stderr = p1.communicate()
                client.send(stdout + '\n::END_STDOUT::BEGIN_STDERR::\n' + stderr)
            client.close()

#######################
## END OF SCRIPT
#######################
if __name__ == '__main__':
   sys.exit(MasterNodeManager())

