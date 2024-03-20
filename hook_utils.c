/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:03:29 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/20 15:33:27 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_to_origin(t_mlx *mlx)
{
	float	centers[3];
	int		height;
	int		width;
	int		i;
	int		j;

	height = mlx->map->height;
	width = mlx->map->width;
	centers[0] = mlx->points[height / 2][width / 2][0];
	centers[1] = mlx->points[height / 2][width / 2][2];
	centers[2] = mlx->points[height / 2][width / 2][1];
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			mlx->points[i][j][0] -= centers[0];
			mlx->points[i][j][1] -= centers[2];
			mlx->points[i][j][2] -= centers[1];
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

void	reset(t_mlx *m)
{
	int	height;
	int	width;

	height = m->map->height;
	width = m->map->width;
	if (m->points)
		free(m->points);
	m->points = return_array(m, height, width, m->camera->zoom);
	if (m->camera)
		free(m->camera);
	init_camera(m);
	get_default_position(m, m->points);
	draw_image(m);
}

void	check_bonus_hook(int k, t_mlx *mlx)
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
