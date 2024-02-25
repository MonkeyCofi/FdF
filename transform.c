/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:41:08 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/25 20:19:13 by pipolint         ###   ########.fr       */
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

void	zoom(t_mlx *mlx, float scale, int code)
{	
	if (code == 4)
	{
		scale += 1;
		for (int i = 0; i < mlx->map->height; i++)
		{
			for (int j = 0; j < mlx->map->width; j++)
			{
				mlx->points[i][j][0] *= scale;
				mlx->points[i][j][1] *= scale;
				mlx->points[i][j][2] *= scale;
			}
		}
		//mlx->points = return_array(mlx, mlx->map->height, mlx->map->width, scale);
		//draw_image(mlx);
	}
	(void)mlx, (void)scale, (void)code;
}

//void	rotate_shape(t_mlx *mlx)
//{
//	int	half_x;
//	int	half_y;

	
//}
