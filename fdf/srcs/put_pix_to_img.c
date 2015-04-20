/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix_to_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:17:04 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 17:48:32 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color_value(t_env *env, int z)
{
	if (z < 0)
		return (mlx_get_color_value(MLX, COLOR & 0xFF555555));
	else if (z == 0)
		return (mlx_get_color_value(MLX, COLOR & 0xFF666666));
	else if (z > 0 && z <= 5)
		return (mlx_get_color_value(MLX, COLOR & 0xFF888888));
	else if (z > 5 && z <= 10)
		return (mlx_get_color_value(MLX, COLOR & 0xFFAAAAAA));
	else if (z > 10 && z <= 15)
		return (mlx_get_color_value(MLX, COLOR & 0xFFBBBBBB));
	else if (z > 15 && z <= 25)
		return (mlx_get_color_value(MLX, COLOR & 0xFFCCCCCC));
	else if (z > 25 && z <= 35)
		return (mlx_get_color_value(MLX, COLOR & 0xFFDDDDDD));
	else if (z > 35 && z <= 45)
		return (mlx_get_color_value(MLX, COLOR & 0xFFEEEEEE));
	else
		return (mlx_get_color_value(MLX, COLOR & 0xFFFFFFFF));
}

void			put_pix_to_img(t_env *env, int x, int y, unsigned int color)
{
	if (x < WIDTH && x > 0 && y > 0 && y < HEIGHT)
	{
		DATA[x * 4 + 3 + LINE_S * y] = (color & 0xFF000000) >> 24;
		DATA[x * 4 + 2 + LINE_S * y] = (color & 0xFF0000) >> 16;
		DATA[x * 4 + 1 + LINE_S * y] = (color & 0xFF00) >> 8;
		DATA[x * 4 + 0 + LINE_S * y] = (color & 0xFF);
	}
}
