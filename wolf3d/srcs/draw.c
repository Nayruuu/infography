/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 15:09:06 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/08 18:14:35 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw(t_env *env, t_point pos, int wall, int color)
{
	int		y;

	y = pos.y + 1;
	put_pix_to_img(env, pos.x, y - 1, 0);
	put_pix_to_img(env, pos.x, y, 0);
	while (y < wall + pos.y - 1)
	{
		put_pix_to_img(env, pos.x, y, color);
		y++;
	}
	put_pix_to_img(env, pos.x, y - 1, 0);
	put_pix_to_img(env, pos.x, y, 0);
}
