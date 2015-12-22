##################################
## Top level makfile for 'amb'
##################################

ifndef PROJECT_PATH
   $(error "You need to source setup before building")
endif

SHELL := /bin/sh
ECHO := echo -e
MAKE := make

export MAKEFLAGS := \
   --no-builtin-rules \
   --no-print-directory \
   --warn-undefined-variables \
   --output-sync \
   --include-dir=xanrMake

%all %clean:
	@$(MAKE) -f Makefile $@

