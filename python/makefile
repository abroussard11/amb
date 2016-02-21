include xanrMake/python/projVars.makefile

SRC_DIR := python
REPO := AMB_python
BUILD_DIR := $(COMP_TYPE)
BIN_DIR := $(BUILD_DIR)/bin

SUBDIRS := \
   NetworkBuild

include python/vars.makefile

include $(patsubst %, $(SRC_DIR)/%/$(MFILE), $(SUBDIRS))
