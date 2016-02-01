####################################################################
## Makefile for amb
####################################################################

include cxx/initVars.makefile

DIR := amb

SUBDIRS := \
   xml

FILES := \
   CliAppDriver \
   Color \
   Font \
   GuiAppDriver \
   GuiComponent \
   ProgVars \
   Text \
   Xml

LINK_STATIC_LIBS := \
   amb-amb-xml

LINK_SFML_LIBS := \
   sfml-graphics \
   sfml-system \
   sfml-window

#include cxx/sharedLib.makefile
include cxx/lib.makefile
