######################################################
## The generic Linux makefile for building executables
######################################################

$(DIR)_EXE := $(BUILD_DIR)/bin/$(EXE)

# Define "order-only" prerequisites
$($(DIR)_EXE): $($(DIR)_LIB_DEPS) | $($(DIR)_LIB_OO_DEPS) $(BIN_DIR)

# Target-specific Variable Value
$($(DIR)_EXE): DIR:=$(DIR)
$($(DIR)_EXE): $($(DIR)_OBJS)
	@echo -e "$(light_blue)Making $@ $(default_color)"
	$(COMPILE.cpp) $($(DIR)_OBJS) $($(DIR)_ALL_LIBS) -o $@

$(DIR)_TGT := $($(DIR)_EXE)

$(DIR)_ARCHIVE := $(patsubst %, $(LIB_DIR)/libamb-%.a, $(subst /,-,$(DIR)))
$($(DIR)_ARCHIVE): $($(DIR)_OBJS)
	@echo -e "$(yellow)Making $@ $(default_color)"
	$(AR) $@ $^
