#!/usr/bin/env python3

# perf2.py
# requests/sec of fast requests

from socket import *
import time
from concurrent.futures import ThreadPoolExecutor as Pool

n = 0

from threading import Thread
def monitor():
    global n
    while True:
        time.sleep(1)
        print(n, 'reqs/sec')
        n = 0
Thread(target=monitor).start()

def spawn_connection():
    global n
    sock = socket(AF_INET, SOCK_STREAM)
    sock.connect(('localhost', 25000))
    sock.send(b'1')
    resp =sock.recv(100)
    sock.close()
    n += 1

pool = Pool(10)

while True:
    pool.submit(spawn_connection)
