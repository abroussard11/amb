# The generic shared library makefile 

$(DIRECTORY)_SRCS := $(addprefix $(AMB_SRC_DIR)/$(DIRECTORY)/, $(addsuffix .cpp, $(SRCS)))
$(DIRECTORY)_OBJS := $(addprefix $(AMB_OBJ_DIR)/$(DIRECTORY)/, $(addsuffix .o, $(SRCS)))
$(DIRECTORY)_DEPS := $(addprefix $(AMB_DEP_DIR)/$(DIRECTORY)/, $(addsuffix .d, $(SRCS)))
$(DIRECTORY)_LIB_SO := $(addprefix $(AMB_LIB_DIR)/lib, $(addsuffix .so, $(subst /,-,$(DIRECTORY))))

$($(DIRECTORY)_LIB_SO): $($(DIRECTORY)_OBJS)
	mkdir -p $(@D)
	g++ -std=c++11 -Og -g -Wall -I$(INCLUDE_DIRS) -shared $^ $(LOADLIBES) $(LDLIBS) -o $@

# Include dependancy files
-include $($(DIRECTORY)_DEPS)

# Include makefiles from subdirectories 
include $(addprefix $(AMB_SRC_DIR)/$(DIRECTORY)/, $(addsuffix /makefile, $(SUBDIRS)))
