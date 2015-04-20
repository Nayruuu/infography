/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 15:09:40 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/26 01:54:23 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point			mult_comp(const t_point p1, const t_point p2)
{
	t_point				temp;

	temp.x = p1.x * p2.x - p1.y * p2.y;
	temp.y = p1.x * p2.y + p1.y * p2.x;
	return (temp);
}

t_point			add_complex(const t_point p1, const t_point p2)
{
	t_point				new;

	new.x = p1.x + p2.x;
	new.y = p1.y + p2.y;
	return (new);
}

t_point			power_complex(const t_point p1, const int power)
{
	int			i;
	t_point		new;

	i = 1;
	new = SET(p1.x, p1.y);
	while (i < power)
	{
		new = mult_comp(new, p1);
		i++;
	}
	return (new);
}

t_point			mult_const(t_point p1, t_ld constante)
{
	t_point				new;

	new.x = p1.x * constante;
	new.y = p1.y * constante;
	return (new);
}
