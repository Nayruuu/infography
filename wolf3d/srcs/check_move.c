/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/08 00:21:41 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 14:11:10 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int			check_left(const t_env *env)
{
	int		x;
	int		y;

	x = (CAMERA.x + cos(M_PI / 2 + DIRECTION) * SPEED / 2) / BLOCK;
	y = (CAMERA.y + sin(M_PI / 2 + DIRECTION) * SPEED / 2) / BLOCK;
	if (x < 1 || x > MAX_W - 1 || y < 1 || y > MAX_H - 1)
		return (0);
	if (MAP[y][x] == 1)
		return (0);
	else
		return (1);
}

int			check_right(const t_env *env)
{
	int		x;
	int		y;

	x = (CAMERA.x - cos(M_PI / 2 + DIRECTION) * SPEED / 2) / BLOCK;
	y = (CAMERA.y - sin(M_PI / 2 + DIRECTION) * SPEED / 2) / BLOCK;
	if (x < 1 || x > MAX_W - 1 || y < 1 || y > MAX_H - 1)
		return (0);
	if (MAP[y][x] == 1)
		return (0);
	else
		return (1);
}

int			check_up(const t_env *env)
{
	int		x;
	int		y;

	x = (CAMERA.x - cos(DIRECTION) * SPEED) / BLOCK;
	y = (CAMERA.y - sin(DIRECTION) * SPEED) / BLOCK;
	if (x < 1 || x > MAX_W - 1 || y < 1 || y > MAX_H - 1)
		return (0);
	if (MAP[y][x] == 1)
		return (0);
	else
		return (1);
}

int			check_down(const t_env *env)
{
	int		x;
	int		y;

	x = (CAMERA.x + cos(DIRECTION) * SPEED) / BLOCK;
	y = (CAMERA.y + sin(DIRECTION) * SPEED) / BLOCK;
	if (x < 1 || x > MAX_W - 1 || y < 1 || y > MAX_H - 1)
		return (0);
	if (MAP[y][x] == 1)
		return (0);
	else
		return (1);
}
