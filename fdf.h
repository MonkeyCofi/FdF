/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:57:49 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/07 16:38:53 by pipolint         ###   ########.fr       */
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

//# define HEIGHT 320
//# define WIDTH 640
# ifdef __APPLE__
#  define HEIGHT 1080
#  define WIDTH 1920
#  define APP 1
# else
#  define HEIGHT 320
#  define WIDTH 640
#  define APP 0
# endif

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_cam
{
	int	zoom;
}	t_cam;

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
	float	***points;
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
float	***return_array(t_mlx *mlx, int height, int width, int scale);

// temp
/* void	pixel_put(t_data *img, int x, int y, unsigned int color); */
void	pixel_put(t_mlx *mlx, int x, int y, int color);
//void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend);
void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend, int color);
// void	draw_line(t_mlx *mlx, t_point one, t_point two, int color);
//void	draw(t_mlx *mlx);
void	draw(t_mlx *mlx);

/*	manipulate	*/
float	**matrix_x(float angle);
float	**matrix_y(float angle);
float	**matrix_z(float angle);
float	**return_matrix(char axis, float angle);
void	apply_transformation(float ***arr, float **matrix, int height, int width);

/*	hooks	*/
int		escape(t_mlx *mlx);
int		get_key_pressed(int keycode, t_mlx *mlx, int scale);
int     get_color(t_mlx *mlx, int i, int j);
int     draw_image(t_mlx *mlx);
int		translate(t_mlx *mlx, int keycode);
void	rotate_shape(t_mlx *mlx, int keycode);

void	zoom(void *mlx, float scale, int code);
int		get_mouse_function(int code, int scale, void *param);

/*	transform	*/

#endif
