/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:52:24 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/31 16:24:23 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getnbr(const char *str)
{
	int	neg;
	int	value;

	neg = 0;
	value = 0;
	if (str)
	{
		if (*str == '+')
			str++;
		if (*str == '-')
		{
			neg++;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			value = (value * 10) + (*str - '0');
			str++;
		}
		if (*str < 0 || *str > 9)
			exit(!ft_putstr_fd(_ERROR_3, 2));
		return (!neg ? value : -value);
	}
	else
		return (0);
}
