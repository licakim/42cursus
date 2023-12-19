CXX = c++
CXXFLAGS=  -std=c++98 -Wall -Wextra -Werror
SRCS = Zombie.cpp zombieHorde.cpp main.cpp
DEPS = Zombie.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = zombie

.INTERMEDIATE : $(OBJS)

all: $(NAME)

$(NAME) : $(OBJS) $(DEPS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o ${NAME}

clean : 
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re