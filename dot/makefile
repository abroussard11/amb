$(info Reading amb/dot/makefile)

all::
	@echo dot all

include xanrMake/dot/projVars.makefile

SRC_DIR := dot
REPO := AMB_dot
BUILD_DIR := $(COMP_TYPE)
PNG_DIR := $(BUILD_DIR)/png
PDF_DIR := $(BUILD_DIR)/pdf

SUBDIRS := \
   NetworkBuild

$(info SRC_DIR = $(SRC_DIR))

include $(patsubst %, $(SRC_DIR)/%/$(MFILE), $(SUBDIRS))

