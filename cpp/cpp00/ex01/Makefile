CXX = c++
CXXFLAGS=  -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Contact.cpp PhoneBook.cpp
DEPS = Contact.hpp PhoneBook.hpp
OBJS = $(SRCS:.cpp=.o)

NAME = phonebook

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