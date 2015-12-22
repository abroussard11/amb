##################################################
## Build commands for the pythonic implementation
## of the DsbProject
##################################################

## Shell commands
MKDIR := mkdir
RM := del /F
RMDIR := rmdir /S /Q
WC :=

SRC_DIR := dsb
TEST_DIR := dsb/test
BUILD_DIR := dist

APP := dsb
$(APP).BIN := $(BUILD_DIR)\$(APP).exe
$(APP).SRC_DIR := dsb
$(APP).MAIN := $($(APP).SRC_DIR)/$(APP).py

UNITTEST := dsbUnitTest
$(UNITTEST).BIN := $(BUILD_DIR)\$(UNITTEST).exe
$(UNITTEST).SRC_DIR := dsb/test
$(UNITTEST).MAIN := $($(UNITTEST).SRC_DIR)/$(UNITTEST).py

#UNITTEST := dsbUnitTest
#UNITTEST.MAIN := $(UNITTEST).py
#UNITTEST.SRC_DIR := dsb/test

all: $($(APP).BIN) $($(UNITTEST).BIN)

clean: FORCE
	$(RMDIR) $(BUILD_DIR)

$($(APP).BIN): FORCE
	build_exe $($(APP).MAIN)

$($(UNITTEST).BIN): FORCE
	build_exe $($(UNITTEST).MAIN)

### Common file names used
#PY_MAIN := __main__.py
#EXE_MAIN := __main__.exe

### Source directories
#MAIN_DIR := dsb
#TEST_DIR := $(MAIN_DIR)/test

### Build directories
#MAIN_DIST := dist
#TEST_DIST := $(MAIN_DIST)/test

### Build targets
#MAIN_TGT := $(MAIN_DIR)/$(PY_MAIN)
#TEST_TGT := $(TEST_DIR)/$(PY_MAIN)

#all: $(MAIN_TGT)
#tests: $(TEST_TGT)
#clean: FORCE
#	$(RMDIR) $(MAIN_DIST)

## build the app
#$(MAIN_TGT): FORCE
#	py -3.4 dsbBuildSetup.py py2exe
#	build_exe -d $(MAIN_DIST) $@

### build the tests
#$(TEST_TGT): FORCE
#	build_exe -d $(TEST_DIST) $@

### run the app
#app: FORCE
#	$(MAIN_DIST)/$(EXE_MAIN)

### run the unit tests
#test-results: FORCE
#	$(TEST_DIST)/$(EXE_MAIN)

FORCE: ;