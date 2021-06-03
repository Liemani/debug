PROJNAME	= $(shell basename $(CURDIR))



GITDIR		= $(realpath $(CURDIR)/../..)
SEOUL42DIR		= $(GITDIR)/seoul42_project
PROJDIR				= $(SEOUL42DIR)/$(PROJNAME)
DEBUGDIR		= $(GITDIR)/debug
BUILDDIR				= $(CURDIR)/build
ABSTRACT_BUILDDIRS		= \
						  . \
						  value_type \
						  object \
						  core \
						  util \
						  t_bmp \
						  set_model
BUILDDIRS				= $(patsubst %,$(BUILDDIR)/%,$(ABSTRACT_BUILDDIRS))

ABSTRACT_SRCS	= \
				  util/util.c \
				  util/endian.c \
				  core/t_mlx.c \
				  core/t_window.c \
				  core/t_image.c \
				  core/t_scene.c \
				  core/t_camera.c \
				  value_type/t_vector2.c \
				  value_type/t_vector2i.c \
				  value_type/t_vector3.c \
				  value_type/t_matrix3.c \
				  value_type/t_rgb192.c \
				  value_type/t_rgb32.c \
				  object/t_geometry.c \
				  object/t_light.c \
				  object/t_ray.c \
				  object/t_sphere.c \
				  object/t_plane.c \
				  object/t_square.c \
				  object/t_triangle.c \
				  object/t_circle.c \
				  object/t_cylinder_body.c \
				  object/t_cylinder.c \
				  t_bmp/t_bmp.c \
				  set_model/set_model.c \
				  set_model/get_line.c \
				  t_application.c \
				  hook.c
SRCS			= $(patsubst %,$(BUILDDIR)/%,$(ABSTRACT_SRCS))
OBJS			= $(SRCS:.c=.o)

# DIR_TO_INCLUDE = value_type \

ABSTRACT_INCLUDE = \
				   . \
				   value_type \
				   object \
				   core \
				   libft \
				   util \
				   t_bmp \
				   set_model
INCLUDE = $(patsubst %,-I $(PROJDIR)/%,$(ABSTRACT_INCLUDE))

CC = clang
CFLAGS = -w -Wall -Wextra -Werror
LIBRARY = -L $(PROJDIR)/libft -l ft \
		  -l mlx -framework OpenGL -framework AppKit
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
				$(RMDIR) $(BUILDDIR)
				$(RM) main.o describe.o
				$(RM) $(OUTS)
fclean:			clean
re:				fclean all



$(BUILDDIRS):
				$(MKDIR) $@

$(OUTS):		main.o describe.o $(OBJS)
				$(LINK) -o $@ $^ $(OPTION)

main.o:			main.c
				$(COMPILE) -c $< -o $@ $(OPTION)
describe.o:		describe.c
				$(COMPILE) -c $< -o $@ $(OPTION)
$(OBJS):		$(BUILDDIR)/%.o: $(PROJDIR)/%.c
				@$(COMPILE) -c $< -o $@ $(OPTION)
