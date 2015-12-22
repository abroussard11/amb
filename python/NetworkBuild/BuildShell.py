#!/usr/bin/env python3

## System imports
import os
import socket
import sys

## Local imports
import config
import util
from util import socketcontext

#######################
## Function definitions
#######################
def get_cmd_from_args(args):
    return ' '.join(args[2:])
    # TODO: write test for cases
    #          1. args = ['BuildShell.py', '-c', '"cat config.py"']
    #          2. args = ['BuildShell.py', '-c', 'cat', 'config.y']
    #        Both should return the same thing

def log_debug(output, errors, cout=sys.stdout, cerr=sys.stderr):
    if not config.DEBUG: return

    if output:
        cout.write('stdout:\n')
        cout.write(output)
    else:
        cout.write('No stdout recieved\n')
    if errors:
        cout.write('stderr:\n')
        cout.write(errors)
    else:
        cout.write('No stderr recieved\n')

#######################
## Main Routine
#######################
def echo_client(msg, cout=sys.stdout, cerr=sys.stderr):
    host = config.HOST
    port = config.PORT
    size = config.SIZE

    if len(msg) >= size:
        cerr.write('ERROR: The message is too long\n')
        sys.exit(1)

    data = bytearray(0)
    stdout = bytearray(0)
    stderr = bytearray(0)
    with socketcontext(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host,port))
        s.send(msg)
        data = s.recv(size)
        stdout, stderr = data.split('\n::END_STDOUT::BEGIN_STDERR::\n')
        log_debug(stdout, stderr)

    buildShell_return_code = (stderr != '')

    if cout:
        cout.write('pyBuildShell: ERROR: stdout =\n' + stdout)
    if cerr:
        cerr.write('pyBuildShell: ERROR: stderr =\n' + stderr)

    return buildShell_return_code

#######################
## END OF SCRIPT
#######################
if __name__ == '__main__':
    cwd = os.getcwd()
    build_cmd = get_cmd_from_args(sys.argv)
    full_cmd = cwd + ', ' + build_cmd
    cout = sys.stdout
    cout.write('\nBuildShell:\n   cwd = ' + cwd + '\n   cmd = ' + build_cmd + '\n')
    cout.write('  len(sys.argv) = ' + str(len(sys.argv)) + '\n')
    for i, arg in enumerate(sys.argv):
        cout.write('    sys.argv[' + str(i) + '] = ' + arg + '\n')
    sys.exit(echo_client(full_cmd))
