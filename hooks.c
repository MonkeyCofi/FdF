/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/14 21:04:07 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_mlx *mlx)
{
	if (mlx->points)
		free(mlx->points);
	mlx->points = return_array(mlx, mlx->map->height, mlx->map->width, mlx->camera->zoom);
	if (mlx->camera)
		free(mlx->camera);
	init_camera(mlx);
	get_default_position(mlx, mlx->points);
	draw_image(mlx);
}

void	parallel(t_mlx *mlx)
{
	if (mlx->points)
		free(mlx->points);	
	mlx->points = return_array(mlx, mlx->map->height, mlx->map->width, mlx->camera->zoom);
	float x, y, z;
	x = mlx->points[mlx->map->height / 2][mlx->map->width / 2][0];
	y = mlx->points[mlx->map->height / 2][mlx->map->width / 2][2];
	z = mlx->points[mlx->map->height / 2][mlx->map->width / 2][1];
	move_to_origin(mlx);
	apply_transformation(mlx->points, return_matrix('x', -5 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
	move_shape_back(mlx, x, y, z);
	draw_image(mlx);
}

int	get_key_pressed(int keycode, t_mlx *mlx, int scale)
{
	if (keycode == ESC)
		escape(mlx);
	else if (keycode == Q || keycode == W || keycode == E || keycode == A || keycode == S || keycode == D)
		rotate_shape(mlx, keycode);
	else if (keycode == R)
		reset(mlx);	
	else if (keycode == PLUS || keycode == MINUS)
		zoom((t_mlx *)mlx, scale, keycode);
	else if (keycode == B || keycode == P || keycode == G || keycode == Y)
	{
		if (keycode == P)
			mlx->current_color = 255 << 16 | 255;
		else if (keycode == Y)
			mlx->current_color = 255 << 16 | 255 << 8;
		else if (keycode == B)
			mlx->current_color = 255 << 8 | 255;			//blue
		else if (keycode == G)
			mlx->current_color = 255 << 8;
		if (mlx->bon)
			mlx->bon = 0;
		else
			mlx->bon = 1;
	}
	else if (keycode == 99)
	{
		parallel(mlx);
	}
	else
		translate(mlx, keycode);
	ft_printf("Keycode: %d\n", keycode);
	return (0);
}

void	move_to_origin(t_mlx *mlx)
{
	float	x1;
	float	y1;
	float	z1;
	int		i;
	int		j;

	x1 = mlx->points[mlx->map->height / 2][mlx->map->width / 2][0];
	y1 = mlx->points[mlx->map->height / 2][mlx->map->width / 2][2];
	z1 = mlx->points[mlx->map->height / 2][mlx->map->width / 2][1];
	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			mlx->points[i][j][0] -= x1;
			mlx->points[i][j][1] -= z1;
			mlx->points[i][j][2] -= y1;
		}
	}
}

void	move_shape_back(t_mlx *mlx, float x_cent, float y_cent, float z_cent)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			mlx->points[i][j][0] += x_cent;
			mlx->points[i][j][1] += z_cent;
			mlx->points[i][j][2] += y_cent;
		}
	}
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
	{
		matrix = return_matrix('x', -4 * (3.1415 / 180));
		apply_transformation(mlx->points, matrix, mlx->map->height, mlx->map->width);
	}
	else if (keycode == S)
	{
		matrix = return_matrix('x', 4 * (3.1415 / 180));
		apply_transformation(mlx->points,matrix, mlx->map->height, mlx->map->width);
	}
	else if (keycode == A)
	{
		matrix = return_matrix('y', 4 * (3.1415 / 180));
		apply_transformation(mlx->points,matrix, mlx->map->height, mlx->map->width);
	}
	else if (keycode == D)
	{
		matrix = return_matrix('y', -4 * (3.1415 / 180));
		apply_transformation(mlx->points, matrix, mlx->map->height, mlx->map->width);
	}
	else if (keycode == Q)
	{
		matrix = return_matrix('z', 4 * (3.1415 / 180));
		apply_transformation(mlx->points,matrix, mlx->map->height, mlx->map->width);
	}
	else if (keycode == E)
	{
		matrix = return_matrix('z', -4 * (3.1415 / 180));
		apply_transformation(mlx->points, matrix, mlx->map->height, mlx->map->width);
	}
	if (matrix)
	{
		for (int i = 0; i < 3; i++)
			free(matrix[i]);
		free(matrix);
	}
	move_shape_back(mlx, axes[0], axes[1], axes[2]);
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
			if (position == Up)
				mlx->points[i][j][2] -= 15;
			else if (position == Down)
				mlx->points[i][j][2] += 15;
			else if (position == Right)
				mlx->points[i][j][0] += 15;
			else if (position == Left)
				mlx->points[i][j][0] -= 15;
		}
	}
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
	for (int i = 0; i < mlx->map->height; i++)
	{
		for (int j = 0; j < mlx->map->width; j++)
			free(mlx->map->z_coord[i][j]);
		free(mlx->map->z_coord[i]);
	}
	free(mlx->map->z_coord);
	free(mlx->map);
	free(mlx->points);
	exit(EXIT_SUCCESS);
}

