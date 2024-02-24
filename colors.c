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

int		intify_color(int color)
{
	int	new_color;

	new_color = 0xFF;
	(void)color;
	(void)new_color;
	return (1);
}
