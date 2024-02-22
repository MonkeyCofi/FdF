/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:45:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/22 18:12:02 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	pixel_put(t_data *img, int x, int y, unsigned int color)
// {
// 	char	*pixel;
//
// 	pixel = img->addr + (y * img->line_length) + (x * (img->bpp / 8));
// 	*(unsigned int *)pixel = color;
// }

int	change_color(t_mlx *mlx)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	color = 0;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			pixel_put(mlx, i, j, color++ % 256);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_window, mlx->img.img, 0, 0);
	return (0);
}

int	cont_draw(t_mlx *mlx, float ***array)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			pixel_put(mlx, i, j, 0x00FF00);
		}
	}
	//draw(mlx, array);
	mlx_put_image_to_window(mlx, mlx->mlx_window, mlx->img.img, 0, 0);
	(void)array;
	return (0);
}

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*p;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		p = mlx->img.addr + (y * mlx->img.line_length) + (x * (mlx->img.bpp / 8));
		*(unsigned int *)p = color;
	}
}

void	project(t_mlx *mlx, float ***point_array)
{
	(void)mlx; (void)point_array;
	apply_transformation(point_array, return_matrix('y', 0.1 * 3.14159265358979323), mlx->map->height, mlx->map->width);
	
	apply_transformation(point_array, return_matrix('x', -0.3 * 3.14159265358979323), mlx->map->height, mlx->map->width);
	apply_transformation(point_array, return_matrix('z', 0.15 * 3.14159265358979323), mlx->map->height, mlx->map->width);
	//apply_transformation(point_array, return_matrix('z', -0.6 * 3.14159265358979323), mlx->map->height, mlx->map->width);
}

int main(int ac, char **av)
{
	t_mlx	mlx;

	// last argument is temporarily the scale
	if (ac < 3)
	{
		ft_printf("Usage: ./fdf [mapfile]\n");
		exit(EXIT_FAILURE);
	}
	init_mlx(&mlx);
	init_map(&mlx);
	parse_map(av[1], mlx.map);
	
	/* for chromebook only */
	if (!APP)
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
				pixel_put(&mlx, j, i, 0x000000);
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
		}
	}
	/* for chromebook only */
	
	//draw(&mlx);
	mlx_key_hook(mlx.mlx_window, get_key_pressed, &mlx.mlx);
	mlx_mouse_hook(mlx.mlx_window, zoom, &mlx);
	int scale = ft_atoi(av[ac - 1]);
	float ***array = return_array(&mlx, mlx.map->height, mlx.map->width, scale); // CORRECT COMPLETELY
	project(&mlx, array);
	int		i;
	int		j;
	i = -1;
	while (++i < mlx.map->height)
	{
		j = -1;
		while (++j < mlx.map->width)
		{
			array[i][j][0] += 500;	// left and right
			array[i][j][2] += 600;	// up and down
		}
	}
	draw(&mlx, array);
	//i = -1;
	//while (++i < mlx.map->height)
	//{
	//	j = -1;
	//	while (++j < mlx.map->width)
	//	{
	//		printf("%2.0f ", array[i][j][0]);
	//		printf("%2.0f ", array[i][j][2]);
	//		if (j < mlx.map->width - 1)
	//			draw_line(&mlx,array[i][j][0],array[i][j + 1][0],array[i][j][2],array[i][j + 1][2]);
	//		if (j < mlx.map->width - 1 && i < mlx.map->height - 1)
	//			draw_line(&mlx,array[i][j][0],array[i + 1][j + 1][0],array[i][j][2],array[i + 1][j + 1][2]);
	//		if (i < mlx.map->height - 1)
	//			draw_line(&mlx,array[i][j][0],array[i + 1][j][0],array[i][j][2],array[i + 1][j][2]);
	//		//if (j > 0 && i < mlx.map->height - 1)
	//		//	draw_line(&mlx,array[i][j][0],array[i + 1][j - 1][0],array[i][j][2],array[i + 1][j - 1][2]);
	//	}
	//	printf("\n");
	//}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
