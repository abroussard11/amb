######################
## The make variables
######################

##
# Variables to be defined by all submodules:
#    DIR :=      [The current directory, relative to the src/ directory]
#    SUBDIRS :=  [List of subdirectories, relative to the current directory]
#    LINK_LIBS :=[
#    LIB_DEPS :=
#    SRCS :=     [Source file list with out .cpp extension]
#    
#$(DIR)_SRCS := $(addprefix $(SRC_DIR)/$(DIR)/, $(addsuffix .cpp, $(SRCS)))
#$(DIR)_OBJS := $(addprefix $(OBJ_DIR)/$(DIR)/, $(addsuffix .o, $(SRCS)))
#$(DIR)_DEPS := $(addprefix $(DEP_DIR)/$(DIR)/, $(addsuffix .d, $(SRCS)))
#$(DIR)_LIB_DEPS := $(addprefix $(LIB_DIR)/lib, $(addsuffix .so, $(LIB_DEPS)))
#$(DIR)_LIB_DEPS_FLAGS := $(addprefix -l, $(LIB_DEPS))
#$(DIR)_LINK_LIBS_FLAGS := $(addprefix -l, $(LINK_LIBS))

$(DIR)_SRCS := $(patsubst %, $(SRC_DIR)/$(DIR)/%.cpp, $(SRCS))
$(DIR)_OBJS := $(patsubst %, $(OBJ_DIR)/$(DIR)/%.o, $(SRCS))
$(DIR)_DEPS := $(patsubst %, $(DEP_DIR)/$(DIR)/%.d, $(SRCS))
$(DIR)_LIB_DEPS := $(patsubst %, $(LIB_DIR)/lib%.so, $(LIB_DEPS))
$(DIR)_LIB_DEPS_FLAGS := $(addprefix -l, $(LIB_DEPS))
$(DIR)_LINK_LIBS_FLAGS := $(addprefix -l, $(LINK_LIBS))

# Define "order-only" prerequisite to create the output directory
$($(DIR)_OBJS): | $(OBJ_DIR)/$(DIR)
$(OBJ_DIR)/$(DIR):
	$(MKDIR) $@

$($(DIR)_DEPS): | $(DEP_DIR)/$(DIR)
$(DEP_DIR)/$(DIR):
	$(MKDIR) $@

