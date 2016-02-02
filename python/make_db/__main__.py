'''
 make_db/__main__py
'''

import sys
from . import parse

print('running __main__.py')
filename = sys.argv[1]
sys.exit(parse.format_db(filename))

