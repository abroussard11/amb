########################################
## The generic shared library makefile
########################################

include Vars.makefile
$(DIR)_LIB_SO := $(addprefix $(LIB_DIR)/lib, $(addsuffix .so, $(subst /,-,$(DIR))))

# Target-specific Variable Value
$($(DIR)_LIB_SO): DIR:=$(DIR)
$($(DIR)_LIB_SO): $($(DIR)_LIB_DEPS)
$($(DIR)_LIB_SO): $($(DIR)_OBJS)
	mkdir -p $(@D)
	g++ $(CXXFLAGS) $(LINKER_FLAGS) $($(DIR)_LINK_LIBS) -shared $($(DIR)_OBJS) -Wl,--whole-archive $($(DIR)_LIB_DEPS_FLAGS) -Wl,--no-whole-archive -o $@

-include $($(DIR)_DEPS)
include Cmds.makefile
include $(addprefix $(SRC_DIR)/$(DIR)/, $(addsuffix /makefile, $(SUBDIRS)))
