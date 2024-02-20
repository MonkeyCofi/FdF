/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:45:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/19 12:55:14 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	pixel_put(t_data *img, int x, int y, unsigned int color)
// {
// 	char	*pixel;
//
// 	pixel = img->addr + (y * img->line_length) + (x * (img->bpp / 8));
// 	*(unsigned int *)pixel = color;
// }

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*p;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		p = mlx->img.addr + (y * mlx->img.line_length) + (x * (mlx->img.bpp / 8));
		*(unsigned int *)p = color;
	}
}

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 53 || keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
		exit(EXIT_SUCCESS);
	}
	ft_printf("%d\n", keycode);
	return (0);
}

int main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		ft_printf("Usage: ./fdf [mapfile]\n");
		exit(EXIT_FAILURE);
	}
	init_mlx(&mlx);
	init_map(&mlx);
	parse_map(av[1], mlx.map);
	// for chromebook only
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			pixel_put(&mlx, j, i, 0x000000);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_window, mlx.img.img, 0, 0);
	}
	for (int i = 0; i < mlx.map->height; i++)
	{
		for (int j = 0; j < mlx.map->width; j++)
			ft_printf("%2d ", mlx.map->z_coord[i][j][0]);
		ft_printf("\n");
	}
	// block of code to zoom into image
	t_cam cam;
	cam.zoom = 2;
	mlx.map->height *= cam.zoom;
	mlx.map->width *= cam.zoom;
	draw(&mlx);
	mlx_key_hook(mlx.mlx_window, keypress, &mlx.mlx);
	mlx_loop(mlx.mlx);
}

//int main(int ac, char **av)
//{
//	t_mlx	*mlx;

//	if (ac != 2)
//		return (-1);
//	mlx = init_mlx();
//	init_map(&mlx);
//	parse_map(mlx->map, av[1]);
//	mlx_key_hook(mlx->mlx_window, keypress, &mlx->mlx);
//	pixel_put(&mlx->img, 0, 0, 0xFF0000);
//	mlx_loop(mlx);
//	free(mlx->mlx);
//	(void)av;
//}

