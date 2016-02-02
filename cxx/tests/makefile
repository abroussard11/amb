####################################################################
## Makefile for UnitTest
####################################################################

include cxx/initVars.makefile

DIR := tests
EXE := ambUnitTest

SUBDIRS := \
   BitOps

TESTS := \
   Amb \
   Dsb \
   Infra \
   Master \
   Paint \
   Util

FILES := \
   $(addsuffix UnitTest, $(TESTS)) \
   main

DSB_GUI_LIBS := \
   amb-dsb-gui-app \
   amb-dsb-gui-center \
   amb-dsb-gui-left \
   amb-dsb-gui-top \
   amb-dsb-gui-right

LINK_STATIC_LIBS := \
   amb-tests-BitOps \
   $(DSB_GUI_LIBS) \
   amb-dsb-cli-app \
   amb-dsb-generic \
   amb-amb \
   amb-amb-xml \
   amb-infra \
   amb-paint-generic \
   amb-Util

LINK_SFML_LIBS := \
   sfml-graphics \
   sfml-system \
   sfml-window

include cxx/exe.makefile
