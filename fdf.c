/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:45:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/11 01:33:41 by pipolint         ###   ########.fr       */
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
	 apply_transformation(point_array, return_matrix('y', 45 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
	 apply_transformation(point_array, return_matrix('x', -62 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
	(void)mlx;
	(void)point_array;
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

int	get_z_min(t_map *map)
{
	int	z_min;
	int	i;
	int	j;

	z_min = INT_MAX;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->z_coord[i][j][0] < z_min)
				z_min = map->z_coord[i][j][0];
		}
	}
	return (z_min);
}

//void	get_default_position(t_mlx *mlx, float ***points, int scale)
//{
//	float	height;
//	float	width;
//	int		z_max;
//	int		i;
//	int		j;

//	z_max = get_z_max(mlx);
//	i = -1;
//	j = -1;
//	height = (HEIGHT / mlx->camera->y_offset);
//	width = (WIDTH / mlx->camera->x_offset);
//	while (++i < mlx->map->height)
//	{
//		j = -1;
//		while (++j < mlx->map->width)
//		{
//			points[i][j][0] += width;
//			points[i][j][2] += height;
//		}
//	}
//	(void)scale;
//}

void	get_default_position(t_mlx *mlx, float ***points, int scale)
{
	float	height;
	float	width;
	int		z_max;
	int		i;
	int		j;

	z_max = get_z_max(mlx);
	i = -1;
	j = -1;
	height = (HEIGHT / 2);
	width = (WIDTH / 2);
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
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

	factor = 1.9;
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
	valid_map(av[1]);
	init_mlx(&mlx);
	init_map(&mlx);
	parse_map(av[1], mlx.map);
	init_camera(&mlx);
	scale = get_default_scale(&mlx);
	mlx.points = return_array(&mlx, mlx.map->height, mlx.map->width, scale);
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
