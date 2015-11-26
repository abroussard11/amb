#!/usr/bin/env python

from contextlib import contextmanager
import socket

@contextmanager
def socketcontext(*args, **kw):
    s = socket.socket(*args, **kw)
    try:
        yield s
    finally:
        s.close()

