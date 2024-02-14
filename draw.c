/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/14 20:21:07 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
* calculate the difference between the start and end points of both x and y: dx = x(end) - x(beginning); dy = y(end) - y(beginning) 
* calculate the slope of the line to be drawn: slope m = dy/dx; difference of x values divided by difference of y values
*/
//void	draw(t_map *map, t_mlx *mlx)
//{
//	ft_bzero(mlx->img->addr, WIDTH * HEIGHT * (mlx->img->bpp / 8));
//}

int	abs(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

void	draw(int x1, int x2, int y1, int y2)
{
	float	dx;
	float	dy;
	float	slope;
	int		length;

	dx = x2 - x1;
	dy = y2 - y1;
	slope = dy / dx;
	if (absolute(dx) > absolute(dy))
		length = absolute(dx);
	else
		length = absolute(dy);
	
}

void	draw_line()