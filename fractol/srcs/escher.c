/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:32:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:41:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void			get_escher_points(t_env *env)
{
	ZOOM.x = WIDTH / (1.7 + 1.7);
	ZOOM.y = HEIGHT / (1.7 + 1.7);
	MIN = SET(-1.4 * ZOOM.x, -1.4 * ZOOM.y);
	MAX = SET(1.4 * ZOOM.x, 1.4 * ZOOM.y);
	OFF.x = MIN_X - (WIDTH - (MAX_X - MIN_X)) / 2;
	OFF.y = MIN_Y - (HEIGHT - (MAX_Y - MIN_Y)) / 2;
	POS = SET(WIDTH, HEIGHT);
	MODE = 0;
}

static int			get_point(t_env *env, t_point p)
{
	int				i;
	t_point			z;
	t_point			sq;
	const t_point	cste = SET(MOUSE_X, MOUSE_Y);

	(void)cste;
	Z = SET(X / ZOOM.x, Y / ZOOM.y);
	sq = SET(POW2(REEL), POW2(IMA));
	i = MAX_ITER;
	while (i--)
	{
		if (POW2(15 * REEL * sin(CSTEX)) + POW2(15 * IMA * sin(CSTEY)) < 16)
			return (i);
		sq = SET(POW2(sin(REEL)), POW2(sin(IMA)));
		IMA = 2 * REEL * IMA;
		REEL = sq.x - sq.y;
	}
	return (i);
}

static void			draw_escher(t_env *env, unsigned int *color)
{
	int				i;
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
				put_pix_to_img(env, X - OFF.x, Y - OFF.y, color[MAX_ITER - i]);
			else
				put_pix_to_img(env, X - OFF.x, Y - OFF.y, BLACK);
		}
	}
}

void				escher(t_env *env)
{
	int				i;
	unsigned int	color[MAX_ITER];

	i = -1;
	if (REDRAW == 0)
		get_escher_points(env);
	while (++i < MAX_ITER)
		color[i] = i * 765 / MAX_ITER + MODE;
	draw_escher(env, color);
}
