/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:41:08 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/20 15:27:03 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_image(t_mlx *mlx)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, \
		&mlx->img.line_length, &mlx->img.endian);
	draw(mlx);
	return (0);
}

void	mult_by_scale(t_mlx *mlx, float scale)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			mlx->points[i][j][0] *= scale;
			mlx->points[i][j][1] *= scale;
			mlx->points[i][j][2] *= scale;
		}
	}
}

void	zoom(t_mlx *mlx, float scale, int code)
{
	float	centers[3];
	int		height;
	int		width;

	height = mlx->map->height;
	width = mlx->map->width;
	centers[0] = mlx->points[height / 2][width / 2][0];
	centers[1] = mlx->points[height / 2][width / 2][1];
	centers[2] = mlx->points[height / 2][width / 2][2];
	if (code == PLUS)
	{
		move_to_origin(mlx);
		mult_by_scale(mlx, 1.1);
		move_shape_back(mlx, centers[0], centers[2], centers[1]);
		draw_image(mlx);
	}
	else if (code == MINUS)
	{
		move_to_origin(mlx);
		mult_by_scale(mlx, 0.9);
		move_shape_back(mlx, centers[0], centers[2], centers[1]);
		draw_image(mlx);
	}
	(void)scale;
}

void	transform_shape(t_mlx *mlx, float *axes, float *angle, char axis)
{
	float	**matrix;

	move_to_origin(mlx);
	matrix = return_matrix(axis, ((*angle) - 4) * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, \
		mlx->map->height, mlx->map->width);
	free_matrix(matrix);
	move_shape_back(mlx, axes[0], axes[1], axes[2]);
}
