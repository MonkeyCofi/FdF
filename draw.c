/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/24 14:41:12 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	absolute(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

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
				draw_line(mlx, return_point(mlx->points[i][j][0], mlx->points[i][j][2]), return_point(mlx->points[i + 1][j][0], mlx->points[i + 1][j][2]), get_color(mlx, i, j));
			if (j < mlx->map->width - 1)
				draw_line(mlx, return_point(mlx->points[i][j][0], mlx->points[i][j][2]), return_point(mlx->points[i][j + 1][0], mlx->points[i][j + 1][2]), get_color(mlx, i, j));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 0, 0);
}

t_point	return_point(float x, float y)
{
	t_point	point;

	point.x = (float)x;
	point.y = (float)y;
	return (point);
}

 // void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend, int color)
 // {
 // 	t_line	dda;
 // float	x;
 // float	y;
 //
 // 	dda.dx = xend - xstart;
 // 	dda.dy = yend - ystart;
 // 	if (absolute(dda.dx) > absolute(dda.dy))
 // 		dda.steps = absolute(dda.dx);
 // 	else
 // 		dda.steps = absolute(dda.dy);
 // 	dda.xinc = dda.dx / (float)dda.steps;
 // 	dda.yinc = dda.dy / (float)dda.steps;
 // x = xstart;
 // y = ystart;
 // 	while (dda.steps--)
 // 	{
 // 	pixel_put(mlx, x, y, color);
 // 	x += dda.xinc;
 // 	y += dda.yinc;
 // }
 // }


void	draw_line(t_mlx *mlx, t_point start, t_point end, int color)
{
	t_line	dda;
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
 	while (dda.steps--)
 	{
	 	pixel_put(mlx, x, y, color);
	 	x += dda.xinc;
	 	y += dda.yinc;
	}
} 
