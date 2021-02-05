PROJNAME = $(shell basename $(CURDIR))
MAINFILE = main

GITDIR = $(realpath $(CURDIR)/../..)

DEBUGDIR = $(GITDIR)/debug
SEOUL42DIR = $(GITDIR)/seoul42_project

BUILDDIR = $(realpath $(CURDIR))/build
BUILDDIRS = $(BUILDDIR) $(BUILDDIR)/$(PROJNAME)
PROJDIR = $(SEOUL42DIR)/$(PROJNAME)



TARGET = $(PROJNAME).out
B_TARGET = $(PROJNAME)_bonus.out

# FILES = $(wildcard $(PROJDIR)/*.c)
FILES = get_next_line get_next_line_utils

SRCS = $(patsubst %,$(PROJDIR)/%.c,$(FILES))
B_SRCS = $(patsubst %,$(PROJDIR)/%_bonus.c,$(FILES))

OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%.o,$(FILES))	# OBJS = $(subst $(SEOUL42DIR),$(BUILDDIR),$(FILES:.c=.o))
B_OBJS = $(patsubst %,$(BUILDDIR)/$(PROJNAME)/%_bonus.o,$(FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEFINE = -D BUFFER_SIZE=5
INCLUDE = -I $(PROJDIR) -I $(DEBUGDIR)

COMPILE = $(CC) $(CFLAGS) $(INCLUDE) $(DEFINE)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



.PHONY:					all
all:					echo $(BUILDDIRS) $(TARGET)

$(BUILDDIRS):
						$(MKDIR) $@

echo:
						@echo "DEFINE =" $(DEFINE)

bonus:					$(BUILDDIRS) $(B_TARGET)

$(TARGET):				$(BUILDDIR)/$(MAINFILE).o $(OBJS)
						$(CC) $^ -o $@

$(B_TARGET):			$(BUILDDIR)/$(MAINFILE).o $(M_OBJS)
						$(CC) $^ -o $@

$(BUILDDIR)/$(MAINFILE).o:	$(MAINFILE).c
						$(COMPILE) -o $@ -c $<

$(OBJS) $(B_OBJS):	$(BUILDDIR)/%.o: $(SEOUL42DIR)/%.c
						$(COMPILE) -o $@ -c $<

.PHONY:					clean
clean:
						$(RMDIR) $(BUILDDIR)

.PHONY:					fclean
fclean:					clean
						$(RM) $(TARGET)

.PHONY:					re
re:						fclean all
