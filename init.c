/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:32:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/16 14:56:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit(EXIT_FAILURE);
	mlx->mlx_window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FdF");
	if (!mlx->mlx_window)
		exit(EXIT_FAILURE);
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img.img)
		exit(EXIT_FAILURE);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
}

//t_mlx	*init_mlx()
//{
//	t_mlx		*mlx;

//	mlx = malloc(sizeof(t_mlx));
//	if (!mlx)
//		return (NULL);
//	mlx->mlx = mlx_init();
//	if (!mlx->mlx)
//	{
//		free (mlx);
//		return (NULL);
//	}
//	mlx->mlx_window = mlx_new_window(&mlx->mlx, WIDTH, HEIGHT, "FdF");
//	if (!mlx->mlx_window)
//	{
//		free(mlx);
//		return (NULL);
//	}
//	mlx->img.img = mlx_new_image(&mlx->mlx, WIDTH, HEIGHT);
//	if (!mlx->img.img)
//	{
//		free(mlx);
//		return (NULL);
//	}
//	mlx->img.addr = mlx_get_data_addr(&mlx->img, &mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
//	return (mlx);
//}

void	init_map(t_mlx *mlx)
{
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
		return ;
	mlx->map->height = 0;
	mlx->map->width = 0;
	mlx->map->z_coord = NULL;
}
