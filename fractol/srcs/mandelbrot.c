/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:32:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:38:08 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void			get_mandel_points(t_env *env)
{
	ZOOM.x = WIDTH / (1 + 2.5);
	ZOOM.y = HEIGHT / (1 + 1);
	MIN = SET(-2.5 * ZOOM.x, -1 * ZOOM.y);
	MAX = SET(1 * ZOOM.x, 1 * ZOOM.y);
	OFF.x = MIN_X - (WIDTH - (MAX_X - MIN_X)) / 2;
	OFF.y = MIN_Y - (HEIGHT - (MAX_Y - MIN_Y)) / 2;
	MODE = 500;
}

static double		get_point(const t_env *env, t_point p)
{
	int				i;
	t_point			z;
	t_point			sq;
	const t_point	cste = SET(X / ZOOM.x, Y / ZOOM.y);

	Z = SET(0, 0);
	sq = SET(0, 0);
	i = MAX_ITER;
	while (i--)
	{
		if (sq.x + sq.y > 4)
			return (i + 1 - log(log(sq.x + sq.y)) / log(2));
		sq = SET(REEL * REEL, IMA * IMA);
		if (POWER > 2)
		{
			Z = power_complex(Z, POWER);
			Z = add_complex(Z, cste);
		}
		else
		{
			IMA = 2 * REEL * IMA + CSTEY;
			REEL = sq.x - sq.y + CSTEX;
		}
	}
	return (0);
}

static void			draw_mandelbrot(t_env *env)
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
			if (X - OFF.x < 0 || X - OFF.x > WIDTH ||
				Y - OFF.y < 0 || Y - OFF.y > HEIGHT)
				return ;
			i = get_point(env, p);
			if (i > 0)
				put_pix_to_img(env, X - OFF.x, Y - OFF.y,
						color(i, MAX_ITER, MODE));
			else
				put_pix_to_img(env, X - OFF.x, Y - OFF.y, BLACK);
		}
	}
}

void				mandelbrot(t_env *env)
{
	if (REDRAW == 0)
		get_mandel_points(env);
	draw_mandelbrot(env);
}
