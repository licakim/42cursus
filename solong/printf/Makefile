CC=cc
CFLAGS=-Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
SRCS= ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJS=$(SRCS:.c=.o)
NAME=libftprintf.a

.INTERMEDIATE : $(OBJS)
.PHONY: all re clean fclean

all: $(NAME)
	
$(NAME) : $(NAME)($(OBJS))

$(OBJS) : ft_printf.h

clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
