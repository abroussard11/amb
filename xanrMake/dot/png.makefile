#########################################################
## The generic makefile for building png images from dot
#########################################################

$(DIR)_SRCS := $(patsubst %, $(SRC_DIR)/$(DIR)/%.dot, $(FILES))
$(DIR)_PNGS := $(patsubst %, $(PNG_DIR)/$(DIR)/%.png, $(FILES))

dot.all:: $($(DIR)_PNGS)
dot.clean:: $(DIR)_clean

$(DIR)_clean: DIR:=$(DIR)
$(DIR)_clean:
	$(RM) $($(DIR)_PNGS)

$($(DIR)_PNGS): | $(PNG_DIR)/$(DIR)
$(PNG_DIR)/$(DIR):
	$(MKDIR) $@

$(PNG_DIR)/$(DIR)/%.png: $(SRC_DIR)/$(DIR)/%.dot
	@$(ECHO) "$(light_blue)Making $@ $(default_color)"
	dot -Tpng $< -o $@

