###############################
## The generic module makefile
###############################

include Vars.makefile
$(DIR)_EXE := $(BUILD_DIR)/$(EXE)

# Target-specific Variable Value
$($(DIR)_EXE): DIR:=$(DIR)
$($(DIR)_EXE): $($(DIR)_LIB_DEPS)
$($(DIR)_EXE): $($(DIR)_OBJS)
	mkdir -p $(@D)
	g++ $(CXXFLAGS) $(LINKER_FLAGS) $($(DIR)_LINK_LIBS_FLAGS) -Wl,--start-group $($(DIR)_LIB_DEPS_FLAGS) -Wl,--end-group $($(DIR)_OBJS) -o $@

-include $($(DIR)_DEPS)
include Cmds.makefile
include $(addprefix $(SRC_DIR)/$(DIR)/, $(addsuffix /makefile, $(SUBDIRS)))
