/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:35:49 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/19 15:08:21 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(float **matrix)
{
	int	i;

	i = -1;
	while (++i < 3)
		free(matrix[i]);
	free(matrix);
}

void	free_points(t_mlx *mlx, float ***points)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->map->height)
	{
		j = -1;
		while (++j < mlx->map->width)
			free(points[i][j]);
		free(points[i]);
	}
	free(points);
}

void	free_triple_int(t_mlx *mlx, int ***t_int)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map->height)
	{
		j = 0;
		while (j < mlx->map->width)
		{
			free(t_int[i][j]);
			j++;
		}
		free(t_int[i]);
		i++;
	}
	free(t_int);
}
