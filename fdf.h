/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:57:49 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/11 00:47:17 by pipolint         ###   ########.fr       */
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
#  define APP 1
#  define HEIGHT 1080
#  define WIDTH 1920
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define Q 12
#  define E 14
#  define R 15
#  define PLUS 24
#  define MINUS 27
# else
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define Q 113
#  define E 101
#  define HEIGHT 720
#  define WIDTH 1080
#  define APP 0
# endif

typedef enum	s_rots
{
	LEFT,
	UP,
	DOWN,
	RIGHT
}	t_rots;

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
	float	zoom;
	float	x_offset;
	float	y_offset;
	float	z_offset;
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
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_window;
	float	***points;
	t_data	img;
	t_map	*map;
	t_cam	*camera;
}	t_mlx;

//void	parse_map(t_map *map, char *file);
void	parse_map(char *file, t_map *map);

/*		init		*/
void	init_camera(t_mlx *mlx);
void	init_mlx(t_mlx *mlx);
//void	init_map(t_mlx **mlx);
void	init_map(t_mlx *mlx);
int		ft_atoi_base(char *str, char *base);
float	***return_array(t_mlx *mlx, int height, int width, int scale);

// temp
/* void	pixel_put(t_data *img, int x, int y, unsigned int color); */
void	pixel_put(t_mlx *mlx, int x, int y, int color);
//void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend);
/* void	draw_line(t_mlx *mlx, int xstart, int xend, int ystart, int yend, int color); */
void	draw_line(t_mlx *mlx, t_point start, t_point end, int color);
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

int		get_color(t_mlx *mlx, int i, int j);
	float	get_current_percent(float start, float end, float current);
int		gradient_color(int start, int end, float progress);

t_point	return_point(float x, float y);
/*	transform	*/
void	move_to_origin(t_mlx *mlx);
void	move_shape_back(t_mlx *mlx, float x_cent, float y_cent, float z_cent);

/*		map check	*/
void	valid_map(char *map);
char	*standardize_color(char *color);
void	error_and_free(t_map *map, t_mlx *mlx, char *error_message);
void	free_double_str_line(char *line, char **double_str, char *error_message);

/*		Utils		*/
int		return_minimum(int a, int b);
int		absolute(int value);

#endif
