/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:53:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/12 17:52:27 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	**matrix_x(float angle)
{
	float	**matrix;
	int		i;
	int		j;

	matrix = malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		matrix[i] = malloc(sizeof(float) * 3);
		while (++j < 3)
		{
			if (i == 0 && j == 0)
				matrix[i][j] = 1;
			else if (i == 0 || j == 0)
				matrix[i][j] = 0;
			else if (i == 1 && j == 2)
				matrix[i][j] = sin(angle) * -1;
			else if (i == 2 && j == 1)
				matrix[i][j] = sin(angle);
			else
				matrix[i][j] = cos(angle);
		}		
	}
	return (matrix);
}

float	**matrix_y(float angle)
{
	float	**matrix;
	int		i;
	int		j;

	matrix = malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
	{
		matrix[i] = malloc(sizeof(float) * 3);
		j = -1;
		while (++j < 3)
		{
			if ((i == 0 && j == 0) || (i == 2 && j == 2))
				matrix[i][j] = cos(angle);
			else if (i == 1 && j == 1)
				matrix[i][j] = 1;
			else if (i == 0 && j == 2)
				matrix[i][j] = sin(angle);
			else if (i == 2 && j == 0)
				matrix[i][j] = sin(angle) * -1;
			else
				matrix[i][j] = 0;
		}
	}
	return (matrix);
}

float	**matrix_z(float angle)
{
	float	**matrix;
	int		i;
	int		j;

	matrix = malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
	{
		matrix[i] = malloc(sizeof(float) * 3);
		j = -1;
		while (++j < 3)
		{
			if (i == 2 && j == 2)
				matrix[i][j] = 1;
			else if (j == 2 || i == 2)
				matrix[i][j] = 0;
			else if (i == 0 && j == 1)
				matrix[i][j] = sin(angle) * -1;
			else if (i == 1 && j == 0)
				matrix[i][j] = sin(angle);
			else
				matrix[i][j] = cos(angle);
		}
	}
	return (matrix);
}

float	**return_matrix(char axis, float angle)
{
	if (axis == 'x')
		return (matrix_x(angle));
	else if (axis == 'y')
		return (matrix_y(angle));
	else
		return (matrix_z(angle));

}
void	apply_transformation(float ***arr, float **matrix, int height, int width)
{
	int		i;
	int		j;
	int		k;
	int		l;
	float	simp[3];

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			k = -1;
			while (++k < 3)
			{
				l = -1;
				simp[k] = 0;
				while (++l < 3)
					simp[k] += arr[i][j][l] * matrix[k][l];
			}
			while (k--)
				arr[i][j][2 - k] = simp[2 - k];
		}
	}
}
