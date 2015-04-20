/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:56:16 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/23 03:10:57 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			*ft_new_point(int x, int y, int z)
{
	t_map		*new_elem;

	new_elem = (t_map*)ft_xmalloc(sizeof(t_map));
	new_elem->point.x = x;
	new_elem->point.y = y;
	new_elem->point.z = z;
	new_elem->left = NULL;
	new_elem->right = NULL;
	return (new_elem);
}
