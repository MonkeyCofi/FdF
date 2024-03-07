/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:45:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/07 19:14:39 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	/*										best projections															*/
	apply_transformation(point_array, return_matrix('z', 0.17 * 3.14159265358979323), mlx->map->height, mlx->map->width);
	apply_transformation(point_array, return_matrix('x', -0.043 * 3.14159265358979323), mlx->map->height, mlx->map->width);
	apply_transformation(point_array, return_matrix('y', -0.2 * 3.14159265358979323), mlx->map->height, mlx->map->width);
	
	//apply_transformation(point_array, return_matrix('y', -0.12 * 3.1415), mlx->map->height, mlx->map->width);
	//apply_transformation(point_array, return_matrix('x', -0.05 * 3.1415), mlx->map->height, mlx->map->width);
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
	float	height;
	float	width;
	int		i;
	int		j;

	i = -1;
	j = -1;
	ft_printf("Map height: %d\n", mlx->map->height);
	ft_printf("Map width: %d\n", mlx->map->width);
	height = (HEIGHT / 2);
	width = (WIDTH / 2);
	printf("height: %f\n", height);
	printf("width: %f\n", width);
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			//points[i][j][0] += WIDTH / 2;
			//points[i][j][2] += HEIGHT / 2;
			points[i][j][0] += width;
			points[i][j][2] += height;
		}
	}
	(void)scale;
}

float	get_default_scale(t_mlx *mlx)
{
	float	scale_height;
	float	scale_width;
	float	scale_z_height;
	float	factor;

	factor = 2.3;
	scale_height = HEIGHT / (mlx->map->height * factor);
	scale_width = WIDTH / (mlx->map->width * factor);
	scale_z_height = HEIGHT / (get_z_max(mlx) * factor);
	if (scale_width > scale_height)
		return (scale_width);
	else if (scale_height > scale_width)
		return (scale_height);
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
	mlx.points = return_array(&mlx, mlx.map->height, mlx.map->width, scale); // CORRECT COMPLETELY	
	if (!APP)
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
				pixel_put(&mlx, i, j, 0x000000);
		}
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
	}
	// draw(&mlx);
	
	/* for mac */
	if (APP)
		mlx_hook(mlx.mlx_window, 2, 0, get_key_pressed, &mlx);
	else
		/* for linux */
		mlx_hook(mlx.mlx_window, 2, 1L << 0, get_key_pressed, &mlx);
	//mlx_mouse_hook(mlx.mlx_window, get_mouse_function, &mlx);
	project(&mlx, mlx.points);
	get_default_position(&mlx, mlx.points, scale);
	draw(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
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
