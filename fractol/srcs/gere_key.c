/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 23:41:22 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/26 22:18:24 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	gere_key3(int keycode, t_env *env)
{
	if (keycode == 65464)
		POWER++;
	else if (keycode == 65458)
		POWER--;
	else if (keycode == 65293)
	{
		REDRAW = 0;
		POWER = 2;
		LOCK_CAM = 1;
		MAX_ITER = 150;
		gere_expose(env);
	}
	if (keycode == 65464 || keycode == 65458)
		REDRAW = 1;
	if (POWER < 2)
		POWER = 2;
	env = env;
	return (0);
}

static int	gere_key2(int keycode, t_env *env)
{
	if (keycode == 44)
	{
		PRECI -= 3;
		MAX_ITER -= 3;
	}
	else if (keycode == 46)
	{
		PRECI += 3;
		MAX_ITER += 3;
	}
	else
		gere_key3(keycode, env);
	if (keycode == 44 || keycode == 46)
		REDRAW = 1;
	if (keycode == 44 && MAX_ITER < 120)
	{
		PRECI += 3;
		MAX_ITER = 120;
	}
	return (0);
}

void		print_msg(t_env *env)
{
	if (CHOICE)
		gere_cam(env);
	if (CHOICE != 6 && CHOICE != 7 && CHOICE != 3)
		PUT_STR(MLX, WIN, WIDTH - 70, 20, WHITE, ft_strjoin("Power :  ",
				ft_itoa(POWER)));
	PUT_STR(MLX, WIN, 10, 20, WHITE, ft_strjoin("Zoom.x : ", ft_itoa(ZOOM.x)));
	PUT_STR(MLX, WIN, 10, 35, WHITE, ft_strjoin("Zoom.y : ", ft_itoa(ZOOM.y)));
	PUT_STR(MLX, WIN, WIDTH - 120, HEIGHT - 20, WHITE, "Iterations :");
	PUT_STR(MLX, WIN, WIDTH - 30, HEIGHT - 20, WHITE, ft_itoa(MAX_ITER));
}

int			gere_key(int keycode, t_env *env)
{
	if (keycode == 65307)
		env->destroy = 1;
	else if (keycode == 99 && !LOCK_CAM)
		LOCK_CAM = 1;
	else if (keycode == 99 && LOCK_CAM)
		LOCK_CAM = 0;
	else if (keycode == 65362)
		OFF.y -= 5;
	else if (keycode == 65364)
		OFF.y += 5;
	else if (keycode == 65361)
		OFF.x -= 5;
	else if (keycode == 65363)
		OFF.x += 5;
	else
		gere_key2(keycode, env);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	print_msg(env);
	if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
		REDRAW = 1;
	return (0);
}
