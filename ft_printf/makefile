MAINFILE = main
LIBNAME = ftprintf



GITDIR = $(realpath $(CURDIR)/../..)

DEBUGDIR = ..
BUILDDIR = build
PROJNAME = $(shell basename $(CURDIR))
MAINDIR = mains

BUILDDIRS = $(BUILDDIR) $(BUILDDIR)/$(MAINDIR) $(BUILDDIR)/$(PROJNAME)

SEOUL42DIR = $(GITDIR)/seoul42_project
PROJDIR = $(SEOUL42DIR)/$(PROJNAME)



D_SUFFIX = _debug
A_SUFFIX = _asan
T_SUFFIX = _test

M_OUT = $(PROJNAME).out
D_OUT = $(PROJNAME)$(D_SUFFIX).out
A_OUT = $(PROJNAME)$(A_SUFFIX).out
T_OUT = $(PROJNAME)$(T_SUFFIX).out
OUTS = $(M_OUT) $(D_OUT) $(A_OUT)

MAIN_C = $(MAINDIR)/$(MAINFILE).c
LIBFILE = $(PROJDIR)/lib$(LIBNAME).a

MAIN_BASE = $(BUILDDIR)/$(MAINDIR)/$(MAINFILE)
MAIN_O = $(MAIN_BASE).o
D_MAIN_O = $(MAIN_BASE)$(d_SUFFIX).o
A_MAIN_O = $(MAIN_BASE)$(A_SUFFIX).o
T_MAIN_O = $(MAIN_BASE)$(T_SUFFIX).o



CC = gcc
CFLAGS = -w -Wall -Wextra -Werror
INCLUDE = -I $(PROJDIR) -I $(DEBUGDIR)
LIBRARY = -L$(PROJDIR) -l$(LIBNAME)
DEBUG_OPTION = -g
ASAN_OPTION = -g3 -fsanitize=address

COMPILE = $(CC) $(CFLAGS) $(INCLUDE)
LINK = $(CC) $(INCLUDE) $(LIBRARY)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



.PHONY:			all mandatory bonus debug asan
all:			$(BUILDDIRS) $(OUTS) clean
mandatory:		$(BUILDDIRS) $(M_OUT)
debug:			$(BUILDDIRS) $(D_OUT)
asan:			$(BUILDDIRS) $(A_OUT)

$(BUILDDIRS):
				$(MKDIR) $@

$(M_OUT):		$(LIBFILE) $(MAIN_O)
				$(LINK) -o $@ $^
$(D_OUT):		$(LIBFILE) $(D_MAIN_O)
				$(LINK) -o $@ $^ $(DEBUG_OPTION)
$(A_OUT):		$(LIBFILE) $(A_MAIN_O)
				$(LINK) -o $@ $^ $(ASAN_OPTION)
$(T_OUT):		$(T_MAIN_O)
				$(CC) -o $@ $^

$(LIBFILE):
				make -C $(PROJDIR) debug

$(MAIN_O):		$(MAIN_C)
				$(COMPILE) -o $@ -c $<
$(D_MAIN_O):	$(MAIN_C)
				$(COMPILE) -o $@ -c $< $(DEBUG_OPTION)
$(A_MAIN_O):	$(MAIN_C)
				$(COMPILE) -o $@ -c $< $(ASAN_OPTION)
$(T_MAIN_O):	$(MAINDIR)/$(MAINFILE)$(T_SUFFIX).c
				$(COMPILE) -o $@ -c $<

.PHONY:			test test2
test:			$(BUILDDIRS) $(T_OUT)
test2:
				echo $(D_MAIN_O)
				echo $(A_MAIN_O)
				echo $(T_MAIN_O)

.PHONY:			clean fclean re
clean:
				make -C $(PROJDIR) fclean
				$(RMDIR) $(BUILDDIR)
fclean:			clean
				$(RM) $(OUTS)
re:				fclean all
