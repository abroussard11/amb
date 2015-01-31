##############################
## The amb directory makefile
##############################

# This disables built-in rules for (almost) all file extensions
.SUFFIXES:
.SUFFIXES: .o .so .d

# Phony targets are always considered out of date
.PHONY: all clean cleandeps mkdir_build_subdirs

# Project locations definitions
SRC_DIR := src
BUILD_DIR := build
LIB_DIR := $(BUILD_DIR)/lib
OBJ_DIR := $(BUILD_DIR)/obj
DEP_DIR := $(BUILD_DIR)/dep
VPATH = $(BUILD_DIR):$(SRC_DIR)

# Graphics toolkit library names
SFML_LIBS := sfml-graphics \
             sfml-window \
             sfml-system \
             sfml-audio \
             sfml-network

INCLUDE_DIRS := -I$(SRC_DIR)
LINK_LIBS := $(SFML_LIBS)
LINK_LIB_DIRS := $(LIB_DIR)
LINKER_FLAGS := $(addprefix -L, $(LINK_LIB_DIRS)) $(addprefix -l, $(LINK_LIBS))

# CXXFLAGS is used is used whenever COMPILE.cpp is expanded. For our purposes,
# this happens whenever a builtin recipe is called for updating a .o file from a .cpp file 
CXXFLAGS := -std=c++11 -ggdb -Wall -fPIC $(INCLUDE_DIRS)

# These targets are defined in Cmds.makefile
# They are listed here so that you can use tab completion in tcsh
all::
clean::
cleandeps::
clobber::

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(COMPILE.cpp) $^ -o $@

makefile:;

include $(SRC_DIR)/makefile
