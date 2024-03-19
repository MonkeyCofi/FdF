/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/19 17:07:49 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parallel(t_mlx *mlx)
{
	int		height;
	int		width;
	float	**matrix;
	float	centers[3];

	height = mlx->map->height;
	width = mlx->map->width;
	if (mlx->points)
		free(mlx->points);
	mlx->points = return_array(mlx, height, width, mlx->camera->zoom);
	centers[0] = mlx->points[height / 2][width / 2][0];
	centers[1] = mlx->points[height / 2][width / 2][2];
	centers[2] = mlx->points[height / 2][width / 2][1];
	move_to_origin(mlx);
	matrix = return_matrix('x', -5 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	move_shape_back(mlx, centers[0], centers[2], centers[1]);
	draw_image(mlx);
}

int	get_key_pressed(int k, t_mlx *mlx, int scale)
{
	if (k == ESC)
		escape(mlx);
	else if (k == Q || k == W || k == E || k == A || k == S || k == D)
		rotate_shape(mlx, k);
	else if (k == R)
		reset(mlx);
	else if (k == PLUS || k == MINUS)
		zoom((t_mlx *)mlx, scale, k);
	else if (k == B || k == P || k == G || k == Y)
	{
		if (k == P)
			mlx->current_color = 255 << 16 | 255;
		else if (k == Y)
			mlx->current_color = 255 << 16 | 255 << 8;
		else if (k == B)
			mlx->current_color = 255 << 8 | 255;
		else if (k == G)
			mlx->current_color = 255 << 8;
		if (mlx->bon)
			mlx->bon = 0;
		else
			mlx->bon = 1;
	}
	else if (k == 99)
		parallel(mlx);
	else
		translate(mlx, k);
	ft_printf("Keycode: %d\n", k);
	return (0);
}

void	rotate_shape(t_mlx *mlx, int keycode)
{
	float			axes[3];
	float			**matrix;

	axes[0] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][0];
	axes[1] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][2];
	axes[2] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][1];
	move_to_origin(mlx);
	matrix = NULL;
	if (keycode == W)
		matrix = return_matrix('x', -4 * (3.1415 / 180));
	else if (keycode == S)
		matrix = return_matrix('x', 4 * (3.1415 / 180));
	else if (keycode == A)
		matrix = return_matrix('y', 4 * (3.1415 / 180));
	else if (keycode == D)
		matrix = return_matrix('y', -4 * (3.1415 / 180));
	else if (keycode == Q)
		matrix = return_matrix('z', 4 * (3.1415 / 180));
	else if (keycode == E)
		matrix = return_matrix('z', -4 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, \
		mlx->map->height, mlx->map->width);
	free_matrix(matrix);
	move_shape_back(mlx, axes[0], axes[1], axes[2]);
	draw_image(mlx);
}

int	translate(t_mlx *mlx, int keycode)
{
	if (keycode == UP)
		move_points(mlx, 0);
	else if (keycode == DOWN)
		move_points(mlx, 1);
	else if (keycode == RIGHT)
		move_points(mlx, 2);
	else if (keycode == LEFT)
		move_points(mlx, 3);
	draw_image(mlx);
	return (0);
}

int	escape(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_window);
	free(mlx->camera);
	free_triple_int(mlx, mlx->map->z_coord);
	free_points(mlx, mlx->points);
	free_triple_int(mlx, mlx->def_color);
	free(mlx->map);
	exit(EXIT_SUCCESS);
}
