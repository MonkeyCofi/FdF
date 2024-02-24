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

//void	fill_point(t_point *point, float ***array, int i, int j)
//{
//	point->x = array[i][j][0];
//	point->z = array[i][j][2];
//}
//int	color_gradient(t_mlx *mlx, int i, int j)
//{
//	float	color;

	
//	return (1);
//}

// int	get_color(t_mlx *mlx, int i, int j)
// {
// 	if (mlx->map->z_coord[i][j][1] != -1)
// 		return (mlx->map->z_coord[i][j][1]);
// 	return (0xFFFFFF);
// }

int	absolute(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

// void	draw(t_mlx *mlx, float ***point_array)
// {
// 	int	i;
// 	int	j;
//
// 	i = -1;
// 	while (++i < mlx->map->height)
// 	{
// 		j = -1;
// 		while (++j < mlx->map->width)
// 		{
// 			if (j < mlx->map->width - 1)
// 				draw_line(mlx, point_array[i][j][0], point_array[i][j + 1][0], point_array[i][j][2], point_array[i][j + 1][2], get_color(mlx, i, j));
// 			if (i < mlx->map->height - 1)
// 				draw_line(mlx, point_array[i][j][0], point_array[i + 1][j][0], point_array[i][j][2], point_array[i + 1][j][2], get_color(mlx, i, j));
// 		}
// 	}
// }

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
			if (j < mlx->map->width - 1)
				draw_line(mlx, mlx->points[i][j][0], mlx->points[i][j + 1][0], mlx->points[i][j][2], mlx->points[i][j + 1][2], get_color(mlx, i, j));
			if (i < mlx->map->height - 1)
				draw_line(mlx, mlx->points[i][j][0], mlx->points[i + 1][j][0], mlx->points[i][j][2], mlx->points[i + 1][j][2], get_color(mlx, i, j));
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 0, 0);
}

//void	draw(t_mlx *mlx, float ***point_array)
//{
//	t_point	one;
//	t_point	two;
//	int	i;
//	int	j;

//	i = -1;
//	while (++i < mlx->map->height)
//	{
//		j = -1;
//		while (++j < mlx->map->width)
//		{
//			fill_point(&one, point_array, i, j);
//			//one.y = point_array[i][j][2];
//			//two.y = point_array[i][j + 1][2];
//			if (j < mlx->map->width - 1)
//			{
//				fill_point(&two, point_array, i, j + 1);
//				draw_line(mlx, one, two, 0xFFFFFF);
//			}
//				//draw_line(mlx, point_array[i][j][0], point_array[i][j + 1][0], point_array[i][j][2], point_array[i][j + 1][2]);
//			//if (i < mlx->map->height - 1)
//			//	draw_line(mlx, point_array[i][j][0], point_array[i + 1][j][0], point_array[i][j][2], point_array[i + 1][j][2]);
//		}
//	}
//}

 void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend, int color)
 {
 	t_line	dda;
	float	x;
	float	y;

 	dda.dx = xend - xstart;
 	dda.dy = yend - ystart;
 	if (absolute(dda.dx) > absolute(dda.dy))
 		dda.steps = absolute(dda.dx);
 	else
 		dda.steps = absolute(dda.dy);
 	dda.xinc = dda.dx / (float)dda.steps;
 	dda.yinc = dda.dy / (float)dda.steps;
	x = xstart;
	y = ystart;
 	while (dda.steps--)
 	{
		pixel_put(mlx, x, y, color);
		x += dda.xinc;
		y += dda.yinc;
	}
 	//float	dx;
 	//float	dy;
 	//int		steps;
 	//float	xinc;
 	//float	yinc;
	//float	x;
	//float	y;

 	//dx = xend - xstart;
 	//dy = yend - ystart;
 	//if (absolute(dx) > absolute(dy))
 	//	steps = absolute(dx);
 	//else
 	//	steps = absolute(dy);
 	//xinc = dx / (float)steps;
 	//yinc = dy / (float)steps;
	//x = xstart;
	//y = ystart;
 	//while (steps--)
 	//{
	//	pixel_put(mlx, x, y, color);
	//	x += xinc;
	//	y += yinc;
	//}
 }


// void	draw_line(t_mlx *mlx, t_point one, t_point two, int color)
// {
// 	t_line	dda;
//	float	x;
//	float	y;

// 	dda.dx = two.x - one.x;
//	dda.dy = two.y - one.y;
// 	if (absolute(dda.dx) > absolute(dda.dy))
// 		dda.steps = absolute(dda.dx);
// 	else
// 		dda.steps = absolute(dda.dy);
// 	dda.xinc = dda.dx / (float)dda.steps;
// 	dda.yinc = dda.dy / (float)dda.steps;
//	x = one.x;
//	y = one.y;
// 	while (dda.steps--)
// 	{
//		pixel_put(mlx, x, y, color);
//		x += dda.xinc;
//		y += dda.yinc;
//	}
// }

