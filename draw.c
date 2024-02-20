/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/19 20:30:15 by pipolint         ###   ########.fr       */
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

//void	draw(t_mlx *mlx)
//{
//	int	x;
//	int	y;

//	x = 0;
//	y = 0;
//	while (y < mlx->map->height)
//	{
//		while (x < mlx->map->width)
//		{
//			draw_line(mlx, x, )
//			x++;
//		}
//		y++;
//	}
//	mlx_put_image_to_window(mlx, mlx->mlx_window, mlx->img.img, 200, 200);
//}

void	draw(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while(++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			if (j + 1 < mlx->map->width)
				draw_line(mlx, j, j + 1, i, i);
			// if (i + 1 < mlx->map->height)
			// 	draw_line(mlx, j, j, i, i + 1);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 200, 200);
}

//void	draw(t_mlx *mlx)
//{
//	//t_point	one;
//	//t_point	two;
//	//int		x;
//	//int		y;

//	//one.x = 0;
//	//two.x = 1;
//	//one.y = 0;
//	//two.y = 0;
//	//x = 0;
//	//y = 0;
//	//while (y < mlx->map->height)
//	//{
//	//	while (x < mlx->map->width)
//	//	{
//	//		if (two.x <= mlx->map->width)
//	//			draw_line(mlx, one, two);
//	//		one.x++;
//	//		two.x++;
//	//		x++;
//	//	}
//	//	draw_line(mlx, one, two);
//	//	one.y++;
//	//	two.y++;
//	//	y++;
//	//}
//	//mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 100, 100);
	
//	t_point	one;
//	t_point	two;
//	t_point	three;
//	int		x;
//	int		y;

//	one.x = 0;
//	two.x = 1;
//	one.y = 0;
//	two.y = 0;
//	three.x = 0;
//	three.y = 1;
//	y = 0;
//	while (y < mlx->map->height)
//	{
//		x = 0;
//		while (x < mlx->map->width)
//		{
//			if (two.x <= mlx->map->width)
//				draw_line(mlx, one, two);
//			if (three.y <= mlx->map->height)
//				draw_line(mlx, one, three);
//			one.x++;
//			two.x++;
//			x++;
//		}
//		one.y++;
//		three.y++;
//		y++;
//	}
//	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 100, 100);
//}


//void	draw_line(t_mlx *mlx, t_point one, t_point two)
//{
//	int		i;
//	float	x;
//	float	y;
//	t_line	line_vars;

//	i = 0;
//	line_vars.dx = two.x - one.x;
//	line_vars.dy = two.y - one.y;
//	ft_printf("x1 %d x0 %d\n", two.x, one.x);
//	ft_printf("dx %d\n", line_vars.dx);
//	ft_printf("dy %d\n", line_vars.dy);
//	if (absolute(line_vars.dx) > absolute(line_vars.dy))
//		line_vars.steps = absolute(line_vars.dx);
//	else
//		line_vars.steps = absolute(line_vars.dy);
//	line_vars.xinc = line_vars.dx / (float)line_vars.steps;
//	line_vars.yinc = line_vars.dy / (float)line_vars.steps;
//	x = one.x;
//	y = one.y;
//	while (i < line_vars.steps)
//	{
//		pixel_put(mlx, round(x), round(y), 0xFF00FF);
//		x += line_vars.xinc;
//		y += line_vars.yinc;
//		i++;
//	}
//}


 void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend)
 {
 	float	dx;
 	float	dy;
 	int		steps;
 	float	xinc;
 	float	yinc;
	int		i;

 	dx = xend - xstart;
 	dy = yend - ystart;
 	if (absolute(dx) > absolute(dy))
 		steps = absolute(dx);
 	else
 		steps = absolute(dy);
 	xinc = dx / (float)steps;
 	yinc = dy / (float)steps;
	i = -1;
 	while (++i < steps)
 	{
 		pixel_put(mlx, xstart, ystart, 0xFFFFFF);
 		xstart += round(xinc);
 		ystart += round(yinc);
 	}
 }



//// void	fill_points(t_point)
