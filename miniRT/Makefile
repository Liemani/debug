PROJNAME	= $(shell basename $(CURDIR))



GITDIR		= $(realpath $(CURDIR)/../..)
SEOUL42DIR		= $(GITDIR)/seoul42_project
PROJDIR				= $(SEOUL42DIR)/$(PROJNAME)
DEBUGDIR		= $(GITDIR)/debug
BUILDDIR				= $(CURDIR)/build
BUILDDIRS				= $(BUILDDIR) \
						  $(BUILDDIR)/value_type \
						  $(BUILDDIR)/util



M_OUT	= $(PROJNAME)_mandatory.out
D_OUT	= $(PROJNAME)_debug.out
A_OUT	= $(PROJNAME)_asan.out
OUTS	= $(M_OUT) $(D_OUT) $(A_OUT)



ABSTRACT_SRCS	= \
				  value_type/t_vector3.c \
				  value_type/t_matrix3.c \
				  util/lmt_alloc.c
SRCS			= $(patsubst %,$(BUILDDIR)/%,$(ABSTRACT_SRCS))
OBJS			= $(SRCS:.c=.o)



CC = clang
CFLAGS = -w -Wall -Wextra -Werror
INCLUDE = \
		  -I $(PROJDIR)/value_type \
		  -I $(PROJDIR)/util
LIBRARY = -l m
DEBUG_OPTION = -g
ASAN_OPTION = -g3 -fsanitize=address

COMPILE = $(CC) $(CFLAGS) $(INCLUDE)
LINK = $(CC) $(INCLUDE) $(LIBRARY)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



.PHONY:			all debug setDebug asan setAsan clean fclean re
all:			$(BUILDDIRS) $(M_OUT)

debug:			$(BUILDDIRS) $(D_OUT)
setDebug:
				$(eval OPTION = $(DEBUG_OPTION))
				$(eval SUFFIX = $(D_SUFFIX))

asan:			$(BUILDDIRS) $(A_OUT)
setAsan:
				$(eval OPTION = $(ASAN_OPTION))
				$(eval SUFFIX = $(A_SUFFIX))

clean:
				$(RMDIR) $(BUILDDIR)
				$(RM) main.o
fclean:			clean
				$(RM) $(OUTS)
re:				fclean all



$(BUILDDIRS):
				$(MKDIR) $@

$(OUTS):		main.o $(OBJS)
				$(LINK) -o $@ $^ $(OPTION)

main.o:			main.c
				$(COMPILE) -c $< -o $@ $(OPTION)
$(OBJS):		$(BUILDDIR)/%.o: $(PROJDIR)/%.c
				$(COMPILE) -c $< -o $@ $(OPTION)
