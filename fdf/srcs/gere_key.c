/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 23:41:22 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 18:03:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		gere_offset(int keycode, t_env *env)
{
	if (keycode == 65464)
		OFF.y -= 5;
	if (keycode == 65458)
		OFF.y += 5;
	if (keycode == 65462)
		OFF.x += 5;
	if (keycode == 65460)
		OFF.x -= 5;
	if (keycode == 122)
		COEFFZ++;
	if (keycode == 120)
		COEFFZ--;
	if (keycode == 65463 || keycode == 65465 || keycode == 65459 ||
		keycode == 65457)
	{
		OFF = set_point(0, 0, 0);
		get_points(env);
	}
}

void		gere_key3(int keycode, t_env *env)
{
	if (keycode == 65463)
		ANGLEX -= 0.05;
	if (keycode == 65465)
		ANGLEX += 0.05;
	if (keycode == 65459)
		ANGLEZ -= 0.05;
	if (keycode == 65457)
		ANGLEZ += 0.05;
	if (keycode == 65469 && CHOICE == 1)
	{
		CHOICE = 0;
		OFF = set_point(0, 0, 0);
		get_points(env);
	}
	if (keycode == 65455 && CHOICE == 0)
	{
		CHOICE = 1;
		OFF = set_point(0, 0, 0);
		get_points(env);
	}
}

void		gere_key2(int keycode, t_env *env)
{
	if (keycode == 113)
		COLOR += 0x010000;
	if (keycode == 119)
		COLOR += 0x000100;
	if (keycode == 101)
		COLOR += 0x01;
	if (keycode == 97)
		COLOR -= 0x00010000;
	if (keycode == 115)
		COLOR -= 0x00000100;
	if (keycode == 100)
		COLOR -= 0x00000001;
	if (keycode == 65456)
	{
		COEFFZ = 1;
		ANGLEX = 0;
		ANGLEZ = 0;
		CHOICE = 0;
		COLOR = DEF_COLOR;
		C = MIN(WIDTH / (MAX_X + 5), HEIGHT / (MAX_Y + 5));
		C = C ? C : 1;
		OFF = set_point(0, 0, 0);
		get_points(env);
	}
}

int			gere_key(int keycode, t_env *env)
{
	if (keycode == 65307)
	{
		kill_everything(env);
		exit (1);
	}
	if (keycode == 65451)
		C++;
	if (keycode == 65453)
		C = C > 1 ? C - 1 : 1;
	if (keycode == 65461)
	{
		OFF = set_point(0, 0, 0);
		get_points(env);
	}
	gere_key2(keycode, env);
	gere_key3(keycode, env);
	gere_offset(keycode, env);
	draw(env);
	return (0);
}
