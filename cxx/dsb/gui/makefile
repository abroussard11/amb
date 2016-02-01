####################################################################
## Makefile for dsb/gui
####################################################################

include cxx/initVars.makefile

DIR := dsb/gui

SUBDIRS := \
   app \
   center \
   left \
   right \
   top

FILES := \
   entry_points

LINK_STATIC_LIBS := \
   amb-dsb-gui-app \
   amb-dsb-gui-center \
   amb-dsb-gui-left \
   amb-dsb-gui-right \
   amb-dsb-gui-top \
   amb-dsb-generic \
   amb-amb \
   amb-amb-xml \
   amb-infra \
   amb-Util

SYS_LIBS := \
   sfml-graphics \
   sfml-window \
   sfml-system

include cxx/sharedLib.makefile
