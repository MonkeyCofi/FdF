/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:45:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/17 16:37:41 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*p;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		p = mlx->img.addr + y * mlx->img.line_length + x * (mlx->img.bpp / 8);
		*(int *)p = color;
	}
}

int	keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		mlx_destroy_window(mlx->mlx, mlx->mlx_window);
	(void)mlx;
	ft_printf("%d\n", keycode);
	exit(EXIT_SUCCESS);
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
	ft_printf("Map height %d\n", mlx.map->height);
	ft_printf("Map width %d\n", mlx.map->width);
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
