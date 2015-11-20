######################
## The make variables
######################

$(DIR)_SRCS := $(patsubst %, $(SRC_DIR)/$(DIR)/%.cpp, $(FILES))
$(DIR)_OBJS := $(patsubst %, $(OBJ_DIR)/$(DIR)/%.o, $(FILES))
$(DIR)_DEPS := $(patsubst %, $(OBJ_DIR)/$(DIR)/%.d, $(FILES))

$(DIR)_LIB_DEPS := $(patsubst %, $(LIB_DIR)/lib%.a, $(LINK_STATIC_LIBS))
$(DIR)_LIB_OO_DEPS += $(patsubst %, $(LIB_DIR)/lib%.so, $(LINK_DYNAMIC_LIBS))

$(DIR)_LINK_DIRS := $(addprefix -L, $(LINK_DIRS))


$(DIR)_LINK_STATIC_LIBS := $(addprefix -l, $(LINK_STATIC_LIBS))
ifneq "$(strip $(LINK_STATIC_LIBS))" ""
   ifeq "$(findstring (LIB_DIR), $($(DIR)_LINK_DIRS))" ""
      $(DIR)_LINK_DIRS += -L$(LIB_DIR)
   endif
endif

$(DIR)_LINK_DYNAMIC_LIBS := $(addprefix -l, $(LINK_DYNAMIC_LIBS))
ifneq "$(strip $(LINK_DYNAMIC_LIBS))" ""
   ifeq "$(findstring (LIB_DIR), $($(DIR)_LINK_DIRS))" ""
      $(DIR)_LINK_DIRS += -L$(LIB_DIR)
   endif
endif

$(DIR)_SYS_LIBS := $(addprefix -l, $(SYS_LIBS))

$(DIR)_BUNDLE_LIBS :=# initialize variable
ifneq "$(strip $(BUNDLE_LIBS))" ""
$(DIR)_BUNDLE_LIBS := -Wl,--whole-archive -L$(LIB_DIR) $(addprefix -l, $(BUNDLE_LIBS)) -Wl,--no-whole-archive
$(DIR)_LIB_DEPS += $(patsubst %, $(LIB_DIR)/lib%.a, $(BUNDLE_LIBS))
endif

$(DIR)_LINK_LIBS :=$($(DIR)_LINK_DIRS) $($(DIR)_LINK_STATIC_LIBS) $($(DIR)_LINK_DYNAMIC_LIBS) $($(DIR)_BUNDLE_LIBS)

$(DIR)_ALL_LIBS :=$($(DIR)_LINK_LIBS) $($(DIR)_SYS_LIBS)

## Word count variables
$(DIR)_HEADERS = $(wildcard $(SRC_DIR)/$(DIR)/*.h)
WC_SRCS += $(sort $($(DIR)_SRCS) $($(DIR)_HEADERS))

## Files to clean (recursively-defined because some of these variables do not exist yet)
$(DIR)_clean_tgts = \
   $($(DIR)_OBJS) \
   $($(DIR)_LIB) \
   $($(DIR)_LIB_SO) \
   $($(DIR)_EXE) \
   $($(DIR)_ARCHIVE) \
   $($(DIR)_DEPS)
