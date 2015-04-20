/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:32:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:38:22 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			get_julia_points(t_env *env)
{
	ZOOM.x = WIDTH / (1.7 + 1.7);
	ZOOM.y = HEIGHT / (1.7 + 1.7);
	MIN = SET(-1.4 * ZOOM.x, -1.4 * ZOOM.y);
	MAX = SET(1.4 * ZOOM.x, 1.4 * ZOOM.y);
	OFF.x = MIN_X - (WIDTH - (MAX_X - MIN_X)) / 2;
	OFF.y = MIN_Y - (HEIGHT - (MAX_Y - MIN_Y)) / 2;
	POS.x = WIDTH / 5;
	POS.y = HEIGHT / 5;
	MODE = 20;
}

static double		get_point(const t_env *env, t_point p)
{
	int				i;
	t_point			z;
	t_point			sq;
	const t_point	cste = SET(MOUSE_X, MOUSE_Y);

	Z = SET(X / ZOOM.x, Y / ZOOM.y);
	sq = SET(POW2(REEL), POW2(IMA));
	i = MAX_ITER;
	while (i--)
	{
		if (sq.x + sq.y > 4)
			return (i + 1 - log(log(sq.x + sq.y)) / log(2));
		sq = SET(POW2(REEL), POW2(IMA));
		if (POWER > 2)
			Z = power_complex(Z, POWER);
		else
			Z = (t_point){sq.x - sq.y, 2 * REEL * IMA};
		Z = (t_point){REEL + CSTEX, IMA + CSTEY};
	}
	return (0);
}

static void			draw_julia(t_env *env)
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

void				julia(t_env *env)
{
	if (REDRAW == 0)
		get_julia_points(env);
	draw_julia(env);
}
