####################################################################
## Makefile for paint/exe
####################################################################

include cxx/initVars.makefile

DIR := paint/exe
EXE := paint

FILES := \
   main

LINK_STATIC_LIBS := \
   amb-amb-xml \
   amb-Util \
   amb-infra

LINK_DYNAMIC_LIBS := \
   amb-paint

SYS_LIBS := \
   sfml-graphics \
   sfml-window \
   sfml-system

ifeq "$(MAKE_TYPE)" "Windows"
   SYS_LIBS += sfml-main-d
endif

include cxx/exe.makefile
