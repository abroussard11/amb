######################
## The make commands
######################

all:: $(DIR)_all
$(DIR)_all: $($(DIR)_TGT)

clean:: $(DIR)_clean
$(DIR)_clean: DIR:=$(DIR)
$(DIR)_clean:
	@echo -e "$(red)Cleaning $(DIR) $(default_color)"
	$(RM) $(strip $($(DIR)_clean_tgts))

# Define "order-only" prerequisite to create the output directory
$($(DIR)_OBJS): | $(OBJ_DIR)/$(DIR)
$(OBJ_DIR)/$(DIR):
	$(MKDIR) $@

$(OBJ_DIR)/$(DIR)/%.o: $(SRC_DIR)/$(DIR)/%.cpp
	@echo -e "$(blue)Making $@ $(default_color)"
	$(COMPILE.cpp) $(MAKE_DEPS_FLAGS) -c $< -o $@

-include $($(DIR)_DEPS)
