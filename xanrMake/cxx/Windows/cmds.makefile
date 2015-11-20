######################
## The make commands
######################

$(PROJ_SLN): $($(DIR)_PROJ)

clean_vcx:: $(DIR)_clean_vcx

$($(DIR)_PROJ): DIR:=$(DIR)
$($(DIR)_PROJ): $(SRC_DIR)/$(DIR)/$(MFILE)
	xanr2vcxproj.py $($(DIR)_CMD_LINE_OPTIONS)

$(DIR)_clean_vcx: DIR:=$(DIR)
$(DIR)_clean_vcx:
	$(RM) $(subst /,\,$($(DIR)_PROJ))

$(DIR)_clean: DIR:=$(DIR)
$(DIR)_clean: $($(DIR)_PROJ)
	msbuild $($(DIR)_PROJ) /t:Clean

