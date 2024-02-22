/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:06:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/22 17:59:25 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom(int keycode, t_mlx *mlx, int scale, float ***array)
{
	//if (keycode == 4)
	//{
			
	//}
	//(void)keycode, (void)mlx,(void)scale;
	ft_printf("hehe\n");
	(void)scale, (void)mlx, (void)keycode, (void)array;
	return (0);
}

int	get_key_pressed(int keycode, t_mlx *mlx, int scale)
{
	if (keycode == 53 || keycode == 655307)
		escape(keycode, mlx);
	else
		zoom(keycode, mlx, scale, NULL);
	return (0);
}

int	escape(int keycode, t_mlx *mlx)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	left(float ***array, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (array[i][j][0] > 0)
				array[i][j][0] -= 25;
		}
	}
}

int	translate(int keycode, float ***array, t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	if (keycode == 123)
	{
		left(array, mlx->map->height, mlx->map->width);
	}
	(void)mlx;
	(void)j;
	(void)array;
	//left = 123
	//right = 124
	//down = 125
	//up = 126
	return (0);
}


