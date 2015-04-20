/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unity.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:32:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:40:29 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			get_unity_points(t_env *env)
{
	ZOOM.x = WIDTH / (2 + 2);
	ZOOM.y = HEIGHT / (2 + 2);
	MIN = SET(-1.4 * ZOOM.x, -1.4 * ZOOM.y);
	MAX = SET(1.4 * ZOOM.x, 1.4 * ZOOM.y);
	OFF.x = MIN_X - (WIDTH - (MAX_X - MIN_X)) / 2;
	OFF.y = MIN_Y - (HEIGHT - (MAX_Y - MIN_Y)) / 2;
	POS = SET(WIDTH, HEIGHT);
	MODE = 0;
}

static double		get_point(const t_env *env, t_point p)
{
	int				i;
	t_point			z;
	t_point			sq;
	t_ld			one;
	t_point			cste;

	cste = SET(MOUSE_X, MOUSE_Y);
	Z = SET(X / ZOOM.x, Y / ZOOM.y);
	sq = SET(POW2(REEL), POW2(IMA));
	i = MAX_ITER;
	while (i--)
	{
		if (sq.x + sq.y > 4)
			return (i + 1 - log(log(sq.x + sq.y)) / log(2));
		sq = SET(POW2(REEL), POW2(IMA));
		one = sq.x + sq.y;
		IMA = (2 - one) * IMA + CSTEY;
		REEL = (2 - one) * REEL + CSTEX;
	}
	return (i);
}

static void			draw_unity(t_env *env)
{
	double			i;
	t_point			p;

	p = OFF;
	MAX = SET(WIDTH + OFF.x - 1, HEIGHT + OFF.y - 1);
	while (++Y < MAX_Y)
	{
		X = OFF.x;
		while (++X < MAX_X)
		{
			i = get_point(env, p);
			if (i > 0)
				put_pix_to_img(env, X - OFF.x, Y - OFF.y,
						-0xDDDDDD + color(i, MAX_ITER, MODE));
			else
				put_pix_to_img(env, X - OFF.x, Y - OFF.y, BLACK);
		}
	}
}

void				unity(t_env *env)
{
	if (REDRAW == 0)
		get_unity_points(env);
	draw_unity(env);
}
