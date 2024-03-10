/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:41:08 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/07 16:32:58 by pipolint         ###   ########.fr       */
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

void	zoom(void *mlx, float scale, int code)
{
	t_mlx	*fdf;
	float	centers[3];

	fdf = (t_mlx *)mlx;
	centers[0] = fdf->points[fdf->map->height / 2][fdf->map->width / 2][0];
	centers[1] = fdf->points[fdf->map->height / 2][fdf->map->width / 2][1];
	centers[2] = fdf->points[fdf->map->height / 2][fdf->map->width / 2][2];
	if (code == 61)
	{
		move_to_origin(fdf);
		for (int i = 0; i < fdf->map->height; i++)
		{
			for (int j = 0; j < fdf->map->width; j++)
			{
				fdf->points[i][j][0] *= 1.2;
				fdf->points[i][j][1] *= 1.2;
				fdf->points[i][j][2] *= 1.2;
			}
		}
		move_shape_back(fdf, centers[0], centers[2], centers[1]);
		draw_image(fdf);
	}
	else if (code == 45)
	{
		move_to_origin(fdf);
		for (int i = 0; i < fdf->map->height; i++)
		{
			for (int j = 0; j < fdf->map->width; j++)
			{
				fdf->points[i][j][0] *= 0.9;
				fdf->points[i][j][1] *= 0.9;
				fdf->points[i][j][2] *= 0.9;
			}
		}
		move_shape_back(fdf, centers[0], centers[2], centers[1]);
		draw_image(fdf);
	}
	(void)scale;
}

//void	rotate_shape(t_mlx *mlx)
//{
//	int	half_x;
//	int	half_y;

	
//}
