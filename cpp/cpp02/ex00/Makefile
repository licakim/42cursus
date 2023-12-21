CXX = c++
CXXFLAGS=  -std=c++98 -Wall -Wextra -Werror
SRCS = Fixed.cpp main.cpp
DEPS = Fixed.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = ex00

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