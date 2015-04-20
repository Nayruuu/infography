/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 23:41:22 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 17:36:03 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			gere_expose(t_env *env)
{
	draw(env);
	return (1);
}

void		gere_mlx(t_env *env)
{
	mlx_do_key_autorepeaton(MLX);
	mlx_expose_hook(WIN, gere_expose, env);
	mlx_hook(WIN, KeyPress, KeyPressMask, gere_key, env);
	mlx_loop(MLX);
}
