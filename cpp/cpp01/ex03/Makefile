CXX = c++
CXXFLAGS=  -std=c++98 -Wall -Wextra -Werror
SRCS = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
DEPS = Weapon.hpp HumanA.hpp HumanB.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = weapon

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