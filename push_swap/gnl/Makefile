CC=cc
CFLAGS=-Wall -Wextra -Werror
AR = ar
ARFLAGS = crs
SRCS= get_next_line.c get_next_line_utils.c 
OBJS=$(SRCS:.c=.o)
NAME=libftgnl.a

.INTERMEDIATE : $(OBJS)
.PHONY: all re clean fclean

all: $(NAME)
	
$(NAME) : $(NAME)($(OBJS))

$(OBJS) : get_next_line.h

clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)

re : fclean
	$(MAKE) all
