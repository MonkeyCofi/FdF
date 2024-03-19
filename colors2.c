/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:33:16 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/19 15:06:25 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_current_percent(float start, float end, float current)
{
	if (start != end)
		return ((current - start) / (end - start));
	return (0);
}

int	get_color(t_mlx *mlx, int i, int j)
{
	int	color;

	if (mlx->map->z_coord[i][j][1] != -1)
	{
		color = mlx->map->z_coord[i][j][1];
		return (mlx->map->z_coord[i][j][1]);
	}
	return (0x00FFFFFF);
}
