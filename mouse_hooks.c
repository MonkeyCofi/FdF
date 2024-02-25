/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:43:08 by pipolint          #+#    #+#             */
/*   Updated: 2024/02/25 20:06:47 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_mouse_function(int code, int scale, t_mlx *mlx)
{
	if (code == 4)
	{
		zoom(mlx, scale, code);
	}
	else if (code == 5)
		ft_printf("Zoom in\n");
	// scroll up = 5
	// scroll down = 4
	(void)mlx;
	(void)scale;
	return (0);
}
