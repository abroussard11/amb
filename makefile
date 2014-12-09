# The amb directory makefile

# This disables built-in rules for all file extensions
.SUFFIXES:

# Phony targets are always considered out of date
.PHONY: all clean mkdir_build_subdirs

AMB_SRC_DIR := src
AMB_BUILD_DIR := build
AMB_LIB_DIR := $(AMB_BUILD_DIR)/lib
AMB_OBJ_DIR := $(AMB_BUILD_DIR)/obj
AMB_DEP_DIR := $(AMB_BUILD_DIR)/dep
AMB_BUILD_SUBDIRS =
VPATH = $(AMB_BUILD_DIR):$(AMB_SRC_DIR)

INCLUDE_DIRS = $(AMB_SRC_DIR)
LINK_LIB_DIRS += $(AMB_LIB_DIR)
AMB_LINKER_FLAGS = $(addprefix -L, $(LINK_LIB_DIRS)) $(addprefix -l, $(LINK_LIBS)) 

# CXXFLAGS is used is used whenever COMPILE.cpp is expanded. For our purposes,
# this happens whenever a builtin recipe is called for updating a .o file from a .cpp file 
CXXFLAGS = -std=c++11 -Og -g -Wall -fPIC -I$(INCLUDE_DIRS)

# Program executables to be built
EXECUTABLES = AmbGames

#################
## TARGET LIST ##
#################

# Default target is all
all: mkdir_build_subdirs $(EXECUTABLES)

# Create the build output directories
mkdir_build_subdirs:
	mkdir -p $(AMB_BUILD_DIR); \
	mkdir -p $(AMB_LIB_DIR) $(AMB_OBJ_DIR) $(AMB_DEP_DIR) ; \
	mkdir -p $(addprefix $(AMB_OBJ_DIR)/, $(AMB_BUILD_SUBDIRS))

# clean-up build output files (defined in lib.makefile and module.makefile)
clean:
	rm -rf build

# Object files
$(AMB_OBJ_DIR)/%.o: $(AMB_SRC_DIR)/%.cpp
	$(COMPILE.cpp) $^ -o $@

include $(AMB_SRC_DIR)/makefile

# Dependancy files
$(AMB_DEP_DIR)/%.d: $(AMB_SRC_DIR)/%.cpp
	set -e; rm -f $@ ;\
	mkdir -p $(@D); \
	g++ -MM $(CXXFLAGS) $< > $@.$$$$ ; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

makefile:;
