/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:17:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/19 16:26:26 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void		put_pix_to_img(t_env *env, int x, int y, unsigned int color)
{
	if (x < WIDTH && x >= 0 && y >= 0 && y < HEIGHT)
	{
		DATA[x * 4 + 3 + LINE_S * y] = (color & 0xFF000000) >> 24;
		DATA[x * 4 + 2 + LINE_S * y] = (color & 0xFF0000) >> 16;
		DATA[x * 4 + 1 + LINE_S * y] = (color & 0xFF00) >> 8;
		DATA[x * 4 + 0 + LINE_S * y] = (color & 0xFF);
	}
}
