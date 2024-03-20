/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:55:55 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/20 15:30:55 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *filename)
{
	char	**column;
	char	*line;
	int		n_columns;
	int		file;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	n_columns = 0;
	line = get_next_line(file);
	column = ft_split(line, ' ');
	while (column[n_columns])
	{
		n_columns++;
		free(column[n_columns]);
	}
	free(column);
	free(line);
	close(file);
	return (n_columns);
}

int	get_height(char *filename)
{
	char	*line;
	int		file;
	int		rows;

	rows = 0;
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		rows++;
		free(line);
	}
	if (line)
		free(line);
	close(file);
	return (rows);
}

static void	fill_color(char **coords, int **z, int i, int j)
{
	char	*temp;

	temp = coords[i];
	coords[i] = standardize_color(&coords[i][j]);
	free(temp);
	z[i][1] = ft_atoi_base(&coords[i][j], "0123456789abcdef");
}

void	get_coords(char *line, int width, int **z)
{
	char	**coords;
	int		i;
	int		j;

	coords = ft_split(line, ' ');
	i = -1;
	while (coords[++i] && i < width)
	{
		j = 0;
		z[i] = malloc(sizeof(int) * 2);
		if (!z[i])
			free_d_strline(line, coords, \
				"Could not malloc for number array", 1);
		z[i][0] = ft_atoi(coords[i]);
		while (coords[i][j] != ',' && coords[i][j])
			j++;
		if (coords[i][j] == ',')
			fill_color(coords, z, i, j);
		else
			z[i][1] = -1;
	}
	free_d_strline(NULL, coords, NULL, 0);
}

void	parse_map(char *file, t_map *map)
{
	char	*line;
	int		op_file;
	int		i;

	op_file = open(file, O_RDONLY);
	if (op_file < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(op_file);
	if (!line)
	{
		close(op_file);
		error_and_free(map, NULL, "Map is empty");
	}
	map->height = get_height(file);
	map->width = get_width(file);
	map->z_coord = malloc(sizeof(int **) * map->height);
	i = -1;
	while (line)
	{
		map->z_coord[++i] = malloc(sizeof(int *) * map->width);
		get_coords(line, map->width, map->z_coord[i]);
		free(line);
		line = get_next_line(op_file);
	}
}
