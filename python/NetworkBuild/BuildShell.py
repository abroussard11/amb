#!/usr/bin/env python

## System imports
import socket
import sys

## Local imports
import config
from util import socketcontext

#######################
## Main Routine
#######################
def echo_client(msg):
    host = config.HOST
    port = config.PORT
    size = config.SIZE

    if len(msg) >= size:
        sys.stderr.write('ERROR: The message is too long\n')
        sys.exit(1)

    data = ""
    stdout = ""
    stderr = ""
    with socketcontext(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host,port))
        s.send(msg)
        data = s.recv(size)
        stdout, stderr = data.split('\n::END_STDOUT::BEGIN_STDERR::\n')
        sys.stdout.write('stdout:' + stdout + ';end_stdout\n')
        sys.stdout.write('stderr:' + stderr + ';end_stderr\n')

    buildShell_return_code = (stderr != '')
    if buildShell_return_code:
        sys.stdout.write('pyBuildShell: ERROR: stdout =\n' + stdout)
        sys.stdout.write('pyBuildShell: ERROR: stderr =\n' + stderr)
        sys.stdout.write('pyBuildShell: END OF ERROR MESSAGE\n')
    
    return buildShell_return_code

#######################
## END OF SCRIPT

if __name__ == '__main__':
    cwd = os.getcwd()
    build_cmd = ''.join(sys.argv[2:])
    full_cmd = cwd + ', ' + build_cmd
    sys.stdout.write('\npyBuildShell:\n   cwd = ' + cwd + '\n   cmd = ' + build_cmd + '\n')
    sys.exit(echo_client(full_cmd))
