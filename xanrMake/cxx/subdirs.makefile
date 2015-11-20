##############################
## For convenience
##############################

ifneq ($(strip $(SUBDIRS)), "")
   include $(patsubst %, $(SRC_DIR)/$(DIR)/%/$(MFILE), $(SUBDIRS))
endif
