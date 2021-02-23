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

M_OUT = $(PROJNAME).out
D_OUT = $(PROJNAME)$(D_SUFFIX).out
A_OUT = $(PROJNAME)$(A_SUFFIX).out
OUTS = $(M_OUT) $(D_OUT) $(A_OUT)

MAIN_C = $(MAINDIR)/$(MAINFILE).c
LIBFILE = $(PROJDIR)/lib$(LIBNAME).a

MAIN_O = $(BUILDDIR)/$(MAINDIR)/$(MAINFILE).o
D_MAIN = $(BUILDDIR)/$(MAINDIR)/$(MAINFILE)$(D_SUFFIX).o
A_MAIN = $(BUILDDIR)/$(MAINDIR)/$(MAINFILE)$(A_SUFFIX).o



CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I $(PROJDIR) -I $(DEBUGDIR)
LIBRARY = -L$(PROJDIR) -l$(LIBNAME)
DEBUG_OPTION = -g
ASAN_OPTION = -g3 -fsanitize=address

COMPILE = $(CC) $(CFLAGS) $(INCLUDE)
LINK = $(CC) $(INCLUDE) $(LIBRARY)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



.PHONY:					all mandatory bonus debug asan
all:					$(BUILDDIRS) $(OUTS)
mandatory:				$(BUILDDIRS) $(M_OUT)
debug:					$(BUILDDIRS) $(D_OUT)
asan:					$(BUILDDIRS) $(A_OUT)

$(BUILDDIRS):
						@$(MKDIR) $@

$(M_OUT):				$(MAIN_O) $(LIBFILE)
						$(LINK) -o $@ $^
$(D_OUT):				$(D_MAIN) $(LIBFILE)
						$(LINK) -o $@ $^
$(A_OUT):				$(A_MAIN) $(LIBFILE)
						$(LINK) -o $@ $^ $(ASAN_OPTION)

$(MAIN_O):				$(MAIN_C)
						$(COMPILE) -o $@ -c $<
$(D_MAIN):				$(MAIN_C)
						$(COMPILE) -o $@ -c $< $(DEBUG_OPTION)
$(A_MAIN):				$(MAIN_C)
						$(COMPILE) -o $@ -c $< $(ASAN_OPTION)

.PHONY:					clean fclean re
clean:
						$(RMDIR) $(BUILDDIR)
fclean:					clean
						$(RM) $(OUTS)
re:						fclean all
