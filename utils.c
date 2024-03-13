/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:28:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/13 10:41:08 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	return_minimum(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		absolute(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

int	print_instructions(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->mlx_window, (WIDTH / 2) - 950, HEIGHT - 1050, 0x000099EF, "Arrow keys: Translate shape");
	mlx_string_put(mlx->mlx, mlx->mlx_window, (WIDTH / 2) - 950, HEIGHT - 1000, 0x000099EF, "Q & E: Rotate z");
	mlx_string_put(mlx->mlx, mlx->mlx_window, (WIDTH / 2) - 950, HEIGHT - 950, 0x000099EF, "A & D: Rotate y");
	mlx_string_put(mlx->mlx, mlx->mlx_window, (WIDTH / 2) - 950, HEIGHT - 900, 0x000099EF, "W & S: Rotate x");
	return (0);
}

/* place the center of the point into the center of the screen */
void	get_default_position(t_mlx *mlx, float ***points)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			points[i][j][0] += mlx->camera->x_offset;
			points[i][j][2] += mlx->camera->y_offset;
		}
	}
	
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

int	get_z_min(t_map *map)
{
	int	z_min;
	int	i;
	int	j;

	z_min = INT_MAX;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->z_coord[i][j][0] < z_min)
				z_min = map->z_coord[i][j][0];
		}
	}
	return (z_min);
}
