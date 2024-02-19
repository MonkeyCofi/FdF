/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/17 16:39:06 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	absolute(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

void	draw(t_mlx *mlx)
{
	t_point	one;
	t_point	two;
	int		i;
	int		j;

	i = 0;
	j = 0;
	two.x = mlx->map->width;
	one.x = i;
	two.y = mlx->map->height;
	one.y = j;
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			draw_line(mlx, one, two);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 0, 0);
}

void	draw_line(t_mlx *mlx, t_point one, t_point two)
{
	int		i;
	float	x;
	float	y;
	t_line	line_vars;

	i = 0;
	line_vars.dx = two.x - one.y;
	line_vars.dy = two.y - one.y;
	if (absolute(line_vars.dx) > absolute(line_vars.dy))
		line_vars.steps = absolute(line_vars.dx);
	else
		line_vars.steps = absolute(line_vars.dy);
	line_vars.xinc = line_vars.dx / (float)line_vars.steps;
	line_vars.yinc = line_vars.dy / (float)line_vars.steps;
	x = one.x;
	y = one.y;
	printf("steps %d\n", line_vars.steps);
	while (i < line_vars.steps)
	{
		pixel_put(mlx, x, y, 0xFF0000);
		x += line_vars.xinc;
		y += line_vars.yinc;
		i++;
	}
}


// void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend)
// {
// 	float	dx;
// 	float	dy;
// 	int		steps;
// 	float	xinc;
// 	float	yinc;
//
// 	dx = xend - xstart;
// 	dy = yend - ystart;
// 	if (absolute(dx) > absolute(dy))
// 		steps = absolute(dx);
// 	else
// 		steps = absolute(dy);
// 	xinc = dx / (float)steps;
// 	yinc = dy / (float)steps;
// 	while (steps--)
// 	{
// 		pixel_put(mlx, xstart, yend, 0xFFFF00);
// 		xstart += xinc;
// 		ystart += yinc;
// 	}
// }

// void	fill_points(t_point)
