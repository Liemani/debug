PROJNAME            = $(shell basename $(CURDIR))
NAME				:= test



GITDIR              = $(realpath $(CURDIR)/../../..)
PROJDIR                 = $(GITDIR)/$(PROJNAME)
DEBUGDIR                = $(GITDIR)/debug



ABSTRACT_SRCS       = \
                      FTServer.cpp\
                      Log.cpp\
					  EventHandler.cpp\
					  EventContext.cpp\
                      VirtualServerConfig.cpp\
                      LocationConfig.cpp\
                      VirtualServer.cpp\
                      Location.cpp\
                      Connection.cpp\
                      Request.cpp\
                      Response.cpp

SRCS				:= $(addprefix $(CURDIR)/,$(ABSTRACT_SRCS))
OBJS				:= $(SRCS:.cpp=.o)

PROJ_INCLUDE        = \
                      .

ABSTRACT_INCLUDE    = $(patsubst %,$(PROJDIR)/%,$(PROJ_INCLUDE))\
                      $(DEBUGDIR)

INCLUDE				:= $(patsubst %,-I %,$(ABSTRACT_INCLUDE))

DEBUG_OPTION		= -D NDEBUG

LIBRARY				:=

CXX					:= c++
CXXFLAGS			:= -std=c++98 -Wall -Wextra -Werror

COMPILE				= $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION)
LINK				= $(CXX) $(CXXFLAGS) $(INCLUDE) $(DEBUG_OPTION) $(LIBRARY)

RM					:= rm -f



.PHONY:				all debug setdebug clean fclean re
all:				$(NAME)

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

$(OBJS):            $(CURDIR)/%.o: $(PROJDIR)/%.cpp
					$(COMPILE) -o $@ -c $<

