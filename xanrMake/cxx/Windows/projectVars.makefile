###########################################
## Project Variables for Windows
###########################################

# Shell commands
MKDIR := mkdir
RM := del /F
RMDIR := rmdir /S /Q
WC :=
ECHO :=echo

VS_TOOLSET ?= v100
VCX_DIR :=vcxproj.$(VS_TOOLSET)

## Define Library paths
INCLUDE_DIRS := \
   $(SRC_DIR)

INCLUDE_DIRS += $(SFML_DIR)/SFML/include

SYS_DLL_LIB :=

PROJ_SLN := $(VCX_DIR)/$(REPO).sln

cxx.all:: $(PROJ_SLN)
	msbuild /m $(PROJ_SLN)

sln: $(PROJ_SLN)
$(PROJ_SLN):
	makeSln.py --repo=$(REPO) --tool_set=$(VS_TOOLSET)

cxx.clean:
	$(RMDIR) $(VCX_DIR)
	$(RMDIR) $(BUILD_DIR)

## These are helper variables so that we can insert commas into
## our lists - used in vars.makefile
comma:= ,
colon:= :
empty:=
space:= $(empty) $(empty)
#foo:= a b c
#bar:= $(subst $(space),$(comma),$(foo))
#bar now equals "a,b,c"
