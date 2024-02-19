/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:57:49 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/19 20:26:16 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

// temp includes
# include <stdio.h>
# include <math.h>

# define HEIGHT 320
# define WIDTH 640

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
	int	***z_coord;
}	t_map;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
}	t_line;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	t_map	*map;
}	t_mlx;

//void	parse_map(t_map *map, char *file);
void	parse_map(char *file, t_map *map);

// init
//t_mlx	*init_mlx();
void	init_mlx(t_mlx *mlx);
//void	init_map(t_mlx **mlx);
void	init_map(t_mlx *mlx);
int		ft_atoi_base(char *str, char *base);

// temp
/* void	pixel_put(t_data *img, int x, int y, unsigned int color); */
void	pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend);
//void	draw_line(t_mlx *mlx, t_point one, t_point two);
void	draw(t_mlx *mlx);

#endif
