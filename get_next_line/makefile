
GITDIR = $(realpath $(CURDIR)/../..)

DEBUGDIR = ..
BUILDDIR = build
PROJNAME = $(shell basename $(CURDIR))
MAINDIR = mains

BUILDDIRS = $(BUILDDIR) $(BUILDDIR)/$(MAINDIR) $(BUILDDIR)/$(PROJNAME)

SEOUL42DIR = $(GITDIR)/seoul42_project
PROJDIR = $(SEOUL42DIR)/$(PROJNAME)



B_SUFFIX = _bonus
D_SUFFIX = _debug
A_SUFFIX = _asan

M_OUT = $(PROJNAME).out
B_OUT = $(PROJNAME)$(B_SUFFIX).out
D_OUT = $(PROJNAME)$(D_SUFFIX).out
A_OUT = $(PROJNAME)$(A_SUFFIX).out
OUTS = $(M_OUT) $(B_OUT) $(D_OUT) $(A_OUT)

MAINFILE = main_stdin
MAIN_C = $(MAINDIR)/$(MAINFILE).c
FILES = get_next_line get_next_line_utils
M_SRCS = $(patsubst %,$(PROJNAME)/%.c,$(FILES))
B_SRCS = $(patsubst %,$(PROJNAME)/%$(B_SUFFIX).c,$(FILES))

MAIN_O = $(BUILDDIR)/$(MAINDIR)/$(MAINFILE).o
D_MAIN = $(BUILDDIR)/$(MAINDIR)/$(MAINFILE)$(D_SUFFIX).o
A_MAIN = $(BUILDDIR)/$(MAINDIR)/$(MAINFILE)$(A_SUFFIX).o
M_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%.o,$(FILES))
B_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%$(B_SUFFIX).o,$(FILES))
D_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%$(D_SUFFIX).o,$(FILES))
A_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%$(A_SUFFIX).o,$(FILES))



CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEFINE = -D BUFFER_SIZE=5
INCLUDE = -I $(PROJDIR) -I $(DEBUGDIR)
DEBUG_OPTION = -g
ASAN_OPTION = -g3 -fsanitize=address

COMPILE = $(CC) $(CFLAGS) $(INCLUDE) $(DEFINE)
LINK = $(CC)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



.PHONY:					all mandatory bonus debug asan
all:					echo $(BUILDDIRS) $(OUTS)
mandatory:				echo $(BUILDDIRS) $(M_OUT)
bonus:					echo $(BUILDDIRS) $(B_OUT)
debug:					echo $(BUILDDIRS) $(D_OUT)
asan:					echo $(BUILDDIRS) $(A_OUT)

.PHONY: echo
echo:
						@echo "DEFINE = ["$(DEFINE)"]"

$(BUILDDIRS):
						@$(MKDIR) $@

$(M_OUT):				$(MAIN_O) $(M_OBJS)
						$(CC) -o $@ $^
$(B_OUT):				$(MAIN_O) $(B_OBJS)
						$(CC) -o $@ $^
$(D_OUT):				$(D_MAIN) $(D_OBJS)
						$(CC) -o $@ $^
$(A_OUT):				$(A_MAIN) $(A_OBJS)
						$(CC) -o $@ $^ $(ASAN_OPTION)

$(MAIN_O):				$(MAIN_C)
						$(COMPILE) -o $@ -c $<
$(D_MAIN):				$(MAIN_C)
						$(COMPILE) -o $@ -c $< $(DEBUG_OPTION)
$(A_MAIN):				$(MAIN_C)
						$(COMPILE) -o $@ -c $< $(ASAN_OPTION)

$(M_OBJS) $(B_OBJS):	$(BUILDDIR)/%.o: $(SEOUL42DIR)/%.c
						$(COMPILE) -o $@ -c $<
$(D_OBJS):				$(BUILDDIR)/%$(D_SUFFIX).o: $(SEOUL42DIR)/%.c
						$(COMPILE) -o $@ -c $< $(DEBUG_OPTION)
$(A_OBJS):				$(BUILDDIR)/%$(A_SUFFIX).o: $(SEOUL42DIR)/%.c
						$(COMPILE) -o $@ -c $< $(ASAN_OPTION)

.PHONY:					clean fclean re
clean:
						$(RMDIR) $(BUILDDIR)
fclean:					clean
						$(RM) $(OUTS)
re:						fclean all
