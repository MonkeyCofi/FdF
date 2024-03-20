/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:49:38 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/20 15:25:58 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

int	change_colors(t_mlx *mlx, int d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			if (!d)
				mlx->map->z_coord[i][j][1] = mlx->current_color;
			else
				mlx->map->z_coord[i][j][1] = mlx->def_color[i][j][0];
		}
	}
	return (0);
}

int	color_spin(t_mlx *mlx)
{
	float	centers[3];
	float	**matrix;
	int		height;
	int		width;

	height = mlx->map->height;
	width = mlx->map->width;
	if (mlx->bon)
	{
		centers[0] = mlx->points[height / 2][width / 2][0];
		centers[1] = mlx->points[height / 2][width / 2][1];
		centers[2] = mlx->points[height / 2][width / 2][2];
		move_to_origin(mlx);
		matrix = return_matrix('z', 0.0010 * (180 / 3.1415));
		apply_transformation(mlx->points, matrix, height, width);
		free_matrix(matrix);
		move_shape_back(mlx, centers[0], centers[2], centers[1]);
		change_colors(mlx, 0);
	}
	else
		change_colors(mlx, 1);
	draw_image(mlx);
	return (0);
}
