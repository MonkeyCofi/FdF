/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:55:55 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/16 17:06:07 by pipolint         ###   ########.fr       */
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
			break;
		rows++;
		free(line);
	}
	if (line)
		free(line);
	close(file);
	return (rows);
}

//void	populate_table(int **z, char *line, int width)
//{
//	char	**cords;
//	int		i;
//	int		index;

//	cords = ft_split(line, ' ');
//	i = 0;
//	while (cords[i] && i < width)
//	{
//		z[i] = malloc(sizeof(int) * 2);
//		if (!z[i])
//			return ;
//		z[i][0] = ft_atoi(cords[i]);
//		index = 0;
//		while (cords[i][index] != ',' && cords[i][index])
//			index++;
//		if (cords[i][index] == ',')
//			z[i][1] = ft_atoi_base(&cords[i][index + 1], "0123456789ABCDEF");
//		else
//			z[i][1] = -1;
//		free(cords[i]);
//		i++;
//	}
//	free(cords);
//}

//void	parse_map(t_map *map, char *file)
//{
//	int		f;
//	char	*line;
//	int		i;

//	f = open(file, O_RDONLY);
//	if (f == -1)
//		return ;
//	map->height = get_height(file);
//	map->width = get_width(file);
//	map->z_coord = malloc(sizeof(int **) * map->height);
//	i = 0;
//	while (1)
//	{
//		map->z_coord[i] = malloc(sizeof(int *) * map->width);
//		line = get_next_line(f);
//		if (!line || !*line)
//			return ;
//		 populate_table(map->z_coord[i++], line, map->width);
//		 free(line);
//	}
//	close(f);
//}

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
			exit(EXIT_FAILURE);
		ft_printf("%d\n", ft_atoi(coords[i]));
		z[i][0] = ft_atoi(coords[i]);
		ft_printf("test\n");
		while (coords[i][j] != ',')
			j++;
		if (coords[i][j] == ',')
			z[i][1] = ft_atoi_base(&coords[i][j], "0123456789abcdef");
		else
			z[i][1] = 0;
		free(coords[i]);
	}
	free(coords);
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
	map->height = get_height(file);
	map->width = get_width(file);
	map->z_coord = malloc(sizeof(int **) * map->height);
	i = 0;
	while (line)
	{
		map->z_coord = malloc(sizeof(int *) * map->width);
		get_coords(line, map->width, map->z_coord[i++]);
		free(line);
		line = get_next_line(op_file);
	}
}