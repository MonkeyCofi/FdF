/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/12 20:36:48 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_frac(int x, int y, t_point start, t_point end)
{
	t_line	dda;
	float	frac;

	dda.dx = end.x - start.x;
	dda.dy = end.y - start.y;
	if (absolute(dda.dx) > absolute(dda.dy))
		frac = get_current_percent(start.x, end.x, x);
	else
		frac = get_current_percent(start.y, end.y, y);
	return (frac);
}

void	draw(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			if (i < mlx->map->height - 1)
				draw_line(mlx, return_point(mlx, mlx->points[i][j][0], mlx->points[i][j][2], i, j), \
					return_point(mlx, mlx->points[i + 1][j][0], mlx->points[i + 1][j][2], i + 1, j), get_color(mlx, i, j));
			if (j < mlx->map->width - 1)
				draw_line(mlx, return_point(mlx, mlx->points[i][j][0], mlx->points[i][j][2], i, j), \
					return_point(mlx, mlx->points[i][j + 1][0], mlx->points[i][j + 1][2], i, j + 1), get_color(mlx, i, j));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 0, 0);
}

t_point	return_point(t_mlx *mlx, float x, float y, int i, int j)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.color = get_color(mlx, i, j); 
	return (point);
}

int	colorr(t_mlx *mlx, t_point start, t_point end, t_point current)
{
	float	perc;
	
	if (current.x > current.y)
		perc = get_current_percent(start.x, end.x, current.x);
	else
		perc = get_current_percent(start.y, end.y, current.y);
	(void)mlx;
	return (gradient_color(start, end, perc));
}

void	draw_line(t_mlx *mlx, t_point start, t_point end, int color)
{
	t_line	dda;
	t_point	current;
	float	x;
	float	y;

 	dda.dx = end.x - start.x;
 	dda.dy = end.y - start.y;
 	if (absolute(dda.dx) > absolute(dda.dy))
		dda.steps = absolute(dda.dx);
 	else
 		dda.steps = absolute(dda.dy);
 	dda.xinc = dda.dx / (float)dda.steps;
 	dda.yinc = dda.dy / (float)dda.steps;
	x = start.x;
	y = start.y;
	current.x = x;
	current.y = y;
 	while (dda.steps--)
 	{
	 	pixel_put(mlx, current.x, current.y, colorr(mlx, start, end, current));
	 	// pixel_put(mlx, current.x, current.y, color);
	 	current.x += dda.xinc;
	 	current.y += dda.yinc;
	}
	(void)color;
}
