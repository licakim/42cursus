CC=cc
CFLAGS=-Wall -Wextra -Werror
MFLAGS= -framework OpenGL -framework AppKit
AR = ar
ARFLAGS = crs

SRCS= dfs.c solong.c move.c map.c utils.c print.c
OBJS=$(SRCS:.c=.o)

FT_DIR	= ./libft
GNL_DIR	= ./gnl	
PRINTF_DIR = ./printf
MLX_DIR = ./mlx_opengl
FT = ft
GNL = ftgnl
PRINTF = ftprintf
MLX = mlx
NAME=so_long

.INTERMEDIATE : $(OBJS)
.PHONY: all re clean fclean libft

all: $(NAME)
	
$(NAME) : $(OBJS)
	$(MAKE) -C $(FT_DIR)
	$(MAKE) -C $(GNL_DIR) && \
	$(MAKE) -C $(PRINTF_DIR) && \
	$(MAKE) -C $(MLX_DIR) && \
	$(CC) $(CFLAGS) \
		-L$(FT_DIR) -l$(FT) \
		-L$(GNL_DIR) -l$(GNL) \
		-L$(PRINTF_DIR) -l$(PRINTF) \
		-L$(MLX_DIR) -l$(MLX) $(MFLAGS) \
		$(SRCS) -o $(NAME)

$(OBJS) : solong.h

clean :
	$(MAKE) clean -C $(FT_DIR)
	$(MAKE) clean -C $(GNL_DIR) 
	$(MAKE) clean -C $(PRINTF_DIR) 
	$(MAKE) clean -C $(MLX_DIR) 
	rm -f $(OBJS)
	
fclean : clean
	$(MAKE) fclean -C $(FT_DIR)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re : fclean
	$(MAKE) all
