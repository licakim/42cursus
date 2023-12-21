CXX = c++
CXXFLAGS=  -std=c++98 -Wall -Wextra -Werror
SRCS = Harl.cpp main.cpp
DEPS = Harl.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = harl

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