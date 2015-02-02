######################
## The make commands
######################
# Commands defined:
#	 all
#   depend
#   clean
#   cleandeps
#   clobber

all:: $($(DIR)_EXE) $($(DIR)_LIB_SO)

depend:: $(DIR)_depend
$(DIR)_depend: $($(DIR)_DEPS)

clean:: $(DIR)_clean
$(DIR)_clean: DIR:=$(DIR)
$(DIR)_clean:
	$(RM) $($(DIR)_OBJS) $($(DIR)_LIB_SO) $($(DIR)_EXE)

cleandeps:: $(DIR)_cleandeps
$(DIR)_cleandeps: DIR:=$(DIR)
$(DIR)_cleandeps:
	$(RM) $($(DIR)_DEPS)

clobber:: $(DIR)_clean $(DIR)_cleandeps

# This could be a clever way of making just a particular module, if necessary.
# But that practice could have some negative consequences. Need to evaluate
#$(DIR):: $($(DIR)_EXE) $($(DIR)_LIB_SO)

# TODO: Find a way to build all targets without generating dependency files
#depend:: $(DIR)_depend
#$(DIR)_depend: DIR:=$(DIR)
#$(DIR)_depend:
#	echo -n $($(DIR)_DEPS)
