/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 10:29:35 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 14:36:23 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		get_color(int x, int y, t_env *env)
{
	if (DATA[30 + x + (30 + y) * WIDTH] & 0x00FF0000)
		put_pix_to_img(env, 30 + x, 30 + y,
				DATA[30 + x + (30 + y) * WIDTH] + 0x00220000);
	else if (DATA[30 + x + (30 + y) * WIDTH] & 0x0000FF00)
		put_pix_to_img(env, 30 + x, 30 + y,
				DATA[30 + x + (30 + y) * WIDTH] + 0x00002200);
	else if (DATA[30 + x + (30 + y) * WIDTH] & 0x000000FF)
		put_pix_to_img(env, 30 + x, 30 + y,
				DATA[30 + x + (30 + y) * WIDTH] + 0x00000022);
}

static void		draw_square(t_env *env, int start_x, int start_y, int length)
{
	int			x;
	int			y;

	y = start_y - 1;
	while (++y < start_y + length)
	{
		x = start_x - 1;
		while (++x < start_x + length)
		{
			put_pix_to_img(env, 30 + x, 30 + y, 0x0);
		}
	}
}

static void		draw_player(t_env *env)
{
	int			x;
	int			y;

	y = 69;
	while (++y < 80)
	{
		x = 69;
		while (++x < 80)
		{
			put_pix_to_img(env, 30 + x, 30 + y, 0x00FCDC12);
		}
	}
}

static void		draw_blocks(t_env *env)
{
	int			x;
	int			y;
	const int	mapy = (int)CAMERA.y / BLOCK;
	const int	mapx = (int)CAMERA.x / BLOCK;

	y = -3;
	while (++y <= 2)
	{
		x = -3;
		while (++x <= 2)
		{
			if (mapy + y >= 0 && mapx - x >= 0 &&
				mapy + y < MAX_H && mapx - x < MAX_W)
			{
				if (MAP[mapy + y][mapx - x])
					draw_square(env, (2 + y) * 30, (2 + x) * 30, 30);
			}
		}
	}
}

void			draw_map(t_env *env)
{
	int			x;
	int			y;

	y = -1;
	while (++y < 150)
	{
		x = -1;
		while (++x < 150)
			get_color(x, y, env);
	}
	draw_blocks(env);
	draw_player(env);
}
