$(info Reading amb/xanrMake/projVars.makefile)

# Shell commands
MKDIR := mkdir -p
RM := rm -f
ECHO :=echo -e

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

