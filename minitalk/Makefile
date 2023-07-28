CC=cc
CFLAGS= -Wall -Wextra -Werror

SRCS_SV = server.c 
SRCS_CN = client.c

OBJS_SV=$(SRCS_SV:.c=.o)
OBJS_CN=$(SRCS_CN:.c=.o)


PRINTF_DIR = ./printf
PRINTF = ftprintf

.INTERMEDIATE : $(OBJS_SV) $(OBJS_CN)
.PHONY: all re clean fclean

NAME_SV = server
NAME_CN = client

all: $(NAME_SV) $(NAME_CN)

$(NAME_SV) : $(OBJS_SV)
	$(MAKE) -C $(PRINTF_DIR) && \
	$(CC) $(CFLAGS) \
		-L$(PRINTF_DIR) -l$(PRINTF) \
		$(OBJS_SV) -o $(NAME_SV)

$(NAME_CN) : $(OBJS_CN)
	$(MAKE) -C $(PRINTF_DIR) && \
	$(CC) $(CFLAGS) \
		-L$(PRINTF_DIR) -l$(PRINTF) \
		$(OBJS_CN) -o $(NAME_CN)

$(OBJS_SV) : server.h
$(OBJS_CN) : client.h

clean :
	$(MAKE) clean -C $(PRINTF_DIR) 
	rm -f $(OBJS_CN) $(OBJS_SV)
	
fclean : clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME_CN) $(NAME_SV)

re : fclean
	$(MAKE) all

