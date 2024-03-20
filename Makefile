CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = fdf.c parse.c init.c ft_atoi_base.c draw.c matrix.c hooks.c \
	   colors.c transform.c check_map.c utils.c spin.c \
	   frees.c colors2.c hook_utils.c extra_proj.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

LIBFT = libft.a

LIBFT_DIR = ./libft/

OS_NAME=$(shell uname)

ifeq ($(OS_NAME), Linux)
MLXOS = minilibx-linux
MLXFLAGS = -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
MLXOBJ =  -Wall -Wextra -Werror -I/usr/include -Iminilibx-linux -O3 -c

else
MLXOS = mlx
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLXOBJ = -Wall -Wextra -Werror -Imlx -c
endif

$(NAME): $(OBJS)
	make -C $(MLXOS)
	make -C $(LIBFT_DIR)
	$(CC) $(OBJS) $(LIBFT_DIR)$(LIBFT) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(MLXOBJ) $< -o $@

all: $(NAME)

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
