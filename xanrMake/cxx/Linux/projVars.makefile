###########################################
## Project Variables for Linux
###########################################


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
PCH_FLAGS :=#
ifeq "$(RUN_SANITIZERS)" "true"
   SAN_FLAGS ?=-fsanitize=address
endif

SYS_DLL_LIB := dl

## Define other compiler variables
AR := ar -rc
GCC := g++-4.9
CLANG := clang++
CXX ?= $(CLANG)
CXXFLAGS := $(STD_CXX_FLAGS) \
            -fPIC \
            $(OPTIMIZE_FLAGS) \
            $(DEBUG_FLAGS) \
            $(WARN_FLAGS) \
            $(SAN_FLAGS) \
            $(INC_DIRS)

COMPILE.cpp := $(CXX) $(PCH_FLAGS) $(CXXFLAGS)

## Targets

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

