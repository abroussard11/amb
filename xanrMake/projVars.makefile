$(info Reading amb/xanrMake/projVars.makefile)

# Shell commands
export MKDIR := mkdir -p
export RM := rm -f
export ECHO :=echo -e

## Colors!!
## set the COLORFUL_MAKE variable in your environment
ifeq "$(COLORFUL_MAKE)" "true"
   $(info COLORFUL_MAKE is on)
   export        black := \033[0;30m
   export          red := \033[0;31m
   export        green := \033[0;32m
   export       orange := \033[0;33m
   export         blue := \033[0;34m
   export       purple := \033[0;35m
   export         cyan := \033[0;36m
	export   light_back := \033[1;30m
   export   light_gray := \033[0;37m
   export    dark_gray := \033[1;30m
   export    light_red := \033[1;31m
   export  light_green := \033[1;32m
   export       yellow := \033[1;33m
   export   light_blue := \033[1;34m
   export light_purple := \033[1;35m
   export   light_cyan := \033[1;36m
   export        white := \033[1;37m
   export light_blue_bg:= \033[1;44m

   export bg0:= \033[40m
   export bg1:= \033[41m
   export bg2:= \033[42m
   export bg3:= \033[43m
   export bg4:= \033[44m
   export bg5:= \033[45m
   export bg6:= \033[46m
   export bg7:= \033[47m
   export bg8:= \033[48m
   export bg9:= \033[49m

   export default_color:= \033[0m
else
   $(info COLORFUL_MAKE is off)
   export        black :=#
   export          red :=#
   export        green :=#
   export       orange :=#
   export         blue :=#
   export       purple :=#
   export         cyan :=#
   export   light_gray :=#
   export    dark_gray :=#
   export    light_red :=#
   export  light_green :=#
   export       yellow :=#
   export   light_blue :=#
   export light_purple :=#
   export   light_cyan :=#
   export        white :=#
   export light_blue_bg:=#
   export default_color:=#
endif

colortest.all::
	@$(ECHO) "$(black)black"
	@$(ECHO) "$(red)red"
	@$(ECHO) "$(green)green"
	@$(ECHO) "$(orange)orange"
	@$(ECHO) "$(blue)blue"
	@$(ECHO) "$(purple)purple"
	@$(ECHO) "$(cyan)cyan"
	@$(ECHO) "$(light_gray)light_gray"
	@$(ECHO) "$(dark_gray)dark_gray"
	@$(ECHO) "$(light_red)light_red"
	@$(ECHO) "$(light_green)light_green"
	@$(ECHO) "$(yellow)yellow"
	@$(ECHO) "$(light_blue)light_blue"
	@$(ECHO) "$(light_purple)light_purple"
	@$(ECHO) "$(light_cyan)light_cyan"
	@$(ECHO) "$(white)white"
	@$(ECHO) "$(black)black"
	@$(ECHO) "$(light_blue_bg)light_blue_bg"


	@$(ECHO) "$(bg0)bg0"
	@$(ECHO) "$(bg1)bg1"
	@$(ECHO) "$(bg2)bg2"
	@$(ECHO) "$(bg3)bg3"
	@$(ECHO) "$(bg4)bg4"
	@$(ECHO) "$(bg5)bg5"
	@$(ECHO) "$(bg6)bg6"
	@$(ECHO) "$(bg7)bg7"
	@$(ECHO) "$(bg8)bg8"
	@$(ECHO) "$(bg9)bg9"

	@$(ECHO) "$(default_color)default_color"

