PROJNAME            = $(shell basename $(CURDIR))
NAME				:= test



GITDIR              = $(realpath $(CURDIR)/../../..)
PROJDIR                 = $(GITDIR)/$(PROJNAME)
DEBUGDIR                = $(GITDIR)/debug



ABSTRACT_SRCS       = \
                      Connection.cpp\
                      FTServer.cpp\
                      Location.cpp\
                      LocationConfig.cpp\
                      Log.cpp\
                      Request.cpp\
                      Response.cpp\
                      VirtualServer.cpp\
                      VirtualServerConfig.cpp

SRCS				:= $(addprefix $(PROJDIR)/,$(ABSTRACT_SRCS))
OBJS				:= $(SRCS:.cpp=.o)

PROJ_INCLUDE        = \
                      .

ABSTRACT_INCLUDE    = $(patsubst %,$(PROJDIR)/%,$(PROJ_INCLUDE))\
                      $(DEBUGDIR)

INCLUDE				:= $(patsubst %,-I %,$(ABSTRACT_INCLUDE))

LIBRARY				:=

CXX					:= c++
CXXFLAGS			:= -std=c++98 -Wall -Wextra -Werror

COMPILE				= $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION)
LINK				= $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM					:= rm -f



.PHONY:				all debug setdebug clean fclean re
all:				debug

debug:				clean setdebug $(NAME)
setdebug:
					$(eval DEBUG_OPTION = -g)

clean:
					$(RM) $(OBJS) test.o
fclean:				clean
					$(RM) $(NAME)
re:					fclean all

echo:
					@echo CURDIR: $(CURDIR)
					@echo GITDIR: $(GITDIR)



$(NAME):			test.o $(OBJS)
					$(LINK) -o $@ $^

test.o:             %.o: %.cpp
					$(COMPILE) -o $@ -c $<

$(OBJS):            %.o: %.cpp
					make -C $(PROJDIR)
