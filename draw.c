/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/19 15:02:19 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ret_point(t_mlx *mlx, float x, float y, int i, int j)
{
	t_point	point;

	point.x = x;
	point.y = y;
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
				draw_line(m, ret_point(m, m->points[i][j][0], \
				m->points[i][j][2], i, j), ret_point(m, m->points[i + 1][j][0], \
						m->points[i + 1][j][2], i + 1, j));
			if (j < m->map->width - 1)
				draw_line(m, ret_point(m, m->points[i][j][0], \
				m->points[i][j][2], i, j), ret_point(m, m->points[i][j + 1][0], \
					m->points[i][j + 1][2], i, j + 1));
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
