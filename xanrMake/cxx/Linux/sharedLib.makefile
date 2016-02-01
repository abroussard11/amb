#################################################
## The generic Linux makefile for building SOs
#################################################


$(DIR)_LIB_SO := $(patsubst %, $(LIB_DIR)/libamb-%.so, $(subst /,-,$(DIR)))

# Define "order-only" prerequisites
$($(DIR)_LIB_SO): $($(DIR)_LIB_DEPS) | $($(DIR)_LIB_OO_DEPS) $(LIB_DIR)

# Target-specific Variable Value
$($(DIR)_LIB_SO): DIR:=$(DIR)
$($(DIR)_LIB_SO): $($(DIR)_OBJS)
	@echo -e "$(light_green)Making $@ $(default_color)"
	$(COMPILE.cpp) -shared $($(DIR)_OBJS) $($(DIR)_ALL_LIBS) -o $@

$(DIR)_TGT := $($(DIR)_LIB_SO)
