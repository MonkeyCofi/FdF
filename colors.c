#include "fdf.h"

int     get_color(t_mlx *mlx, int i, int j)
{
	if (mlx->map->z_coord[i][j][1] != -1)
		return (mlx->map->z_coord[i][j][1]);
	return (0xFFFFFF);
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

float	get_current_percent(float start, float end, float current)
{
	if (start != end)
		return ((current - start) / (end - start));
	return (0);
	// double	distance_1;
	// double	distance_2;
	//
	// distance_1 = current - start;
	// distance_2 = end - start;
	// if (distance_2 == 0)
	// 	return (1.0);
	// return (distance_1 / distance_2);
}

int	gradient_color(int start, int end, float progress)
{
	int	r;
	int	g;
	int	b;

	// r = round(1 - progress) * get_red(start) + progress * get_red(end);
	r = get_red(start) + (get_red(end) - get_red(start)) * progress;
	g = round(1 - progress) * get_green(start) + progress * get_green(end);
	b = round(1 - progress) * get_blue(start) + progress * get_blue(end);
	return (r << 16 | g << 8 | b);
}
