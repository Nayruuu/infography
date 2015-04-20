/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 16:08:35 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/09 16:08:37 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	destroy_map(t_type **map)
{
	int		i;

	i = 0;
	while (map[i])
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
	destroy_map(MAP);
	SDL_DestroyRenderer(IMG);
	SDL_DestroyTexture(TEXTURE);
	free(DATA);
	DATA = NULL;
	free (env->img);
	env->img = NULL;
	SDL_DestroyWindow(WIN);
	free(env);
	env = NULL;
	exit(!ft_putendl_fd("Wolf3d exit successfully.", 1));
}
