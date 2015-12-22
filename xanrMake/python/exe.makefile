#########################################################
## The generic makefile for building png images from dot
#########################################################
$(info Reading amb/xanrMake/python/exe.makefile)

$(DIR)_SRCS := $(patsubst %, $(SRC_DIR)/$(DIR)/%.py, $(FILES))
$(DIR)_EXES := $(patsubst %, $(BIN_DIR)/%.exe, $(FILES))

all:: $($(DIR)_EXES)
python.all:: $($(DIR)_EXES)


clean:: $(DIR).clean
python.clean:: $(DIR).clean

$(DIR).clean: DIR:=$(DIR)
$(DIR).clean:
	$(RM) $($(DIR)_EXES)

$($(DIR)_EXES): | $(BIN_DIR)

$(BIN_DIR)/%.exe: $(SRC_DIR)/$(DIR)/%.py
	@$(ECHO) "$(light_blue)Making $@ $(default_color)"
	nuitka $(NUITKA_FLAGS) --output-dir=$(BIN_DIR) $<

ifneq ($(strip $(SUBDIRS)), "")
   include $(patsubst %, $(SRC_DIR)/$(DIR)/%/$(MFILE), $(SUBDIRS))
endif
