/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:17:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/13 23:40:09 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			put_pix_to_img(t_env *env, int x, int y, Uint32 color)
{
	if (x + y * WIDTH < WIDTH * HEIGHT && x + y * WIDTH >= 0)
		DATA[x + y * WIDTH] = color;
}
