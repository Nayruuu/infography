/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 03:04:03 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/23 06:05:03 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_insert_elem(t_map **map, t_map *elem)
{
	t_map		*current;

	if (map)
	{
		if (!(*map))
			*map = elem;
		else
		{
			current = *map;
			if (current->right == NULL)
			{
				current->right = elem;
				elem->right = NULL;
				elem->left = current;
			}
			else
			{
				elem->right = current->right;
				current->right->left = elem;
				current->right = elem;
				elem->left = current;
			}
			*map = elem;
		}
	}
}
