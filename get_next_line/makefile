PROJNAME = $(shell basename $(CURDIR))

GITDIR = $(realpath $(CURDIR)/../..)

DEBUGDIR = $(GITDIR)/debug
SEOUL42DIR = $(GITDIR)/seoul42_project

BUILDDIR = $(realpath $(CURDIR))/build
BUILDDIRS = $(BUILDDIR) $(BUILDDIR)/$(PROJNAME)
PROJDIR = $(SEOUL42DIR)/$(PROJNAME)



TARGET = $(PROJNAME).out

SRCS = $(wildcard $(PROJDIR)/*.c)
OBJS = $(subst $(SEOUL42DIR), $(BUILDDIR), $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEFINE = -D BUFFER_SIZE=5
INCLUDE = -I $(PROJDIR) -I $(DEBUGDIR)

COMPILE = $(CC) $(CFLAGS) $(INCLUDE) $(DEFINE)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



.PHONY:				all
all:				$(BUILDDIRS) $(TARGET)

$(TARGET):			$(BUILDDIR)/main.o $(OBJS)
					$(CC) $^ -o $@

$(BUILDDIRS):
					$(MKDIR) $@

$(BUILDDIR)/main.o:	main.c
					$(COMPILE) -o $@ -c $<

$(OBJS):			$(BUILDDIR)/%.o: $(SEOUL42DIR)/%.c
					$(COMPILE) -o $@ -c $<

.PHONY:				clean
clean:
					$(RMDIR) $(BUILDDIR)

.PHONY:				fclean
fclean:				clean
					$(RM) $(TARGET)

.PHONY:				re
re:					fclean all
