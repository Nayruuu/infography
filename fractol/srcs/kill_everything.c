/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 17:02:45 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/25 17:18:13 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	kill_env(t_env *env)
{
	if (env)
	{
		mlx_destroy_image(MLX, IMG);
		mlx_clear_window(MLX, WIN);
		mlx_destroy_window(MLX, WIN);
		free (env);
		env = NULL;
	}
}

void		kill_everything(t_env **env)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		kill_env(env[i]);
		i++;
	}
	exit(1);
}
