/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_proj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:39:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/20 21:40:22 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_center(t_mlx *mlx, float x, float y, float z)
{
	int	i;
	int	j;
	int	out;

	i = -1;
	out = 0;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			mlx->points[i][j][0] += x + (WIDTH / 3);
			mlx->points[i][j][2] += y + (HEIGHT / 3);
			if (mlx->points[i][j][2] > HEIGHT) 
				out = 1;
		}
	}
	if (!out)
		return ;
	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
			mlx->points[i][j][2] -= 200;
	}
	(void)z;
}

void	top_down(t_mlx *mlx)
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
	matrix = return_matrix('x', 0 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	move_center(mlx, centers[0], centers[1], centers[2]);
	draw_image(mlx);
}

void	side_view(t_mlx *mlx)
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
	matrix = return_matrix('x', -90 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	matrix = return_matrix('z', 90 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	move_center(mlx, centers[0], centers[1], centers[2]);
	draw_image(mlx);
}

void	front_view(t_mlx *mlx)
{
	int		height;
	int		width;
	float	centers[3];
	float	**matrix;

	height = mlx->map->height;
	width = mlx->map->width;
	if (mlx->points)
		free_points(mlx, mlx->points);
	mlx->points = return_array(mlx, height, width, mlx->camera->zoom);
	centers[0] = mlx->points[height / 2][width / 2][0];
	centers[1] = mlx->points[height / 2][width / 2][2];
	centers[2] = mlx->points[height / 2][width / 2][1];
	move_to_origin(mlx);
	matrix = return_matrix('x', -90 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	move_center(mlx, centers[0], centers[1], centers[2]);
	free_matrix(matrix);
	draw_image(mlx);
}

void	op_pers(t_mlx *mlx)
{
	int		height;
	int		width;
	float	centers[3];
	float	**matrix;

	height = mlx->map->height;
	width = mlx->map->width;
	if (mlx->points)
		free_points(mlx, mlx->points);
	mlx->points = return_array(mlx, height, width, mlx->camera->zoom);
	centers[0] = mlx->points[height / 2][width / 2][0];
	centers[1] = mlx->points[height / 2][width / 2][2];
	centers[2] = mlx->points[height / 2][width / 2][1];
	move_to_origin(mlx);
	matrix = return_matrix('x', -75 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	matrix = return_matrix('z', 30 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	move_center(mlx, centers[0], centers[1], centers[2]);
	draw_image(mlx);
}
