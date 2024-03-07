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
	float	***new;
	t_mlx	*fdf;

	fdf = (t_mlx *)mlx;
	if (code == 4)
	{
		scale += 1;
		new = malloc(sizeof(float **) * fdf->map->height);
		for (int i = 0; i < fdf->map->height; i++)
		{
			new[i] = malloc(sizeof(float *) * fdf->map->width);
			for (int j = 0; j < fdf->map->width; j++)
			{
				new[i][j] = malloc(sizeof(float) * 3);
				new[i][j][0] = fdf->points[i][j][0] * scale;
				new[i][j][1] = fdf->points[i][j][1] * scale;
				new[i][j][2] = fdf->points[i][j][2] * scale;
				//fdf->points[i][j][0] *= scale;
				//fdf->points[i][j][1] *= scale;
				//fdf->points[i][j][2] *= scale;
			}
		}
		fdf->points = new;
		draw_image(fdf);
	}
	(void)mlx, (void)scale, (void)code, (void)new;
}

//void	rotate_shape(t_mlx *mlx)
//{
//	int	half_x;
//	int	half_y;

	
//}
