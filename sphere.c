/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:49:38 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/14 21:04:59 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>

int	change_colors(t_mlx *mlx, int d, int keycode)
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
	(void)keycode;
	return (0);
}

int	disco_ball(t_mlx *mlx, int keycode)
{
	float	centers[3];

	if (mlx->bon)
	{
		centers[0] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][0];
		centers[1] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][1];
		centers[2] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][2];
		move_to_origin(mlx);
		apply_transformation(mlx->points, return_matrix('z', 0.0010 * (180 / 3.1415)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, centers[0], centers[2], centers[1]);
		change_colors(mlx, 0, keycode);
	}
	else
		change_colors(mlx, 1, 0);
	draw_image(mlx);
	(void)keycode;
	return (0);
}
