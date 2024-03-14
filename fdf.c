/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:45:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/14 21:10:03 by pipolint         ###   ########.fr       */
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

//void	iso(t_mlx *mlx, float ***point_array)
//{
//	/*										best projections															*/
//	 apply_transformation(point_array, return_matrix('y', 45 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
//	 apply_transformation(point_array, return_matrix('x', -62 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
//}

void	parallel(t_mlx *mlx)
{
	 apply_transformation(mlx->points, return_matrix('y', 300 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
	 apply_transformation(mlx->points, return_matrix('x', -30 * (3.1415 / 180)), mlx->map->height, mlx->map->width);
}

float	get_default_scale(t_mlx *mlx)
{
	float	scale_height;
	float	scale_width;
	float	scale_z_height;
	float	factor;

	//factor = (float)get_z_max(mlx) * 0.25;
	factor = 1.3;
	scale_height = HEIGHT / (mlx->map->height * factor);
	scale_width = WIDTH / (mlx->map->width * factor);
	scale_z_height = HEIGHT / (get_z_max(mlx) * factor);
	if (scale_height > scale_width)
		return (scale_height);
	else if (scale_width > scale_height)
		return (scale_width);
	return (scale_z_height);
}

int main(int ac, char **av)
{
	t_mlx	mlx;
	
	if (ac < 2)
	{
		ft_printf("Usage: ./fdf [mapfile]\n");
		exit(EXIT_FAILURE);
	}
	valid_map(av[1]);
	init_mlx(&mlx);
	parse_map(av[1], mlx.map);
	get_default_color(&mlx);
	mlx.points = return_array(&mlx, mlx.map->height, mlx.map->width, get_default_scale(&mlx));
	if (APP)
		mlx_hook(mlx.mlx_window, 2, 0, get_key_pressed, &mlx);
	else
		mlx_hook(mlx.mlx_window, 2, 1L << 0, get_key_pressed, &mlx);
	init_camera(&mlx);
	get_default_position(&mlx, mlx.points);
	mlx_loop_hook(mlx.mlx, disco_ball, &mlx);
	draw(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
