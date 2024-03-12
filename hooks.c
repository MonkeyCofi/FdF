/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/12 19:55:06 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// reset the shape to standard projection
void	reset(t_mlx *mlx, int scale)
{
	if (mlx->points)
		free(mlx->points);
	mlx->points = return_array(mlx, mlx->map->height, mlx->map->width, mlx->camera->zoom);
	if (mlx->camera)
		free(mlx->camera);
	init_camera(mlx);
	draw_image(mlx);
	(void)scale;
}

int	get_key_pressed(int keycode, t_mlx *mlx, int scale)
{
	if (keycode == 53 || keycode == 65307)
		escape(mlx);
	else if (keycode == Q || keycode == W || keycode == E || keycode == A || keycode == S || keycode == D)
		rotate_shape(mlx, keycode);
	else if (keycode == R)
		reset(mlx, scale);	
	else if (keycode == PLUS || keycode == MINUS)
		zoom((t_mlx *)mlx, scale, keycode);
	else
		translate(mlx, keycode);
	ft_printf("Key pressed: %d\n", keycode);
	return (0);
}

void	move_to_origin(t_mlx *mlx)
{
	float	x1;
	float	y1;
	float	z1;
	int		i;
	int		j;

	x1 = round(mlx->points[mlx->map->height / 2][mlx->map->width / 2][0]);
	y1 = round(mlx->points[mlx->map->height / 2][mlx->map->width / 2][2]);
	z1 = round(mlx->points[mlx->map->height / 2][mlx->map->width / 2][1]);
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

	axes[0] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][0];
	axes[1] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][2];
	axes[2] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][1];
	if (keycode == W)
	{
		move_to_origin(mlx);
		apply_transformation(mlx->points, return_matrix('x', -4 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, axes[0], axes[1], axes[2]);
	}
	else if (keycode == S)
	{
		move_to_origin(mlx);	
		apply_transformation(mlx->points, return_matrix('x', 4 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, axes[0], axes[1], axes[2]);
	}
	else if (keycode == A)
	{
		move_to_origin(mlx);	
		apply_transformation(mlx->points, return_matrix('y', 4 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, axes[0], axes[1], axes[2]);
	}
	else if (keycode == D)
	{
		move_to_origin(mlx);	
		apply_transformation(mlx->points, return_matrix('y', -4 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, axes[0], axes[1], axes[2]);
	}
	else if (keycode == Q)
	{
		move_to_origin(mlx);
		apply_transformation(mlx->points, return_matrix('z', 4 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, axes[0], axes[1], axes[2]);
	}
	else if (keycode == E)
	{
		move_to_origin(mlx);
		apply_transformation(mlx->points, return_matrix('z', -4 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, axes[0], axes[1], axes[2]);
	}
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
	if (keycode == 65362 || keycode == UP)
		move_points(mlx, 0);
	else if (keycode == 65364 || keycode == DOWN)
		move_points(mlx, 1);
	else if (keycode == 65363 || keycode == RIGHT)
		move_points(mlx, 2);
	else if (keycode == 65361 || keycode == LEFT)
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

