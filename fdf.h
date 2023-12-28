/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:57:49 by pipolint          #+#    #+#             */
/*   Updated: 2023/12/28 20:58:41 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define HEIGHT 1080
# define WIDTH 1920

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_map
{
	int	height;
	int	width;
	int	***array;
}	t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_window;
	t_data	*img;
	t_map	*map;
}	t_mlx;

void	validate_map(t_map *map, char *file);

// init
t_mlx	*init_mlx();
void	init_map(t_mlx **mlx);
int		ft_atoi_base(char *str, char *base);

#endif