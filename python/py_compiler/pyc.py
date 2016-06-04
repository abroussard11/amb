#!/usr/bin/env python2

import py_compile
import sys

def pyc(src, destfile):
  py_compile.compile(src, cfile=destfile, doraise=True)
  return 0

if __name__ == '__main__':
  if len(sys.argv) > 1:
    src = sys.argv[1]
    dfile = src + 'c'
    if sys.argv[2] and sys.argv[2] == '-o':
      dfile = sys.argv[3]
    sys.exit(pyc(src, dfile))
  else:
    print "Usage:"
    sys.exit(1)
