CC=cc
CFLAGS= -Wall -Wextra -Werror

SRCS = philo.c ft_atoi.c

OBJS=$(SRCS:.c=.o)

NAME = philo

.INTERMEDIATE : $(OBJS)
.PHONY: all re clean fclean

all: $(NAME)
	
$(NAME) : $(OBJS)
		$(OBJS) -o $(NAME)

$(OBJS) : philo.h

clean : rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
