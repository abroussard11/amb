#########################################################
## The generic makefile for building png images from dot
#########################################################
$(info Reading amb/xanrMake/python/exe.makefile)

$(DIR)_SRCS := $(patsubst %, $(SRC_DIR)/$(DIR)/%.py, $(FILES))
$(DIR)_PYCS :- $(patsubst %, %(LIB_DIR)/$(DIR)/%.pyc, $(FILES))
$(DIR)_EXES := $(patsubst %, $(BIN_DIR)/%.exe, $(FILES))
$(DIR)_PYZS := $(patsubst %, $(BIN_DIR)/pyz/%, $(PYZS))

python.all:: $($(DIR)_EXES)
python.zyp:: $($(DIR)_PYZS)#TODO test this out
python.clean:: $(DIR).clean

$(DIR).clean: DIR:=$(DIR)
$(DIR).clean:
	$(RM) $($(DIR)_EXES)

#Nuitka builds
$($(DIR)_EXES): | $(BIN_DIR)
$(BIN_DIR)/%.exe: $(SRC_DIR)/$(DIR)/%.py
	@$(ECHO) "$(light_blue)Making $@ $(default_color)"
	nuitka $(NUITKA_FLAGS) --output-dir=$(BIN_DIR) $<

#ZipFile builds
$($(DIR)_PYZS): | $(BIN_DIR) $(BIN_DIR)/pyz
$($(DIR)_PYZS): $(BIN_DIR)/pyz/%: $(SRC_DIR)/$(DIR):
	python -m zipfile -c $@.zip  $(SRC_DIR)/$(DIR)/*
	echo "#!/usr/bin/env python3" >> $@
	cat $@.zip >> $@
	rm -f $@.zip

# Out of source pyc builds


ifneq ($(strip $(SUBDIRS)), "")
   include $(patsubst %, $(SRC_DIR)/$(DIR)/%/$(MFILE), $(SUBDIRS))
endif
