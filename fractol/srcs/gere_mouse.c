/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 14:22:50 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:55:39 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			get_iter(long double zoom, int preci)
{
	int				i;

	i = 0;
	while ((zoom /= 1.3) > 1)
		i++;
	return (i + 130 + preci);
}

static int			gere_wheel(int keycode, int x, int y, t_env *env)
{
	t_point			pos;
	t_point			temp;

	if (keycode == 4 || (keycode == 5 && ZOOM.x > 100 && ZOOM.y > 100))
	{
		pos = SET(OFF.x + x, OFF.y + y);
		temp = SET(pos.x / ZOOM.x, pos.y / ZOOM.y);
		ZOOM.x = keycode == 4 ? ZOOM.x * 1.05 : ZOOM.x / 1.05;
		ZOOM.y = keycode == 4 ? ZOOM.y * 1.05 : ZOOM.y / 1.05;
		OFF.x += (temp.x - (pos.x / ZOOM.x)) * ZOOM.x;
		OFF.y += (temp.y - (pos.y / ZOOM.y)) * ZOOM.y;
		MAX_ITER = get_iter(GET_MAX(ZOOM.x, ZOOM.y), PRECI);
		REDRAW = 1;
	}
	return (1);
}

int					gere_click(int keycode, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (keycode == 1 && MOUSE_ON)
		MOUSE_ON = 0;
	if (keycode == 3 && MOUSE_2_ON)
		MOUSE_2_ON = 0;
	(void)env;
	return (1);
}

int					gere_motion(int x, int y, t_env *env)
{
	static int		mouse_x = 0;
	static int		mouse_y = 0;

	if (CHOICE && !LOCK_CAM && !MOUSE_ON)
	{
		POS_X = x;
		POS_Y = y;
		REDRAW = 1;
	}
	if (MOUSE_ON)
	{
		OFF.x += mouse_x - x;
		OFF.y += mouse_y - y;
		REDRAW = 1;
	}
	if (MOUSE_2_ON)
	{
		MODE += (mouse_x - x) / 2;
		MODE += (mouse_y - y) / 2;
		MODE = (MODE < 0) ? 0 : MODE;
		REDRAW = 1;
	}
	mouse_x = x;
	mouse_y = y;
	return (1);
}

int					gere_mouse(int keycode, int x, int y, t_env *env)
{
	if (keycode == 1)
		MOUSE_ON = 1;
	if (keycode == 3)
		MOUSE_2_ON = 1;
	gere_wheel(keycode, x, y, env);
	return (1);
}
