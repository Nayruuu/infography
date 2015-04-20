/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 00:01:33 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 12:30:20 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		destroy_map(int **map, int max_y)
{
	int		i;

	i = 0;
	while (i < max_y)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void		kill_everything(t_env *env)
{
	mlx_destroy_image(MLX, IMG);
	destroy_map(MAP, MAX_Y);
	mlx_clear_window(MLX, WIN);
	mlx_destroy_window(MLX, WIN);
	free(MLX);
	MLX = NULL;
	free(env);
	env = NULL;
}
