###############################
## The generic module makefile
###############################

# NOTE: Defining the EXE target as a double-colon rule could allow
# us to list all executable targets in the top-level makefile as
# double-colon rules as well, enabling tab-completion on the targets 
# when using tcsh. #TODO check consequences when multiple EXE targets exist

include Vars.makefile
$(DIR)_EXE := $(BUILD_DIR)/$(EXE)

# Define "order-only" prerequisites
$($(DIR)_EXE):: | $($(DIR)_LIB_DEPS) $(BUILD_DIR)
$(BUILD_DIR):
	mkdir -p $@

# Target-specific Variable Value
$($(DIR)_EXE):: DIR:=$(DIR)
$($(DIR)_EXE):: $($(DIR)_OBJS)
	g++ $(CXXFLAGS) $(LINKER_FLAGS) $($(DIR)_LINK_LIBS_FLAGS) -Wl,--start-group $($(DIR)_LIB_DEPS_FLAGS) -Wl,--end-group $($(DIR)_OBJS) -o $@

-include $($(DIR)_DEPS)
include Cmds.makefile

#include $(addprefix $(SRC_DIR)/$(DIR)/, $(addsuffix /makefile, $(SUBDIRS)))
include $(patsubst %, $(SRC_DIR)/$(DIR)/%/makefile, $(SUBDIRS))
