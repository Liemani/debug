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
				  large_scale_search/t_buffer.c \
				  large_scale_search/t_circular_list.c \
				  large_scale_search/t_node_lss.c \
				  large_scale_search/instruction_lss.c \
				  util.c
SRCS			= $(addprefix  $(PROJDIR),$(ABSTRACT_SRCS))
OBJS			= $(SRCS:.c=.o)

PROJ_INCLUDE = \
			   . \
			   $(LIBFT) \
			   bfs \
			   large_scale_search
ABSTRACT_INCLUDE = \
				   $(patsubst %,$(PROJDIR)/%,$(PROJ_INCLUDE)) \
				   $(DEBUGDIR)

INCLUDE = \
		  $(patsubst %,-I %,$(ABSTRACT_INCLUDE)) \

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



.PHONY:			all debug pre_debug asan setAsan clean fclean re
all:			$(BUILDDIRS) $(M_OUT)

debug:			clean pre_debug push_swap checker
pre_debug:
				make -C $(PROJDIR) debug

asan:			setAsan $(BUILDDIRS) $(A_OUT)
setAsan:
				$(eval OPTION = $(ASAN_OPTION))

clean:
				$(RM) push_swap checker
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
push_swap:
				cp $(PROJDIR)/push_swap .
checker:
				cp $(PROJDIR)/checker .
