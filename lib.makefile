########################################
## The generic shared library makefile
########################################

include Vars.makefile
$(DIR)_LIB_SO := $(addprefix $(LIB_DIR)/lib, $(addsuffix .so, $(subst /,-,$(DIR))))
$(DIR)_LIB_SO_TEST := $(patsubst %, $(LIB_DIR)/lib%.so, $(subst /,-,$(DIR)))

# Define "order-only" prerequisites
$($(DIR)_LIB_SO): | $($(DIR)_LIB_DEPS) $(LIB_DIR)

# Target-specific Variable Value
$($(DIR)_LIB_SO): DIR:=$(DIR)
$($(DIR)_LIB_SO): $($(DIR)_OBJS)
	g++ $(CXXFLAGS) $(LINKER_FLAGS) $($(DIR)_LINK_LIBS) -shared $($(DIR)_OBJS) -Wl,--whole-archive $($(DIR)_LIB_DEPS_FLAGS) -Wl,--no-whole-archive -o $@
	@echo AARON $($(DIR)_LIB_SO_TEST) vs $($(DIR)_LIB_SO)

-include $($(DIR)_DEPS)
include Cmds.makefile
include $(addprefix $(SRC_DIR)/$(DIR)/, $(addsuffix /makefile, $(SUBDIRS)))
