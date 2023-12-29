/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:45:31 by pipolint          #+#    #+#             */
/*   Updated: 2023/12/29 16:12:45 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_square(t_data *img, int x, int y, int height, int width, int color)
{
	int height_i;
	int	width_j;

	height_i = 0;
	while (height_i < height + y)
	{
		width_j = x;
		while (width_j < width + x)
		{
			pixel_put(img, width_j++, height_i, color);
		}
		height_i++;
	}
}

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
	(void)mlx;
	ft_printf("%d\n", keycode);
	return (0);
}

int main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		return (-1);
	mlx = init_mlx();
	init_map(&mlx);
	parse_map(mlx->map, av[1]);
	mlx_key_hook(mlx->mlx_window, keypress, &mlx->mlx);
	mlx_loop(mlx->mlx);
	free(mlx->mlx);
}