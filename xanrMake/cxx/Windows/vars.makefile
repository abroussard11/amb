###################################
## The make variables for Windows
###################################

$(DIR)_COMPONENT :=$(patsubst %,amb-%, $(subst /,-,$(DIR)))
$(DIR)_PROJ := $(patsubst %, $(VCX_DIR)/%.vcxproj, $($(DIR)_COMPONENT))

$(DIR)_SRCS := $(subst $(space),$(comma),$(strip $(FILES)))

HEADERS :=$(notdir $(wildcard $(SRC_DIR)/$(DIR)/*.h))
$(DIR)_HEADERS = $(subst $(space),$(comma),$(HEADERS))

$(DIR)_LINK_DIRS:= $(strip \
   $(LINK_DIRS) \
   $(SFML_DIR)/SFML/lib)

## Static libraries
$(DIR)_LINK_STATIC_LIBS := $(subst $(space),$(comma),$(LINK_STATIC_LIBS))
ifneq "$(strip $(LINK_STATIC_LIBS))" ""
   ifeq "$(findstring (LIB_DIR), $($(DIR)_LINK_DIRS))" ""
      $(DIR)_LINK_DIRS += $(LIB_DIR)
   endif
endif

## Bundled Static libraries
$(DIR)_LINK_STATIC_LIBS += $(subst $(space),$(comma),$(BUNDLE_LIBS))
ifneq "$(strip $(BUNDLE_LIBS))" ""
   ifeq "$(findstring (LIB_DIR), $($(DIR)_LINK_DIRS))" ""
      $(DIR)_LINK_DIRS += $(LIB_DIR)
   endif
endif

## Dynamic libraries
$(DIR)_LINK_DYNAMIC_LIBS := $(subst $(space),$(comma),$(LINK_DYNAMIC_LIBS))
ifneq "$(strip $(LINK_DYNAMIC_LIBS))" ""
   ifeq "$(findstring (LIB_DIR), $($(DIR)_LINK_DIRS))" ""
      $(DIR)_LINK_DIRS += $(LIB_DIR)
   endif
endif

$(DIR)_SYS_LIBS := $(subst $(space),$(comma),$(SYS_LIBS))

INC_DIRS += $(INCLUDE_DIRS)
$(DIR)_INC_DIRS :=$(strip $(INC_DIRS))



$(DIR)_DEPS := \
   $(LINK_STATIC_LIBS) \
   $(LINK_DYNAMIC_LIBS) \
   $(BUNDLE_LIBS)

## Build the command line options to send to xanr2vcxproj
$(DIR)_CMD_LINE_OPTIONS := \
   --component=$($(DIR)_COMPONENT) \
   --tool_set=$(VS_TOOLSET) \
   --dir=$(DIR) \
   --inc_dirs=$(subst /,\,$(subst $(space),$(comma),$($(DIR)_INC_DIRS)))

ifneq "$(strip $($(DIR)_SRCS))" ""
   $(DIR)_CMD_LINE_OPTIONS += --srcs=$($(DIR)_SRCS)
endif

ifneq "$(strip $($(DIR)_HEADERS))" ""
   $(DIR)_CMD_LINE_OPTIONS += --headers=$($(DIR)_HEADERS)
endif

ifneq "$(strip $($(DIR)_LINK_STATIC_LIBS))" ""
   $(DIR)_CMD_LINE_OPTIONS += --static_libs=$($(DIR)_LINK_STATIC_LIBS)
endif

ifneq "$(strip $($(DIR)_LINK_DYNAMIC_LIBS))" ""
   $(DIR)_CMD_LINE_OPTIONS += --dynamic_libs=$($(DIR)_LINK_DYNAMIC_LIBS)
endif

ifneq "$(strip $($(DIR)_SYS_LIBS))" ""
   $(DIR)_CMD_LINE_OPTIONS += --sys_libs=$($(DIR)_SYS_LIBS)
endif

ifneq "$(strip $($(DIR)_LINK_DIRS))" ""
   $(DIR)_CMD_LINE_OPTIONS += --link_dirs=$(subst /,\,$(subst $(space),$(comma),$($(DIR)_LINK_DIRS)))
endif

