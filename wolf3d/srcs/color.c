/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 16:21:45 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/08 01:43:30 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		hsv_to_rgb(double h, double s, double v)
{
	int				i;
	double			f;
	t_color			test;
	t_color			rgb;

	i = floor(h * 6);
	f = h * 6 - i;
	test = (t_color){v * (1 - s), v * (1 - s * f), v * (1 - s * (1 - f))};
	if (i == 0)
		rgb = (t_color){v, test.b, test.r};
	else if (i == 1)
		rgb = (t_color){test.g, v, test.b};
	else if (i == 2)
		rgb = (t_color){test.r, v, test.b};
	else if (i == 3)
		rgb = (t_color){test.r, test.g, v};
	else if (i == 4)
		rgb = (t_color){test.b, test.r, v};
	else
		rgb = (t_color){v, test.r, test.g};
	return (RGB(0xFE, (int)(rgb.g * 255), (int)(rgb.b * 255)));
}
