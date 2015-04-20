/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:32:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:41:05 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			get_square_points(t_env *env)
{
	ZOOM.x = WIDTH / (1.7 + 1.7);
	ZOOM.y = HEIGHT / (1.7 + 1.7);
	MIN = SET(-1.4 * ZOOM.x, -1.4 * ZOOM.y);
	MAX = SET(1.4 * ZOOM.x, 1.4 * ZOOM.y);
	OFF.x = MIN_X - (WIDTH - (MAX_X - MIN_X)) / 2;
	OFF.y = MIN_Y - (HEIGHT - (MAX_Y - MIN_Y)) / 2;
	POS = SET(WIDTH / 3, HEIGHT / 3);
	MODE = 0;
}

static double		get_point(t_env *env, t_point p)
{
	int				i;
	t_point			z;
	t_point			sq;
	t_point			cste;

	cste = SET(MOUSE_X, MOUSE_Y);
	if (POS_X > WIDTH / 3)
		POS_X = WIDTH / 3;
	if (POS_Y > HEIGHT / 3)
		POS_Y = HEIGHT / 3;
	Z = SET(X / ZOOM.x, Y / ZOOM.y);
	sq = SET(POW2(REEL), POW2(IMA));
	i = MAX_ITER;
	while (i--)
	{
		if (sq.x + sq.y > 8)
			return (i + 1 - log(log(sq.x + sq.y)) / log(2));
		sq = SET(POW2(REEL), POW2(IMA));
		IMA = fabs(IMA) / (sq.x + sq.y) + CSTEY;
		REEL = fabs(REEL) / (sq.x + sq.y) + CSTEX;
	}
	return (0);
}

static void			draw_square(t_env *env)
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
						color(i, MAX_ITER, MODE));
			else
				put_pix_to_img(env, X - OFF.x, Y - OFF.y, BLACK);
		}
	}
}

void				square(t_env *env)
{
	if (REDRAW == 0)
		get_square_points(env);
	draw_square(env);
}
