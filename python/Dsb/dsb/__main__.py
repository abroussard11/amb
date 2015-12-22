'''
Created on Oct 10, 2015

@author: Aaron
'''
from tkinter import *
from tkinter.ttk import *
from dsb.panels import *

def setupMenus(parent):    
    ## Top menu bar
    menubar = Menu(parent)
    ## File menu
    menu_file = Menu(menubar)
    menu_file.add_command(label="New")
    menu_file.add_command(label="Open")
    menu_file.add_command(label="Close")
    ## Edit menu
    menu_edit= Menu(menubar)
    menu_edit.add_command(label="Undo")
    menu_edit.add_command(label="Redo")
    menubar.add_cascade(menu=menu_file, label="File")
    menubar.add_cascade(menu=menu_edit, label="Edit")
    parent['menu'] = menubar
      
def makeApp(toplevel):
    appFrame = Frame(master=toplevel, padding=(3,3,12,12))
    appFrame.grid(column=0, row=0, sticky=(N,W,E,S))
    appFrame.rowconfigure(0, weight=1)
    appFrame.rowconfigure(1, weight=2)
    appFrame.columnconfigure(0, weight=1)
    appFrame.columnconfigure(1, weight=2)
    appFrame.columnconfigure(2, weight=1)
    TopFrame.load(appFrame)
    LeftFrame.load(appFrame)
    CenterFrame.load(appFrame)
    RightFrame.load(appFrame)


def main():
    root = Tk()
    root.title("DSB")
    root.option_add('*tearOff', FALSE)
    
    setupMenus(root)
    makeApp(root)
     
    root.mainloop()

if __name__ == '__main__':
    sys.exit(main())
