# The generic module makefile 

$(DIRECTORY)_SRCS := $(addprefix $(AMB_SRC_DIR)/$(DIRECTORY)/, $(addsuffix .cpp, $(SRCS)))
$(DIRECTORY)_OBJS := $(addprefix $(AMB_OBJ_DIR)/$(DIRECTORY)/, $(addsuffix .o, $(SRCS)))
$(DIRECTORY)_DEPS := $(addprefix $(AMB_DEP_DIR)/$(DIRECTORY)/, $(addsuffix .d, $(SRCS)))
$(DIRECTORY)_LIB_DEPS := $(addprefix $(AMB_LIB_DIR)/lib, $(addsuffix .so, $(LIB_DEPENDENCIES)))

# The executable
$(EXE): $($(DIRECTORY)_OBJS) $($(DIRECTORY)_LIB_DEPS)
	g++ -I$(AMB_SRC_DIR) $(AMB_LINKER_FLAGS) $^ -o $(AMB_BUILD_DIR)/$(EXE)

