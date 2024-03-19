/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:51:29 by pipolint          #+#    #+#             */
/*   Updated: 2024/03/19 15:08:58 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include "libft/libft.h"

int	base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			break ;
		i++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	i;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_length;
	int	result;
	int	index;

	result = 0;
	base_length = ft_strlen(base);
	index = 0;
	if (check_base(base))
	{
		if (!ft_strncmp(str, "0x", 2) && \
			!ft_strncmp(base, "0123456789ABCDEF", 16))
			index += 2;
		while (str[index])
		{
			result = (result * base_length) + base_value(str[index], base);
			index++;
		}
	}
	return (result);
}
