CC=cc
CFLAGS= -Wall -Wextra -Werror -g3 -fsanitize=thread

SRCS = philo.c ft_atoi.c init.c monitoring.c print_state.c simulate.c utils.c

OBJS=$(SRCS:.c=.o)

NAME = philo

.INTERMEDIATE : $(OBJS)
.PHONY: all re clean fclean

all: $(NAME)
	
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS)	$(OBJS) -o $(NAME)

$(OBJS) : philo.h

clean : 
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
