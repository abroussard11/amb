'''
Created on Oct 12, 2015

@author: Aaron
'''

from tkinter.constants import N,E,S,W
from tkinter.ttk import Frame, Label, Entry, Treeview

def load(appFrame):
    leftFrame = Frame(appFrame)
    leftFrame.grid(row=1, column=0, sticky=W)
    ctree = Treeview(leftFrame)
    ctree['columns'] = ('size', 'modified', 'owner')
    for column in ctree['columns']:
        ctree.column(column, width=100, anchor='center')
        ctree.heading(column, text=column.capitalize())
        
    ctree.insert('', 'end', 'widgets', text='Widget Tour', values=('1a', '1b'))
    ctree.insert('', 0, 'gallery', text='Applications', values=('1a', '1b'))
    id = ctree.insert('', 'end', text='Tutorial', values=('1a', '1b'))
    ctree.insert('widgets', 'end', text='Canvas', values=('1a', '1b'))
    ctree.insert(id, 'end', text='Tree', values=('1a', '1b'))
    ctree.grid(row = 0, column = 0)