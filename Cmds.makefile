######################
## The make commands
######################
# Commands defined:
#	 all
#   depend
#   clean
#   cleandeps
#   clobber

all:: $($(DIR)_EXE)

# TODO: Find a way to build all targets without generating dependency files
#depend:: $(DIR)_depend
#$(DIR)_depend: DIR:=$(DIR)
#$(DIR)_depend:
#	mkdir -p $(DEP_DIR)/$(DIR)
#	echo -n $($(DIR)_DEPS)

depend:: $($(DIR)_DEPS)
$($(DIR)_DEPS): $($(DIR)_SRCS)
	mkdir -p $(@D)
	echo -n $@" " > $@
	g++ -MM $(CXXFLAGS) $< >> $@

clean:: $(DIR)_clean
$(DIR)_clean: DIR:=$(DIR)
$(DIR)_clean:
	rm -f $($(DIR)_OBJS) $($(DIR)_LIB_SO) $($(DIR)_EXE)

cleandeps:: $(DIR)_cleandeps
$(DIR)_cleandeps: DIR:=$(DIR)
$(DIR)_cleandeps:
	rm -f $($(DIR)_DEPS)

clobber:: $(DIR)_clean $(DIR)_cleandeps
