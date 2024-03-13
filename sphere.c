#include "fdf.h"

void	draw_sphere(t_mlx *mlx);

void	sphereize(t_mlx *mlx)
{
	float	r;
	float	t[3];

	for (int i = 0; i < mlx->map->height; i++)
	{
		for (int j = 0; j < mlx->map->width; j++)
		{
			float x = mlx->points[i][j][2];
			t[0] = pow(mlx->points[i][j][0], 2);
			t[1] = pow(mlx->points[i][j][1], 2);
			t[2] = pow(mlx->points[i][j][2], 2);
			r = sqrt(t[0] + t[1] + t[2]);
			mlx->points[i][j][0] = r;
			mlx->points[i][j][2] = atan(mlx->points[i][j][2] / x) * (180 / 3.1415);
			mlx->points[i][j][1] = acos(mlx->points[i][j][1] / r) * (180 / 3.1415);
		}
	}
	draw_sphere(mlx);
}

void	draw_sphere(t_mlx *mlx)
{
	for (int i = 0; i < mlx->map->height; i++)
	{
		for (int j = 0; j < mlx->map->width; j++)
		{
				apply_transformation(mlx->points, return_matrix('y', mlx->points[i][j][1]), mlx->map->height, mlx->map->width);
			pixel_put(mlx, i, j, 0xFF0000);
			// for (int s = 0; s < mlx->points[i][j][0]; s++)
			// {
			// 	apply_transformation(mlx->points, return_matrix('z',mlx->points[i][j][2]), mlx->map->height, mlx->map->width);
			//
			// }
		}
	}
}
