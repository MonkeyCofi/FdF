CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = fdf.c parse.c init.c ft_atoi_base.c draw.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

MLX = mlx

MLXOS = minilibx

LIBFT = libft.a

LIBFT_DIR = ./libft/

all: $(NAME)
	make -C $(MLX)
	make -C $(MLXOS)
	make -C $(LIBFT_DIR)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework Appkit $(LIBFT_DIR)$(LIBFT) $(OBJS) -o $(NAME)

$(NAME): $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(MLX)/*.o
	rm -rf $(MLXOS)/*.o
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIBFT_DIR)$(LIBFT)
	rm -rf $(MLX)/libmlx.a
	rm -rf $(MLX)/font.xcf
	rm -rf $(MLXOS)/*.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re