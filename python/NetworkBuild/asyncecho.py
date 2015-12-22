#!/usr/bin/env python3

## System imports
import asyncio
from   concurrent.futures import ProcessPoolExecutor, Future
from   socket import *

## Local imports
import config
from   fib import fib
from   util import socketcontext

def patch_future(cls):
    def __iter__(self):
        if not self.done():
            yield self
        return self.result()
    cls.__iter__ = __iter__

patch_future(Future)


pool = ProcessPoolExecutor(4)
loop = asyncio.get_event_loop()

@asyncio.coroutine
def echo_client(sock):
    while True:
        data = yield from loop.sock_recv(sock, 8192)
        if not data.rstrip():
            break
        n = int(data.rstrip())
        val = yield from pool.submit(fib, n)
        yield from loop.sock_sendall(sock, bytes(str(val) + '\n', 'ascii'))
    sock.close()

def echo_server(address):
    sock = socket(AF_INET, SOCK_STREAM)
    sock.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
    sock.bind(address)
    sock.listen(5)
    sock.setblocking(False)
    while True:
       client_sock, addr = yield from loop.sock_accept(sock)
       asyncio.async(echo_client(client_sock))

if __name__ == '__main__':
    asyncio.async(echo_server(('', 25000)))
    loop.run_forever()

