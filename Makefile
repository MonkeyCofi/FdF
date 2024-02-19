CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = fdf.c parse.c init.c ft_atoi_base.c draw.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

LIBFT = libft.a

LIBFT_DIR = ./libft/

OS_NAME=$(shell uname)

MLXOS = minilibx-linux

# MLX = mlx

$(NAME): $(OBJS)
	# make -C $(MLX)
	make -C $(MLXOS)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBFT_DIR)$(LIBFT) -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c $< -o $@

all: $(NAME)

# ifeq (${OS},Darwin)
#
# MLXOS = minilibx
#
# all: $(NAME)
# 	make -C $(MLX)
# 	make -C $(MLXOS)
# 	make -C $(LIBFT_DIR)
# 	$(CC) -Lmlx -lmlx -framework OpenGL -framework Appkit $(LIBFT_DIR)$(LIBFT) $(OBJS) -o $(NAME)
#
# $(NAME): $(OBJS)
#
# %.o: %.c
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#
# else
# MLXOS = minilibx_linux
#
# all: $(NAME)
# 	make -C $(MLXOS)
# 	make -C $(LIBFT_DIR)
# 	$(CC) $(OBJS) $(LIBFT_DIR)$(LIBFT) -Lminilibx-linux -lminilibx-linux -L/usr/lib -Iminilibx-linux -IXext -IX11 -lm -lz -o $(NAME)
#
# $(NAME): $(OBJS)
#
# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Iminilibx-linux -O3 -c $< -o $@
#
# endif

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
