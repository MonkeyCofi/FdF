/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:32:58 by pipolint          #+#    #+#             */
/*   Updated: 2023/12/28 20:03:33 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*init_mlx()
{
	t_mlx		*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		free (mlx);
		return (NULL);
	}
	mlx->mlx_window = mlx_new_window(&mlx->mlx, WIDTH, HEIGHT, "FdF");
	if (!mlx->mlx_window)
	{
		free(mlx);
		return (NULL);
	}
	mlx->img->img = mlx_new_image(&mlx->mlx, WIDTH, HEIGHT);
	if (!mlx->img->img)
	{
		free(mlx);
		return (NULL);
	}
	return (mlx);
}

void	init_map(t_mlx **mlx)
{
	(*mlx)->map = malloc(sizeof(t_map));
	if (!(*mlx)->map)
		return ;
	(*mlx)->map->height = 0;
	(*mlx)->map->width = 0;
	(*mlx)->map->array = NULL;
	(*mlx)->map->color = NULL;
}