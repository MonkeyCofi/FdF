/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:41:08 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/11 14:57:50 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     draw_image(t_mlx *mlx)
{
        if (mlx->img.img)
                mlx_destroy_image(mlx->mlx, mlx->img.img);
        mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
        mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
        draw(mlx);
        return (0);
}

void	mult_by_scale(t_mlx *mlx, float scale)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
		{
			mlx->points[i][j][0] *= scale;
			mlx->points[i][j][1] *= scale;
			mlx->points[i][j][2] *= scale;
		}
	}
}

void	zoom(void *mlx, float scale, int code)
{
	t_mlx	*fdf;
	float	centers[3];

	fdf = (t_mlx *)mlx;
	centers[0] = fdf->points[fdf->map->height / 2][fdf->map->width / 2][0];
	centers[1] = fdf->points[fdf->map->height / 2][fdf->map->width / 2][1];
	centers[2] = fdf->points[fdf->map->height / 2][fdf->map->width / 2][2];
	if (code == PLUS)
	{
		move_to_origin(fdf);
		mult_by_scale(fdf, 1.1);
		move_shape_back(fdf, centers[0], centers[2], centers[1]);
		draw_image(fdf);
	}
	else if (code == MINUS)
	{
		move_to_origin(fdf);
		mult_by_scale(fdf, 0.9);
		move_shape_back(fdf, centers[0], centers[2], centers[1]);
		draw_image(fdf);
	}
	(void)scale;
}

void	transform_shape(t_mlx *mlx, float *axes, float *angle, char axis)
{
	move_to_origin(mlx);
	apply_transformation(mlx->points, return_matrix(axis, ((*angle) - 4) * (3.1415 / 180)), mlx->map->height, mlx->map->width);
	move_shape_back(mlx, axes[0], axes[1], axes[2]);
}