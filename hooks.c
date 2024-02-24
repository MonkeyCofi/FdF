/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/24 21:32:29 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     draw_image(t_mlx *mlx)
{
        if (mlx->img.img)
                mlx_destroy_image(mlx->mlx, mlx->img.img);
        mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
        mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
        draw(mlx);
        return (0);
}

int	get_key_pressed(int keycode, t_mlx *mlx, int scale)
{
	if (keycode == 53 || keycode == 65307)
		escape(mlx);
	else if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		rotate_shape(mlx, keycode);
	else
		translate(mlx, keycode);
	(void)scale;
	ft_printf("Key pressed: %d\n", keycode);
	return (0);
}

void	rotate_shape(t_mlx *mlx, int keycode)
{
	float	angle;
	// w=119
	// a=97
	// s=115
	// d=100
	angle = 0.01;
	if (keycode == 119 || keycode == 1)
		apply_transformation(mlx->points, return_matrix('z', 1 * 3.1415), mlx->map->height, mlx->map->width);
	draw_image(mlx);
}

void	move_points(t_mlx *mlx, int position)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			if (position == 0)
				mlx->points[i][j][2] -= 15;
			else if (position == 1)
				mlx->points[i][j][2] += 15;
			else if (position == 2)
				mlx->points[i][j][0] += 15;
			else if (position == 3)
				mlx->points[i][j][0] -= 15;
		}
	}
}

// currently only for linux
int	translate(t_mlx *mlx, int keycode)
{
	// up: 65362
	// left: 65361
	// down: 65364
	// right: 65363
	if (keycode == 65362 || keycode == 126)
		move_points(mlx, 0);
	else if (keycode == 65364 || keycode == 125)
		move_points(mlx, 1);
	else if (keycode == 65363 || keycode == 124)
		move_points(mlx, 2);
	else if (keycode == 65361 || keycode == 123)
		move_points(mlx, 3);
	draw_image(mlx);
	return (0);
}

int	escape(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_window);
	exit(EXIT_SUCCESS);
	return (0);
}

