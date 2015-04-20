/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 23:41:22 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/07 23:02:52 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			gere_expose(t_env *env)
{
	if (CHOICE == 0)
		mandelbrot(env);
	if (CHOICE == 1)
		julia(env);
	if (CHOICE == 2)
		phoenix(env);
	if (CHOICE == 3)
		escher(env);
	if (CHOICE == 4)
		burning(env);
	if (CHOICE == 5)
		barnsley(env);
	if (CHOICE == 6)
		square(env);
	if (CHOICE == 7)
		unity(env);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	print_msg(env);
	return (0);
}

static void	gere_mult_loop(t_env *env)
{
	if (env && REDRAW == 1)
	{
		gere_expose(env);
		REDRAW = 2;
	}
}

int			gere_loop(t_env **env)
{
	gere_mult_loop(env[0]);
	gere_mult_loop(env[1]);
	gere_mult_loop(env[2]);
	gere_mult_loop(env[3]);
	gere_mult_loop(env[4]);
	gere_mult_loop(env[5]);
	gere_mult_loop(env[6]);
	gere_mult_loop(env[7]);
	if ((env[0] && DESTROY0) || (env[1] && DESTROY1) ||
		(env[2] && DESTROY2) || (env[3] && DESTROY3) ||
		(env[4] && DESTROY4) || (env[5] && DESTROY5) ||
		(env[6] && DESTROY6) || (env[7] && DESTROY7))
	{
		kill_everything(env);
	}
	return (0);
}

void		gere_mlx(t_env *env)
{
	if (env)
	{
		ft_putnbr(MotionNotify);
		ft_putstr(" ");
		ft_putnbr(PointerMotionMask);
		mlx_expose_hook(WIN, gere_expose, env);
		mlx_hook(WIN, ButtonPress, ButtonPressMask, &gere_mouse, env);
		mlx_hook(WIN, MotionNotify, PointerMotionMask, &gere_motion, env);
		mlx_hook(WIN, ButtonRelease, ButtonReleaseMask, &gere_click, env);
		mlx_hook(WIN, KeyPress, KeyPressMask, &gere_key, env);
	}
}
