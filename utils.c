/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:28:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/20 15:26:44 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	absolute(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

static void	move_into_bounds(t_mlx *mlx, float ***points, int under_over)
{
	int	i;
	int	j;

	if (under_over == 1)
	{
		i = -1;
		while (++i < mlx->map->height)
		{
			j = -1;
			while (++j < mlx->map->width)
				points[i][j][2] += 100;
		}
	}
	else if (under_over == -1)
	{
		i = -1;
		while (++i < mlx->map->height)
		{
			j = -1;
			while (++j < mlx->map->width)
				points[i][j][2] -= 300;
		}
	}
}

void	get_default_position(t_mlx *mlx, float ***points)
{
	int		i;
	int		j;
	int		out;

	i = -1;
	out = 0;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			points[i][j][0] += mlx->camera->x_offset;
			points[i][j][2] += mlx->camera->y_offset;
			if (points[i][j][2] < 0)
				out = 1;
			else if (points[i][j][2] > HEIGHT)
				out = -1;
		}
	}
	move_into_bounds(mlx, points, out);
}

int	get_z_max(t_mlx *mlx)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			if (mlx->map->z_coord[i][j][0] > max)
				max = mlx->map->z_coord[i][j][0];
		}
	}
	return (max);
}
