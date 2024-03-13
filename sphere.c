#include "fdf.h"

int	disco_ball(t_mlx *mlx)
{
	float	centers[3];

	if (mlx->bon)
	{
		centers[0] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][0];
		centers[1] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][1];
		centers[2] = mlx->points[mlx->map->height / 2][mlx->map->width / 2][2];
		move_to_origin(mlx);
		apply_transformation(mlx->points, return_matrix('z', 0.0010 * (180 / 3.1415)), mlx->map->height, mlx->map->width);
		move_shape_back(mlx, centers[0], centers[2], centers[1]);
		draw_image(mlx);
	}

	// }
	return (0);
}
