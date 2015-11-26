$(info Reading amb/cxx/makefile)

all::
	@echo cxx all


# Project locations definitions
REPO := AMB_cxx
SRC_DIR := cxx
BUILD_DIR := $(COMP_TYPE)
BIN_DIR := $(BUILD_DIR)/bin
LIB_DIR := $(BUILD_DIR)/lib
OBJ_DIR := $(BUILD_DIR)/objs
WC_FILE := $(BUILD_DIR)/wc_file

include cxx/projVars.makefile

SUBDIRS := \
   amb \
   BuildShell \
   dsb \
   include \
   infra \
   paint \
   tests \
   Util \

include $(patsubst %, $(SRC_DIR)/%/$(MFILE), $(SUBDIRS))
