##################################
## The generic executable makefile
##################################

## Forward make to use the currently
## targeted architecture makefiles
include cxx/$(MAKE_TYPE)/vars.makefile
include cxx/$(MAKE_TYPE)/exe.makefile
include cxx/$(MAKE_TYPE)/cmds.makefile

include cxx/subdirs.makefile
