/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/20 16:38:15 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	ret_point(t_mlx *mlx, int i, int j)
{
	t_point	point;

	point.x = mlx->points[i][j][0];
	point.y = mlx->points[i][j][2];
	point.color = get_color(mlx, i, j);
	return (point);
}

void	draw(t_mlx *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->map->height)
	{
		j = -1;
		while (++j < m->map->width)
		{
			if (i < m->map->height - 1)
				draw_line(m, ret_point(m, i, j), ret_point(m, i + 1, j));
			if (j < m->map->width - 1)
				draw_line(m, ret_point(m, i, j), ret_point(m, i, j + 1));
		}
	}
	mlx_put_image_to_window(m->mlx, m->mlx_window, m->img.img, 0, 0);
}

int	return_gradient(t_point start, t_point end, t_point current)
{
	float	perc;

	if (current.x > current.y)
		perc = get_current_percent(start.x, end.x, current.x);
	else
		perc = get_current_percent(start.y, end.y, current.y);
	return (gradient_color(start, end, perc));
}

void	draw_line(t_mlx *mlx, t_point start, t_point end)
{
	t_line	dda;
	t_point	curr;

	dda.dx = round(end.x) - round(start.x);
	dda.dy = round(end.y) - round(start.y);
	if (absolute(dda.dx) > absolute(dda.dy))
		dda.steps = absolute(dda.dx);
	else
		dda.steps = absolute(dda.dy);
	dda.xinc = dda.dx / (float)dda.steps;
	dda.yinc = dda.dy / (float)dda.steps;
	curr.x = start.x;
	curr.y = start.y;
	while (dda.steps--)
	{
		pixel_put(mlx, curr.x, curr.y, return_gradient(start, end, curr));
		curr.x += dda.xinc;
		curr.y += dda.yinc;
	}
}
