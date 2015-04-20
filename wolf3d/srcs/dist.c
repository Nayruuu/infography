/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 00:28:18 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 00:29:33 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline double	dist(t_pos pos, t_pos camera)
{
	return (sqrt(POW2(pos.x - camera.x) + POW2(pos.y - camera.y)));
}
