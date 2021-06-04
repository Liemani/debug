PROJNAME	= $(shell basename $(CURDIR))
LIBFT		= libft



GITDIR		= $(realpath $(CURDIR)/../..)
SEOUL42DIR		= $(GITDIR)/seoul42_project
PROJDIR				= $(SEOUL42DIR)/$(PROJNAME)
DEBUGDIR		= $(GITDIR)/debug



SRCS			= main.c
OBJS			= $(SRCS:.c=.o)

PROJ_INCLUDE = \
			   .
INCLUDE = $(patsubst %,-I $(PROJDIR)/%,$(PROJ_INCLUDE)) \
		  -I $(DEBUGDIR)

LIBRARY = -L $(PROJDIR) -l $(patsubst lib%,%,$(LIBFT))

CC = clang
CFLAGS = -w -Wall -Wextra -Werror
DEBUG_OPTION = -g
ASAN_OPTION = -g3 -fsanitize=address

COMPILE = $(CC) $(CFLAGS) $(INCLUDE)
LINK = $(CC) $(INCLUDE) $(LIBRARY)

RM = rm -f



M_OUT	= $(PROJNAME)_mandatory.out
D_OUT	= $(PROJNAME)_debug.out
A_OUT	= $(PROJNAME)_asan.out
OUTS	= $(M_OUT) $(D_OUT) $(A_OUT)



.PHONY:			all debug setDebug asan setAsan clean fclean re
all:			$(M_OUT)

debug:			clean setDebug $(D_OUT)
setDebug:
				$(eval OPTION = $(DEBUG_OPTION))

asan:			setAsan $(A_OUT)
setAsan:
				$(eval OPTION = $(ASAN_OPTION))

clean:
				$(RM) $(OBJS)
fclean:			clean
				$(RM) $(OUTS)
				make -C $(PROJDIR) fclean
re:				fclean all



$(OUTS):		$(PROJDIR)/$(LIBFT).a $(OBJS)
				$(LINK) -o $@ $^ $(OPTION)

$(PROJDIR)/$(LIBFT).a:
				make -C $(PROJDIR) bonus

%.o:			%.c
				$(COMPILE) -c $< -o $@ $(OPTION)
