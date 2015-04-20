/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 14:22:50 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 16:01:20 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int					gere_motion(int x, int y, t_env *env)
{
	static int		t_x = WIDTH / 2;

	if (x < WIDTH - 1 && x > 0)
	{
		DIRECTION += CST_A * BLOCK / 4 * (x - t_x);
		t_x = x;
	}
	if (y > 0 && y < HEIGHT)
		OFF = (HEIGHT / 2 - y) * 5;
	if (x == WIDTH - 1)
		DIRECTION += CST_A * BLOCK * (x - t_x);
	if (x == 0)
		DIRECTION += CST_A * BLOCK * (x - t_x);
	REDRAW = 1;
	return (1);
}

int					gere_mouse(int y, t_env *env)
{
	if (y > 0)
		ANGLE = 0.523;
	else
		ANGLE = 1.0471975512;
	REDRAW = 1;
	return (1);
}
