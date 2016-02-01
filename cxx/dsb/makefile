####################################################################
## Makefile for dsb
####################################################################

include cxx/initVars.makefile

DIR := dsb
EXE := dsb

SUBDIRS := \
   cfg \
   cli \
   generic \
   gui \
   interface

FILES := \
   main

LINK_STATIC_LIBS := \
   amb-Util

LINK_DYNAMIC_LIBS := \
   amb-dsb-gui \
   amb-dsb-cli

LINK_SFML_LIBS := \
   sfml-graphics \
   sfml-window \
   sfml-system

ifeq "$(MAKE_TYPE)" "Windows"
   LINK_SFML_LIBS += sfml-main
endif

include cxx/exe.makefile
