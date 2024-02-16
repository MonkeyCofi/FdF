/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/15 16:23:14 by pipolint         ###   ########.fr       */
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

int	absolute(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

//void	draw(int x1, int x2, int y1, int y2, t_data *data)
//{
//	float	dx;
//	float	dy;
//	float	slope;
//	int		length;

//	dx = x2 - x1;
//	dy = y2 - y1;
//	slope = dy / dx;
//	if (absolute(dx) > absolute(dy))
//		length = absolute(dx);
//	else
//		length = absolute(dy);
//	while (y1 < y2)
//	{
//		while (x1 < x2)
//		{
//			pixel_put(data, y1, y2, 0xFF0000);
//			x1++;
//		}
//		y1++;
//	}
//}

//void	draw_line()