#include "fdf.h"

void    top_down(t_mlx *mlx)
{
        int             height;
        int             width;
        float   **matrix;
        float   centers[3];

        height = mlx->map->height;
        width = mlx->map->width;
        if (mlx->points)
                free(mlx->points);
        mlx->points = return_array(mlx, height, width, mlx->camera->zoom);
        centers[0] = mlx->points[height / 2][width / 2][0];
        centers[1] = mlx->points[height / 2][width / 2][2];
        centers[2] = mlx->points[height / 2][width / 2][1];
        move_to_origin(mlx);
        matrix = return_matrix('x', 0 * (3.1415 / 180));
        apply_transformation(mlx->points, matrix, height, width);
        free_matrix(matrix);
        move_shape_back(mlx, centers[0], centers[1], centers[2]);
        draw_image(mlx);
}

void	side_view(t_mlx *mlx)
{
	int             height;
	int             width;
	float   **matrix;
	float   centers[3];
	
	height = mlx->map->height;
	width = mlx->map->width;
	if (mlx->points)
	        free(mlx->points);
	mlx->points = return_array(mlx, height, width, mlx->camera->zoom);
	centers[0] = mlx->points[height / 2][width / 2][0];
	centers[1] = mlx->points[height / 2][width / 2][2];
	centers[2] = mlx->points[height / 2][width / 2][1];
	move_to_origin(mlx);
	matrix = return_matrix('x', -90 * (3.1415 / 180));
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	move_shape_back(mlx, centers[0], centers[1], centers[2]);
	matrix = return_matrix('z', 90 * (3.1415 / 180));	
	apply_transformation(mlx->points, matrix, height, width);
	free_matrix(matrix);
	move_shape_back(mlx, centers[0], centers[1], centers[2]);
	draw_image(mlx);
}
