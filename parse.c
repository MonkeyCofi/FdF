/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:55:55 by pipolint          #+#    #+#             */
/*   Updated: 2023/12/28 19:16:43 by pipolint         ###   ########.fr       */
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

//void	populate_table(int **nums, t_mlx *mlx, char *line)
//{
//	char	**coords;
//	int		i;
//	int		j;

//	coords = ft_split(line, ' ');
//	i = 0;
//	while (coords[i] && i < mlx->map->width)
//	{
//		nums[i] = malloc(sizeof(int) * 2);
//		if (!nums[i])
//			return ;
//		nums[i][0] = ft_atoi(coords[i]);
//		j = 0;
//		while (coords[i][j] != ',' && coords[i][j])
//			j++;
//		if (coords[i][j] == ',')
//			nums[i][1] = ft_atoi_base(&coords[i][j], "0123456789ABCDEF");
//		else
//			nums[i][1] = -1;
//		free(coords[i]);
//		i++;
//	}
//	if (i != mlx->map->width || coords[i])
//		return ;
//	free(coords);
//}

//void	parse_map(t_map *map, t_mlx *mlx, char *file)
//{
//	char	*str;
//	int		o_file;
//	int		i;

//	map->height = get_height(file);
//	map->width = get_width(file);
//	o_file = open(file, O_RDONLY);
//	if (o_file < 0)
//		return ;
//	map->array = malloc(sizeof(int **) * map->height);
//	if (!map->array)
//		return ;
//	i = 0;
//	while ((str = get_next_line(o_file)) && *str != '\0')
//	{
//		map->array[i++] = malloc(sizeof(int *) * map->width);
//		if (!map->array[i])
//			return ;
//		populate_table(map->array[i], mlx, str);
//		free(str);
//	}
//}

/*

*/
void	populate_table(t_map *map, char *line)
{
	char	**coords;
	int		i;

	coords = ft_split(line, ' ');
	i = 0;
	while (coords[i] && i < map->width)
	{
		
	}
}