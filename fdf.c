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

int	get_z_max(t_mlx *mlx)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			if (mlx->map->z_coord[i][j][0] > max)
				max = mlx->map->z_coord[i][j][0];
		}
	}
	return (max);
}

void	get_default_position(t_mlx *mlx, float ***points, int scale)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			points[i][j][0] += WIDTH / 2;
			points[i][j][2] += HEIGHT / 2;
		}
	}
	(void)scale;
}

int	get_default_scale(t_mlx *mlx)
{
	int		scale_height;
	int		scale_width;
	int		scale_z_height;
	float	factor;

	factor = 1.99;
	scale_height = HEIGHT / (mlx->map->height * factor);
	scale_width = WIDTH / (mlx->map->width * factor);
	scale_z_height = HEIGHT / (get_z_max(mlx) * factor);
	if (scale_height <= scale_width)
		return (scale_height);
	else
		return (scale_width);
	return (scale_z_height);
}

int main(int ac, char **av)
{
	t_mlx	mlx;
	int		scale;
	
	if (ac < 2)
	{
		ft_printf("Usage: ./fdf [mapfile]\n");
		exit(EXIT_FAILURE);
	}
	init_mlx(&mlx);
	init_map(&mlx);
	parse_map(av[1], mlx.map);
	scale = get_default_scale(&mlx);
	mlx.points =  return_array(&mlx, mlx.map->height, mlx.map->width, scale); // CORRECT COMPLETELY	
	/* for chromebook only */
	// if (!APP)
	// {
	// 	for (int i = 0; i < HEIGHT; i++)
	// 	{
	// 		for (int j = 0; j < WIDTH; j++)
	// 			pixel_put(&mlx, j, i, 0x000000);
	// 		mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
	// 	}
	// }
	/* for chromebook only */
	
	// draw(&mlx);
	// mlx_loop_hook(mlx.mlx, get_key_pressed, &mlx);
	mlx_key_hook(mlx.mlx_window, get_key_pressed, &mlx);
	project(&mlx, mlx.points);
	get_default_position(&mlx, mlx.points, scale);
	// int		i;
	// int		j;
	// i = -1;
	// while (++i < mlx.map->height)
	// {
	// 	j = -1;
	// 	while (++j < mlx.map->width)
	// 	{
	// 		array[i][j][0] += 200;	// left and right
	// 		array[i][j][2] += 145;	// up and down
	// 	}
	// }
	draw(&mlx);
	mlx_loop(mlx.mlx);
}



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
	// mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
