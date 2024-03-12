/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:32:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/12 19:46:50 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera(t_mlx *mlx)
{
	t_cam	*camera;

	camera = malloc(sizeof(t_cam));
	if (!camera)
		exit(EXIT_FAILURE);
	camera->x_angle = -62 * (3.1415 / 180);
	camera->y_angle = 45 * (3.1415 / 180);
	apply_transformation(mlx->points, return_matrix('y', camera->y_angle), mlx->map->height, mlx->map->width);
	apply_transformation(mlx->points, return_matrix('x', camera->x_angle), mlx->map->height, mlx->map->width);
	camera->x_offset = (WIDTH / 2) - mlx->points[mlx->map->height / 2][mlx->map->width / 2][0];
	camera->y_offset = (HEIGHT / 2) - mlx->points[mlx->map->height / 2][mlx->map->width / 2][2];
	camera->zoom = get_default_scale(mlx);
	mlx->camera = camera;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(EXIT_FAILURE);
	mlx->mlx_window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FdF");
	if (!mlx->mlx_window)
		exit(EXIT_FAILURE);
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img.img)
		exit(EXIT_FAILURE);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
	mlx->points = NULL;
	mlx->camera = NULL;
}

void	init_map(t_mlx *mlx)
{
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		return ;
	mlx->map->height = 0;
	mlx->map->width = 0;
	mlx->map->z_coord = NULL;
}


float	***return_array(t_mlx *mlx, int height, int width, int scale)
{
	float	***point_arr;
	int		i;
	int		j;

	point_arr = malloc(sizeof(float **) * height);
	i = -1;
	while (++i < height)
	{
		point_arr[i] = malloc(sizeof(float *) * width);
		j = -1;
		while (++j < width)
		{
			point_arr[i][j] = malloc(sizeof(float) * 3);
			point_arr[i][j][0] = j * scale;
			point_arr[i][j][1] = mlx->map->z_coord[i][j][0] * scale;
			point_arr[i][j][2] = i * scale;
		}
	}
	return (point_arr);
}
