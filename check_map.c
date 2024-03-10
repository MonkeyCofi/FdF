/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 20:18:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/11 01:32:21 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	valid_map(char *map)
{
	int	file;

	file = open(map, O_RDONLY);
	if (file == -1)
	{
		ft_putendl_fd("Couldn't open file", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(&map[(ft_strlen(map) - 4)], ".fdf", 4))
	{
		ft_putendl_fd("Map should be in .fdf format", 2);
		exit(EXIT_FAILURE);
	}
}

char	*standardize_color(char *color)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strdup(color);
	while (str[++i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}
	return (str);
}

void	error_and_free(t_map *map, t_mlx *mlx, char *error_message)
{
	if (mlx)
		free(mlx);
	if (map)
		free(map);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	free_double_str_line(char *line, char **double_str, char *error_message)
{
	int	i;

	i = -1;
	if (double_str)
	{
		while (double_str[++i])
			free(double_str[i]);
		free(double_str);
	}
	if (line)
		free(line);
	ft_putendl_fd(error_message, 2);
	exit(EXIT_FAILURE);
}

void	check_map(char *filename)
{
	int		file;
	int		i;
	char	*line;

	file = open(filename, O_RDONLY);
	if (file == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(file);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == ' ')
				if (line[i + 1] == '\0')
					exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(file);
		
	}
}
