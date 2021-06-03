PROJNAME	= $(shell basename $(CURDIR))
LIBFT		= libft



GITDIR		= $(realpath $(CURDIR)/../..)
SEOUL42DIR		= $(GITDIR)/seoul42_project
PROJDIR				= $(SEOUL42DIR)/$(PROJNAME)
DEBUGDIR		= $(GITDIR)/debug



ABSTRACT_SRCS	= \
				  bfs/t_bfs.c \
				  bfs/t_branch.c \
				  bfs/t_node_bfs.c \
				  bfs/t_queue.c \
				  bfs/instruction_bfs.c \
				  large_scale_search/t_lss.c \
				  large_scale_search/t_circular_list.c \
				  large_scale_search/t_node_lss.c \
				  large_scale_search/instruction_lss.c \
				  util.c
SRCS			= $(patsubst %,$(PROJDIR)/%,$(ABSTRACT_SRCS))
OBJS			= $(SRCS:.c=.o)

ABSTRACT_INCLUDE = \
				   . \
				   $(LIBFT) \
				   bfs \
				   large_scale_search
INCLUDE = $(patsubst %,-I $(PROJDIR)/%,$(ABSTRACT_INCLUDE))

LIBRARY = -L $(PROJDIR)/libft -l $(patsubst lib%,%,$(LIBFT))

CC = clang
CFLAGS = -w -Wall -Wextra -Werror
DEBUG_OPTION = -g
ASAN_OPTION = -g3 -fsanitize=address

COMPILE = $(CC) $(CFLAGS) $(INCLUDE)
LINK = $(CC) $(INCLUDE) $(LIBRARY)

RM = rm -f
RMDIR = rm -rf
MKDIR = mkdir -p



M_OUT	= $(PROJNAME)_mandatory.out
D_OUT	= $(PROJNAME)_debug.out
A_OUT	= $(PROJNAME)_asan.out
OUTS	= $(M_OUT) $(D_OUT) $(A_OUT)



.PHONY:			all debug setDebug asan setAsan clean fclean re
all:			$(BUILDDIRS) $(M_OUT)

debug:			clean setDebug $(BUILDDIRS) $(D_OUT)
setDebug:
				$(eval OPTION = $(DEBUG_OPTION))

asan:			setAsan $(BUILDDIRS) $(A_OUT)
setAsan:
				$(eval OPTION = $(ASAN_OPTION))

clean:
				$(RM) main.o describe.o
				$(RM) $(OUTS)
				make -C $(PROJDIR) clean
fclean:			clean
				make -C $(PROJDIR) fclean
re:				fclean all



$(OUTS):		main.o describe.o $(OBJS)
				$(LINK) -o $@ $^ $(OPTION)

main.o:			main.c
				$(COMPILE) -c $< -o $@ $(OPTION)
describe.o:		describe.c
				$(COMPILE) -c $< -o $@ $(OPTION)
$(OBJS):
				make -C $(PROJDIR) debug
