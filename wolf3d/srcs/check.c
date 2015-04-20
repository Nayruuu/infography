/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 20:03:58 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 14:39:06 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static inline Uint32	get_color_value(t_env *env, t_point prev, t_point next)
{
	prev.x = prev.x / BLOCK * BLOCK + (BLOCK / 2);
	prev.y = prev.y / BLOCK * BLOCK + (BLOCK / 2);
	next.x = next.x / BLOCK * BLOCK + (BLOCK / 2);
	next.y = next.y / BLOCK * BLOCK + (BLOCK / 2);
	prev.x -= next.x;
	prev.y -= next.y;
	if (!prev.x && prev.y < 0)
		return (0x00DD0000);
	else if (!prev.x && prev.y > 0)
		return (0x00AA0000);
	else if (!prev.y && prev.x > 0)
		return (0x00880000);
	else if (!prev.y && prev.x < 0)
		return (0x00550000);
	else
		return (0x00660000);
}

static t_ray			raycast(t_env *env, double angle)
{
	t_ray		ray;
	t_point		prev;
	t_point		next;
	const t_pos	delta = SET(cos(angle), sin(angle));

	X = CAMERA.x;
	Y = CAMERA.y;
	next = ISET((int)CAMERA.x, (int)CAMERA.y);
	while (X >= 0 && Y >= 0 &&
			X < MAX_W * BLOCK && Y < MAX_H * BLOCK)
	{
		prev = ISET((int)X, (int)Y);
		if (MAP[(int)Y / BLOCK][(int)X / BLOCK] == WALL)
		{
			ray.angle = angle;
			ray.color = get_color_value(env, prev, next);
			ray.dist = dist(ray.pos, CAMERA);
			return (ray);
		}
		next = prev;
		X -= delta.x;
		Y -= delta.y;
	}
	ray = (t_ray){{0, 0}, 0, 0, -1};
	return (ray);
}

static void				fill_tab(t_env *env)
{
	int					x;

	x = -1;
	while (++x < WIDTH * HEIGHT)
	{
		if (DATA[x] == 0x00660000 && x - 1 >= 0)
			DATA[x] = DATA[x - 1];
	}
}

static int				get_wall(t_env *env, double angle, t_ray ray,
		int *temp_wall)
{
	int					wall;

	if (ray.dist != -1)
		wall = SCREEN * BLOCK / (cos(DIRECTION - angle) * ray.dist);
	else
		wall = 0;
	if (*temp_wall == 0)
		*temp_wall = wall;
	if (abs(*temp_wall - wall) < 2)
		wall = *temp_wall;
	else
		*temp_wall = wall;
	return (wall);
}

void					check(t_env *env)
{
	int			x;
	int			wall;
	t_ray		ray;
	int			temp_wall;
	double		angle;

	x = -1;
	temp_wall = 0;
	angle = -ANGLE / 2 + DIRECTION;
	while (++x < WIDTH)
	{
		ray = raycast(env, angle);
		wall = get_wall(env, angle, ray, &temp_wall);
		angle += CST_A;
		draw(env, ISET(x, 0), (HEIGHT + OFF + ACCR - wall) / 2, 0x00000055);
		draw(env, ISET(x, ((HEIGHT + OFF + ACCR - wall) / 2)), wall, ray.color);
		draw(env, ISET(x, ((HEIGHT + OFF + ACCR - wall) / 2 + wall)),
				(HEIGHT - OFF - ACCR + wall) / 2, 0x00005500);
	}
	fill_tab(env);
}
