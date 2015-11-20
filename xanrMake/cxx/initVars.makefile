###############################################
## Initialize all variables to the empty string
###############################################

$(info Reading amb/xanrMake/cxx/initVars.makefile)
$(info )


DIR :=
EXE :=
LINK_DIRS :=#           -L
LINK_STATIC_LIBS :=#    -l [dependencies]
LINK_DYNAMIC_LIBS :=#   -l [dependencies]
SYS_LIBS :=#            -l [non-dependencies]
BUNDLE_LIBS :=#         -Wl,--whole-archive (archives)
SUBDIRS :=
FILES :=
INC_DIRS :=
