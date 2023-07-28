CC=cc
CFLAGS= -Wall -Wextra -Werror
AR = ar
ARFLAGS = crs

SRCS= push_swap.c sort_small_num.c push_a.c a_to_b.c move_min.c check_count.c \
		b_to_a.c add_delete_dq.c command1.c command2.c command3.c utils.c
SRCS_BN= ./bonus/push_swap_bonus.c ./bonus/command1_bonus.c ./bonus/command2_bonus.c ./bonus/command3_bonus.c \
		./bonus/add_delete_dq_bonus.c ./bonus/push_a_bonus.c ./bonus/utils_bonus.c
OBJS=$(SRCS:.c=.o)
OBJS_BN=$(SRCS_BN:.c=.o)

FT_DIR	= ./libft
PRINTF_DIR = ./printf
GNL_DIR	= ./gnl	
FT = ft
PRINTF = ftprintf
GNL = ftgnl
NAME = push_swap
NAME_BN=checker

.INTERMEDIATE : $(OBJS) $(OBJS_BN)
.PHONY: all re clean fclean libft 

all: $(NAME)
	
$(NAME) : $(OBJS)
	$(MAKE) -C $(FT_DIR)
	$(MAKE) -C $(PRINTF_DIR) && \
	$(MAKE) -C $(GNL_DIR) && \
	$(CC) $(CFLAGS) \
		-L$(FT_DIR) -l$(FT) \
		-L$(PRINTF_DIR) -l$(PRINTF) \
		-L$(GNL_DIR) -l$(GNL) \
		$(OBJS) -o $(NAME)

bonus : $(NAME_BN)

$(NAME_BN): $(OBJS_BN)
	$(MAKE) -C $(FT_DIR)
	$(MAKE) -C $(PRINTF_DIR) && \
	$(MAKE) -C $(GNL_DIR) && \
	$(CC) $(CFLAGS) \
		-L$(FT_DIR) -l$(FT) \
		-L$(PRINTF_DIR) -l$(PRINTF) \
		-L$(GNL_DIR) -l$(GNL) \
		$(OBJS_BN) -o $(NAME_BN)

$(OBJS) : push_swap.h
$(OBJS_BN) : ./bonus/push_swap_bonus.h

clean :
	$(MAKE) clean -C $(FT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR) 
	$(MAKE) clean -C $(GNL_DIR) 
	rm -f $(OBJS) $(OBJS_BN)
	
fclean : clean
	$(MAKE) fclean -C $(FT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(MAKE) fclean -C $(GNL_DIR) 
	rm -f $(NAME) $(NAME_BN)

re : fclean
	$(MAKE) all
