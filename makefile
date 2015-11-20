##################################
## Top level makfile for 'amb'
##################################

ifndef PROJECT_PATH
   $(error "You need to source setup before building")
endif

export SHELL ?= /bin/sh
export COLORFUL_MAKE ?= false
export MAKE := make

export MAKEFLAGS := --no-builtin-rules --no-print-directory \
                 --warn-undefined-variables --output-sync \
                 --include-dir=$(PROJECT_PATH)/xanrMake

LANGUAGE_DIRS := \
   cxx \
   dot \
   python

include xanrMake/projVars.makefile


all:
	@$(MAKE) -f cxx/makefile $@
	@$(MAKE) -f dot/makefile $@
	@$(MAKE) -f python/makefile $@
	@echo all target

#include $(addsuffix /$(MFILE), $(LANGUAGE_DIRS))
