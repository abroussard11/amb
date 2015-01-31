######################
## The make variables
######################

$(DIR)_SRCS := $(addprefix $(SRC_DIR)/$(DIR)/, $(addsuffix .cpp, $(SRCS)))
$(DIR)_OBJS := $(addprefix $(OBJ_DIR)/$(DIR)/, $(addsuffix .o, $(SRCS)))
$(DIR)_DEPS := $(addprefix $(DEP_DIR)/$(DIR)/, $(addsuffix .d, $(SRCS)))
$(DIR)_LIB_DEPS := $(addprefix $(LIB_DIR)/lib, $(addsuffix .so, $(LIB_DEPS)))
$(DIR)_LIB_DEPS_FLAGS := $(addprefix -l, $(LIB_DEPS))
$(DIR)_LINK_LIBS_FLAGS := $(addprefix -l, $(LINK_LIBS))
