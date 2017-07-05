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

LANG_DIRS := \
   cxx \
   dot \
   python

print-%:
	$(MAKE) impl_$@

all:: $(addsuffix .all, $(LANG_DIRS))
clean:: $(addsuffix .clean, $(LANG_DIRS))
#all clean:
#	$(MAKE) $(addsuffix .$@, $(LANG_DIRS))
#
#%/all %/clean:
#	$(MAKE) $(subst /,., $@)

scan:
	scan-build --use-c++=/usr/bin/clang++ -V $(MAKE) cxx/all

compdb:
	bear $(MAKE) all

tags:
	ctags -R

# For debugging...
#  $ make print-SRCS
#  SRCS=main.cpp util.cpp
impl_print-%: ; @echo $*=$($*)

#'make' is invoked twice;
# First by the user 'make all', where xanrMake cannot
# be automatically inserted into .INCLUDEDIRS
# and
# Second, by make executing the recipe for the 'all' target
# where we inject (into 'MAKEFLAGS') all of the command line
# flags that we don't want to type every time
#$(info .INCLUDE_DIRS = $(.INCLUDE_DIRS))
#ifneq ("$(findstring xanrMake, $(.INCLUDE_DIRS))", "")
   include projVars.makefile
   include $(addsuffix /$(MFILE), $(LANG_DIRS))
#endif

