/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 16:30:31 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/26 16:36:03 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_destroy_lst(t_map **map)
{
	t_map		*temp;

	if (map && *map)
	{
		while ((*map)->left)
			*map = (*map)->left;
		temp = (*map)->right;
		if (temp == NULL)
			ft_destroy_point(map);
		else
		{
			while (temp)
			{
				temp = (*map)->right;
				ft_destroy_point(map);
				*map = temp;
			}
		}
	}
}
