/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 15:15:51 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 15:31:04 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_pos(t_env *env)
{
	int			random;
	int			random2;

	random = rand() % (MAX_H - 2) + 1;
	random2 = rand() % (MAX_W - 2) + 1;
	while (MAP[random][random2])
	{
		random = rand() % (MAX_H - 2) + 1;
		random2 = rand() % (MAX_W - 2) + 1;
	}
	CAMERA = SET(random * BLOCK, random2 * BLOCK);
}
