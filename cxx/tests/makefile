####################################################################
## Makefile for UnitTest
####################################################################

include cxx/initVars.makefile

DIR := tests
EXE := ambUnitTest

SUBDIRS := \
   amb \
   BitOps \
   dsb \
   infra \
   paint \
   std \
   util

FILES := \
   MasterUnitTest \
   main

LINK_STATIC_LIBS := \
   amb-Util

LINK_DYNAMIC_LIBS := \
   amb-tests-amb \
   amb-tests-BitOps \
   amb-tests-dsb \
   amb-tests-infra \
   amb-tests-paint \
   amb-tests-std \
   amb-tests-util

LINK_SFML_LIBS := \
   sfml-graphics \
   sfml-system \
   sfml-window

include cxx/exe.makefile
