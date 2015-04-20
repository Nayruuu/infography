/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:25:41 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 16:44:50 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fill_map(t_map **map, char **stock, int y, int *x)
{
	int			t_x;

	t_x = 0;
	while (stock[t_x])
	{
		ft_insert_elem(map, NEW_P(t_x, y, ft_getnbr(stock[t_x])));
		t_x++;
	}
	if (!(*x) && t_x > *x)
		*x = t_x;
}

static int		**t_map_to_map(t_map *l_map, int y, int x)
{
	int			i;
	int			j;
	int			**map;

	ft_go_first_point(&l_map);
	i = -1;
	j = 0;
	map = (int**)ft_xmalloc(sizeof(int*) * y);
	while (++i < y)
		map[i] = (int*)ft_xmalloc(sizeof(int) * x);
	i = 0;
	while (l_map)
	{
		map[j][i++] = l_map->point.z;
		if (i == x)
		{
			i = 0;
			j++;
		}
		l_map = l_map->right;
	}
	return (map);
}

int				**get_map(int fd, int *max_x, int *max_y)
{
	int			ret;
	t_map		*l_map;
	int			**map;
	char		*line;
	char		**stock;

	stock = NULL;
	l_map = ft_init_map();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		stock = ft_strsplit(line, ' ');
		fill_map(&l_map, stock, *max_y, max_x);
		free_line(stock);
		(*max_y)++;
	}
	if (ret == ERROR)
		exit(!ft_putstr_fd(_ERROR_3, 2));
	else if (l_map == NULL)
		exit(!ft_putstr_fd(_ERROR_4, 2));
	map = t_map_to_map(l_map, *max_y, *max_x);
	ft_destroy_lst(&l_map);
	return (map);
}
