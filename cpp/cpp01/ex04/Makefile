CXX = c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = brain

.INTERMEDIATE : $(OBJS)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o ${NAME}

clean : 
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re