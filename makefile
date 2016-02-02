##################################
## Top level makfile for 'amb'
##################################

ifndef PROJECT_PATH
   $(error "You need to source setup before building")
endif

BUILD_SHELL ?= /bin/sh
export SHELL := $(BUILD_SHELL)
export MAKE := make
export MFILE := makefile

export MAKEFLAGS := \
   --no-builtin-rules \
   --no-print-directory \
   --warn-undefined-variables \
   --output-sync \
   --include-dir=xanrMake

LANG_DIRS := \
   cxx \
   dot \
   python

all clean:
	@$(MAKE) $(addsuffix .$@, $(LANG_DIRS))

%/all %/clean:
	@$(MAKE) $(subst /,., $@)

compilation_database:
	@bear $(MAKE) all

scan:
	scan-build --use-c++=/usr/bin/clang++ -V $(MAKE) cxx/all

#'make' is invoked twice;
# First by the user 'make all', where xanrMake cannot
# be automatically inserted into .INCLUDEDIRS
# and
# Second, by make executing the recipe for the 'all' target
# where we inject (into 'MAKEFLAGS') all of the command line
# flags that we don't want to type every time
ifneq ("$(findstring xanrMake,$(.INCLUDE_DIRS))", "")
   include xanrMake/projVars.makefile
   include $(addsuffix /$(MFILE), $(LANG_DIRS))
endif

