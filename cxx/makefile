$(info Reading amb/cxx/makefile)

cxx.all::
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

cxx.all:: .syntastic_cppcheck_config .syntastic_clang_check_config

.syntastic_cppcheck_config .syntastic_clang_check_config: SRC_DIR:=$(SRC_DIR)
.syntastic_cppcheck_config .syntastic_clang_check_config:
	@$(ECHO) "-I $(PROJECT_PATH)/$(SRC_DIR)" > $@

SUBDIRS := \
   amb \
   BitOps \
   dsb \
   include \
   infra \
   netbld \
   paint \
   tests \
   Util \
   x2048

include $(patsubst %, $(SRC_DIR)/%/$(MFILE), $(SUBDIRS))
