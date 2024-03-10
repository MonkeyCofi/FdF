/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 00:28:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/11 00:34:33 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	return_minimum(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		absolute(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}