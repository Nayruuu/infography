/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:32:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:40:46 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			get_phoenix_points(t_env *env)
{
	ZOOM.x = WIDTH / (1.7 + 1.7);
	ZOOM.y = HEIGHT / (1.7 + 1.7);
	MIN = SET(-1.4 * ZOOM.x, -1.4 * ZOOM.y);
	MAX = SET(1.4 * ZOOM.x, 1.4 * ZOOM.y);
	OFF.x = MIN_X - (WIDTH - (MAX_X - MIN_X)) / 2;
	OFF.y = MIN_Y - (HEIGHT - (MAX_Y - MIN_Y)) / 2;
	POS = SET(WIDTH / 4, HEIGHT / 2);
	MODE = 0;
}

static double		get_point(const t_env *env, t_point p)
{
	int				i;
	t_point			z;
	t_point			sq;
	t_point			prev;
	t_point			current;

	i = MAX_ITER;
	prev = SET(0, 0);
	sq = SET(POW2(REEL), POW2(IMA));
	Z = SET(X / ZOOM.x, Y / ZOOM.y);
	while (i-- && sq.x + sq.y < 32)
	{
		current = SET(REEL, IMA);
		sq = SET(POW2(REEL), POW2(IMA));
		if (POWER > 2)
			Z = power_complex(Z, POWER);
		else
			Z = (t_point){sq.x - sq.y, 2 * REEL * IMA};
		IMA = IMA + MOUSE_X * prev.y + MOUSE_Y * prev.x;
		REEL = REEL + 0.5667 - MOUSE_Y * prev.y;
		prev = current;
	}
	return (i + 1 - log(log(sq.x + sq.y)) / log(2));
}

static void			draw_phoenix(t_env *env)
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

void				phoenix(t_env *env)
{
	if (REDRAW == 0)
		get_phoenix_points(env);
	draw_phoenix(env);
}
