##################################
## Top level Makfile for 'amb'
##################################

ifndef PROJECT_PATH
   $(error "You need to source setup before building")
endif

BUILD_SHELL ?= /bin/sh
SHELL := $(BUILD_SHELL)
COLORFUL_MAKE ?= false
MAKE := make
MFILE := makefile

LANGUAGE_DIRS := \
   cxx \
   dot \
   python

include xanrMake/projVars.makefile

LANG_DIRS := \
   cxx \
   dot \
   python

include $(addsuffix /$(MFILE), $(LANG_DIRS))


