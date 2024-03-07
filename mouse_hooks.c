/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:43:08 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/07 16:39:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_mouse_function(int code, int scale, void *param)
{
	if (code == 4 || code == 5)
		zoom(param, scale, code);
	//else
		ft_printf("%d\n", code);
	// scroll up = 5
	// scroll down = 4
	(void)param;
	(void)scale;
	return (0);
}
