/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:17:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 17:36:54 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	while1(t_point p1, t_point p2, t_env *env, t_draw draw)
{
	int		t_x;

	t_x = 1;
	CUMUL = DX / 2;
	while (t_x <= DX)
	{
		_X += XINC;
		CUMUL += DY;
		if (CUMUL >= DX)
		{
			CUMUL -= DX;
			_Y += YINC;
		}
		if (Z2 == Z1)
			put_pix_to_img(env, _X, _Y, GC(env, Z2));
		else if (COEFFZ >= 0)
			put_pix_to_img(env, _X, _Y, GC(env, abs((Z2 - Z1)) / 2));
		else
			put_pix_to_img(env, _X, _Y, GC(env, -abs((Z2 - Z1)) / 2));
		t_x++;
	}
}

static void	while2(t_point p1, t_point p2, t_env *env, t_draw draw)
{
	int		t_x;

	t_x = 1;
	CUMUL = DY / 2;
	while (t_x <= DY)
	{
		_Y += YINC;
		CUMUL += DX;
		if (CUMUL >= DY)
		{
			CUMUL -= DY;
			_X += XINC;
		}
		if (Z2 == Z1)
			put_pix_to_img(env, _X, _Y, GC(env, Z2));
		else if (COEFFZ >= 0)
			put_pix_to_img(env, _X, _Y, GC(env, abs((Z2 - Z1)) / 2));
		else
			put_pix_to_img(env, _X, _Y, GC(env, -abs((Z2 - Z1)) / 2));
		t_x++;
	}
}

void		draw_hline(t_point p1, int i, int j, t_env *env)
{
	t_point	p2;
	t_draw	draw;

	if (i + 1 >= MAX_X)
		return ;
	p2 = set_point(i + 1, j, MAP[j][i + 1]);
	p2 = choice(env, p2);
	_X = X2;
	_Y = Y2;
	DX = X2 - X1;
	DY = Y2 - Y1;
	XINC = (DX > 0) ? -1 : 1;
	YINC = (DY > 0) ? -1 : 1;
	DX = abs(DX);
	DY = abs(DY);
	if (Z2 == Z1)
		put_pix_to_img(env, _X, _Y, GC(env, Z2));
	else if (COEFFZ >= 0)
		put_pix_to_img(env, _X, _Y, GC(env, abs((Z2 - Z1)) / 2));
	else
		put_pix_to_img(env, _X, _Y, GC(env, -abs((Z2 - Z1)) / 2));
	if (DX > DY)
		while1(p1, p2, env, draw);
	else
		while2(p1, p2, env, draw);
}

void		draw_vline(t_point p1, int i, int j, t_env *env)
{
	t_point	p2;
	t_draw	draw;

	if (j + 1 >= MAX_Y)
		return ;
	p2 = set_point(i, j + 1, MAP[j + 1][i]);
	p2 = choice(env, p2);
	_X = X2;
	_Y = Y2;
	DX = X2 - X1;
	DY = Y2 - Y1;
	XINC = (DX > 0) ? -1 : 1;
	YINC = (DY > 0) ? -1 : 1;
	DX = abs(DX);
	DY = abs(DY);
	if (Z2 == Z1)
		put_pix_to_img(env, _X, _Y, GC(env, Z2));
	else if (COEFFZ >= 0)
		put_pix_to_img(env, _X, _Y, GC(env, abs((Z2 - Z1)) / 2));
	else
		put_pix_to_img(env, _X, _Y, GC(env, -abs((Z2 - Z1)) / 2));
	if (DX > DY)
		while1(p1, p2, env, draw);
	else
		while2(p1, p2, env, draw);
}

void		draw(t_env *env)
{
	int		i;
	int		j;
	t_point	p1;

	j = -1;
	ft_memset(DATA, 0, LINE_S * HEIGHT);
	while (++j < MAX_Y)
	{
		i = -1;
		while (++i < MAX_X)
		{
			p1 = set_point(i, j, MAP[j][i]);
			p1 = choice(env, p1);
			draw_hline(p1, i, j, env);
			draw_vline(p1, i, j, env);
		}
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	print_msgs(env);
}
