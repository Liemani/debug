PROJNAME = $(shell basename $(CURDIR))

GITDIR = $(realpath $(CURDIR)/../..)

DEBUGDIR = $(GITDIR)/debug
SEOUL42DIR = $(GITDIR)/seoul42_project

BUILDDIR = $(realpath $(CURDIR))/build
BUILDDIRS = $(BUILDDIR) $(BUILDDIR)/$(PROJNAME)
PROJDIR = $(SEOUL42DIR)/$(PROJNAME)



TARGET = $(PROJNAME).out
B_TARGET = $(PROJNAME)_bonus.out
D_TARGET = $(PROJNAME)_debug.out
A_TARGET = $(PROJNAME)_asan.out

# FILES = $(wildcard $(PROJDIR)/*.c)
FILES = get_next_line get_next_line_utils

SRCS = $(patsubst %,$(PROJDIR)/%.c,$(FILES))
B_SRCS = $(patsubst %,$(PROJDIR)/%_bonus.c,$(FILES))

OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%.o,$(FILES))	# OBJS = $(subst $(SEOUL42DIR),$(BUILDDIR),$(FILES:.c=.o))
B_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%_bonus.o,$(FILES))
D_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%_debug.o,$(FILES))
A_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%_asan.o,$(FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEFINE = -D BUFFER_SIZE=5
INCLUDE = -I $(PROJDIR) -I $(DEBUGDIR)

COMPILE = $(CC) $(CFLAGS) $(INCLUDE) $(DEFINE)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



.PHONY:						all bonus, debug, asan
all:						echo $(BUILDDIRS) $(TARGET)
bonus:						echo $(BUILDDIRS) $(B_TARGET)
debug:						echo $(BUILDDIRS) $(D_TARGET)
asan:						echo $(BUILDDIRS) $(A_TARGET)

.PHONY: echo
echo:
							@echo "DEFINE =" $(DEFINE)

$(BUILDDIRS):
							$(MKDIR) $@

$(TARGET):					$(BUILDDIR)/$(MAINFILE).o $(OBJS)
							$(CC) $^ -o $@
$(B_TARGET):				$(BUILDDIR)/$(MAINFILE).o $(M_OBJS)
							$(CC) $^ -o $@
$(D_TARGET):				$(BUILDDIR)/$(MAINFILE).o $(D_OBJS)
							$(CC) $^ -o $@
$(A_TARGET):				$(BUILDDIR)/$(MAINFILE).o $(A_OBJS)
							$(CC) $^ -o $@

$(BUILDDIR)/main.o:			main.c
							$(COMPILE) -o $@ -c $<
$(OBJS) $(B_OBJS):			$(BUILDDIR)/%.o: $(SEOUL42DIR)/%.c
							$(COMPILE) -o $@ -c $<
$(D_OBJS):					$(BUILDDIR)/%_debug.o: $(SEOUL42DIR)/%.c
							$(COMPILE) -g -o $@ -c $<
$(A_OBJS):					$(BUILDDIR)/%_asan.o: $(SEOUL42DIR)/%.c
							$(COMPILE) -g3 -fsanitize=address -o $@ -c $<

.PHONY:						clean
clean:
							$(RMDIR) $(BUILDDIR)

.PHONY:						fclean
fclean:						clean
							$(RM) $(TARGET) $(B_TARGET) $(D_TARGET) $(A_TARGET)

.PHONY:						re
re:							fclean all
