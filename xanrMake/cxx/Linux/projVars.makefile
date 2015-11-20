###########################################
## Project Variables for Linux
###########################################

$(info Reading amb/xanrMake/cxx/Linux/projVars.makefile)

# Shell commands
MKDIR := mkdir -p
RM := rm -f
WC := wc -l --files0-from=
ECHO :=echo -e

## Define Library paths
INCLUDE_DIRS := \
   $(SRC_DIR)

INC_DIRS :=$(patsubst %, -I%, $(INCLUDE_DIRS))

## Define compiler flags
STD_CXX_FLAGS :=-std=c++14
OPTIMIZE_FLAGS :=-O0
DEBUG_FLAGS :=-g
WARN_FLAGS :=-Wall
MAKE_DEPS_FLAGS :=-MMD

SYS_DLL_LIB := dl

## Define other compiler variables
AR := ar -rc
GCC := g++-4.9
CLANG := clang++
CXX ?= $(CLANG)
CXXFLAGS := $(STD_CXX_FLAGS) -fPIC $(OPTIMIZE_FLAGS) $(DEBUG_FLAGS) $(WARN_FLAGS) $(INC_DIRS)
PCH_FLAGS :=#
COMPILE.cpp := $(CXX) $(PCH_FLAGS) $(CXXFLAGS)

## Colors!!
## set the COLORFUL_MAKE variable in your environment
ifneq "$(COLORFUL_MAKE)" "true"
       black := \033[0;30m
         red := \033[0;31m
       green := \033[0;32m
      orange := \033[0;33m
        blue := \033[0;34m
      purple := \033[0;35m
        cyan := \033[0;36m
  light_gray := \033[0;37m
   dark_gray := \033[1;30m
   light_red := \033[1;31m
 light_green := \033[1;32m
      yellow := \033[1;33m
  light_blue := \033[1;34m
light_purple := \033[1;35m
  light_cyan := \033[1;36m
       white := \033[1;37m
light_blue_bg := \033[1;44m
default_color:= \033[0m
endif

all::
	@$(ECHO) "\n$(light_blue_bg)*** Building all source ***$(default_color)\n"

#clean:: wc_clean

wc:: | $(BUILD_DIR)
	@touch $(WC_FILE)_h
	@find -name "*.h" -print0 > $(WC_FILE)_h
	@$(ECHO) -n "      .h: "; $(WC)$(WC_FILE)_h | grep total
	@find -name "*.cpp" -print0 > $(WC_FILE)_cpp
	@$(ECHO) -n "    .cpp: "; $(WC)$(WC_FILE)_cpp | grep total
	@find -name "*makefile" -print0 > $(WC_FILE)_m
	@$(ECHO) -n "makefile: "; $(WC)$(WC_FILE)_m | grep total

WC_SRCS := # To be added to by each subdirectory
wc-detailed:: | $(BUILD_DIR)
	$(RM) $(WC_FILE)
	@touch $(WC_FILE)
	@for file in $(WC_SRCS); do \
	   $(ECHO) -ne "$$file\0" >> $(WC_FILE); \
	done
	@$(WC)$(WC_FILE)

wc_clean:
	$(RM) $(WC_FILE) $(WC_FILE)_h $(WC_FILE)_cpp $(WC_FILE)_m

$(BUILD_DIR):
	mkdir -p $@

$(BIN_DIR):
	$(MKDIR) $@

$(LIB_DIR):
	$(MKDIR) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(COMPILE.cpp) -MMD -c $< -o $@
