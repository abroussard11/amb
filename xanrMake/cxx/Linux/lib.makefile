###################################################
## The generic Linux makefile for building archives
###################################################

$(DIR)_LIB := $(patsubst %, $(LIB_DIR)/libamb-%.a, $(subst /,-,$(DIR)))

# Define "order-only" prerequisites
$($(DIR)_LIB): | $($(DIR)_LIB_DEPS) $(LIB_DIR)

# Target-specific Variable Value
$($(DIR)_LIB): DIR:=$(DIR)
$($(DIR)_LIB): $($(DIR)_OBJS)
	@echo -e "$(yellow)Making $@ $(default_color)"
	$(AR) $@ $^


$(DIR)_TGT := $($(DIR)_LIB)
