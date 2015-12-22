'''
Created on Oct 12, 2015

@author: Aaron
'''

# from tkinter.constants import N,E,S,W
from tkinter.ttk import Frame, Label

def load(appFrame):
    rightFrame = Frame(appFrame)
    rightFrame.grid(row=1, column=2)
    label = Label(master=rightFrame, text="Project:")
    label.grid(row=0, column=0)