'''
Created on Oct 12, 2015

@author: Aaron
'''

from tkinter.constants import N,E,S,W
from tkinter.ttk import Frame, Label, Entry

def load(appFrame):
    topFrame = Frame(appFrame)
    topFrame.grid(row=0, column=0, sticky=(N,E,S,W))
    ## Search Label and Entry box
    label = Label(master=topFrame, text="Search:")
    label.grid(row=0, column=0)
    entry = Entry(topFrame)
    entry.grid(row=0, column=1)