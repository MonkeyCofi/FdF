#include "fdf.h"

int	get_t(int color)
{
	return ((color >> 24) & 0xFF);
}

int	get_red(int color)
{
	return ((color >> 16) & 0xFF);
}

int	get_green(int color)
{
	return ((color >> 8) & 0xFF);
}

int get_blue(int color)
{
	return ((color) & 0xFF);
}

int     get_color(t_mlx *mlx, int i, int j)
{
	int	color;

	if (mlx->map->z_coord[i][j][1] != -1)
	{
		color = mlx->map->z_coord[i][j][1];
		return (get_t(color) << 24 | get_red(color) << 16 | get_green(color) << 8 | get_blue(color));
	}
	return (0x00FFFFFF);
}
float	get_current_percent(float start, float end, float current)
{
	//if (start != end)
	//	return ((current - start) / (end - start));
	//return (0);
	 double	distance_1;
	 double	distance_2;
	
	 distance_1 = current - start;
	 distance_2 = end - start;
	 if (distance_2 == 0)
	 	return (1.0);
	 return (distance_1 / distance_2);
}

int	gradient_color(t_point start, t_point end, float progress)
{
	int	r;
	int	g;
	int	b;

	r = round(1 - progress) * get_red(start.color) + progress * get_red(end.color);
	g = round(1 - progress) * get_green(start.color) + progress * get_green(end.color);
	b = round(1 - progress) * get_blue(start.color) + progress * get_blue(end.color);
	return (r << 16 | g << 8 | b);
}
