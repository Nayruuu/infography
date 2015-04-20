/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 19:38:30 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 14:32:25 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_length(char **data)
{
	int		i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

static void		fill_line(t_type *map, char **data, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		map[i] = ft_atoi(data[i]);
		i++;
	}
}

static void		to_t_map_to_map(t_tree *t_map, t_type **map, int *max_w)
{
	int			i;
	int			length;
	char		**data;

	i = 0;
	length = 0;
	data = NULL;
	while (t_map)
	{
		data = ft_strsplit(t_map->data, ' ');
		length = !length ? get_length(data) : length;
		*max_w = length;
		map[i] = (t_type*)ft_xmalloc(sizeof(t_type) * length + 1);
		ft_memset(map[i], 0, length);
		fill_line(map[i], data, length);
		map[i][length] = INT_MAX;
		free_line(data);
		t_map = t_map->right;
		i++;
	}
}

t_type			**get_map(int fd, int *max_h, int *max_w)
{
	t_type		**map;
	int			height;
	char		*line;
	t_tree		*t_map;

	height = 0;
	t_map = NULL;
	while (get_next_line(fd, &line))
	{
		ft_insert_elem_r(&t_map, ft_new_elem(line));
		ft_strdel(&line);
		height++;
	}
	ft_strdel(&line);
	if (!height)
		exit(!ft_putendl_fd(_ERROR_2, 2));
	*max_h = height;
	ft_go_first_elem(&t_map);
	map = (t_type**)ft_xmalloc(sizeof(t_type*) * height + 1);
	map[height] = NULL;
	to_t_map_to_map(t_map, map, max_w);
	ft_destroy_tree(&t_map);
	return (map);
}
