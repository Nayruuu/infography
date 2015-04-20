/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 14:42:40 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/22 14:48:49 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		gere_cam(const t_env *env)
{
	if (LOCK_CAM)
		mlx_string_put(MLX, WIN, 20, HEIGHT - 20, 0xFFFFFF, "Camera Locked");
	else
		mlx_string_put(MLX, WIN, 20, HEIGHT - 20, 0xFFFFFF, "Camera Unlocked");
}
