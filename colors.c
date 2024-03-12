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
	if (start != end)
		return ((current - start) / (end - start));
	return (0);
}

int	gradient_color(t_point start, t_point end, float progress)
{
	int	r;
	int	g;
	int	b;
	int	t;

	r = get_red(start.color) + progress * (get_red(end.color) - get_red(start.color));
	g = get_green(start.color) + progress * (get_green(end.color) - get_green(start.color));
	b = get_blue(start.color) + progress * (get_blue(end.color) - get_blue(start.color));
	t = get_t(start.color) + progress * (get_t(end.color) - get_t(start.color));
	return (t << 24 | r << 16 | g << 8 | b);
}
