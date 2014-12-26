# The amb directory makefile

# This disables built-in rules for all file extensions
.SUFFIXES:
.SUFFIXES: .o .so .d

# Phony targets are always considered out of date
.PHONY: all clean mkdir_build_subdirs

AMB_SRC_DIR := src
AMB_BUILD_DIR := build
AMB_LIB_DIR := $(AMB_BUILD_DIR)/lib
AMB_OBJ_DIR := $(AMB_BUILD_DIR)/obj
AMB_DEP_DIR := $(AMB_BUILD_DIR)/dep
VPATH = $(AMB_BUILD_DIR):$(AMB_SRC_DIR)

# Graphics toolkit library names
SFML_LIBS := sfml-graphics \
             sfml-window \
             sfml-system \
             sfml-audio \
             sfml-network


INCLUDE_DIRS = $(AMB_SRC_DIR)
LINK_LIBS = $(SFML_LIBS)
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
all: $(EXECUTABLES)

# Create the build output directories
#mkdir_build_subdirs:
#	mkdir -p $(AMB_BUILD_DIR); \
#	mkdir -p $(AMB_LIB_DIR) $(AMB_OBJ_DIR) $(AMB_DEP_DIR)

# clean-up build output files (defined in lib.makefile and module.makefile)
clean:
	rm -rf build

# Object files
$(AMB_OBJ_DIR)/%.o: $(AMB_SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(COMPILE.cpp) $^ -o $@

include $(AMB_SRC_DIR)/makefile

# Dependancy files
$(AMB_DEP_DIR)/%.d: $(AMB_SRC_DIR)/%.cpp
	mkdir -p $(@D)
	echo -n $@" " > $@
	g++ -MM $(CXXFLAGS) $(patsubst $(AMB_DEP_DIR)%.d,$(AMB_SRC_DIR)%.cpp,$@) >> $@
	

makefile:;
