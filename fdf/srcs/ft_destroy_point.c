/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 05:30:13 by sde-toda          #+#    #+#             */
/*   Updated: 2015/01/26 16:36:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		del_content(t_map **map)
{
	free(*map);
	*map = NULL;
}

static void		first_case(t_map **map, t_map *current)
{
	current->right->left = NULL;
	*map = current->right;
}

static void		second_case(t_map *current)
{
	current->left->right = current->right;
	current->right->left = current->left;
}

static void		last_case(t_map **map, t_map *current)
{
	current->left->right = NULL;
	*map = current->left;
}

void			ft_destroy_point(t_map **map)
{
	t_map		*current;

	if (map && *map)
	{
		current = *map;
		if (current->left == NULL && current->right)
		{
			first_case(map, current);
		}
		else if (current->left && current->right)
		{
			second_case(current);
		}
		else if (current->left && current->right == NULL)
		{
			last_case(map, current);
		}
		else if (!current->left && !current->right)
			del_content(map);
	}
}
