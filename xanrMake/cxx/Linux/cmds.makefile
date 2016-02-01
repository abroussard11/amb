######################
## The make commands
######################

cxx.all:: $(DIR)_all
$(DIR)_all: $($(DIR)_TGT)

cxx.clean:: $(DIR)_clean
$(DIR)_clean: DIR:=$(DIR)
$(DIR)_clean:
	@$(ECHO) "$(red)Cleaning $(DIR) $(default_color)"
	$(RM) $(strip $($(DIR)_clean_tgts))

# Define "order-only" prerequisite to create the output directory
$($(DIR)_OBJS): | $(OBJ_DIR)/$(DIR)
$(OBJ_DIR)/$(DIR):
	$(MKDIR) $@

# TODO: look into using a "Status Pattern Rule" for objects, see below
$(OBJ_DIR)/$(DIR)/%.o: $(SRC_DIR)/$(DIR)/%.cpp
	@echo -e "$(blue)Making $@ $(default_color)"
	$(COMPILE.cpp) $(MAKE_DEPS_FLAGS) -c $< -o $@

# With this, maybe we could use DIR specific variables?
#$($(DIR)_OBJECTS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
#cpp@$(ECHO) "$(blue)Making $@ $(default_color)"
#default_color$(COMPILE.cpp) $(MAKE_DEPS_FLAGS) $($(DIR)_ANY_VAR_HERE) -c $< -o $@

## TODO: Aaron, test this
$($(DIR)_DEPS): $(OBJ_DIR)/%.d: $(SRC_DIR)/%.cpp
	@$(RM) $@

-include $($(DIR)_DEPS)
