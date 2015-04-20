/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:36:34 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 15:15:47 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	gere_jump(const Uint8 *keycode, t_env *env)
{
	if (keycode[SDL_SCANCODE_SPACE] && ACCR == (-HEIGHT) / 2)
		ACCR = 0;
	else if (keycode[SDL_SCANCODE_SPACE] && ACCR == 0)
	{
		JUMP += HEIGHT / 2;
		if (keycode[SDL_SCANCODE_UP])
			JUMP_DIRECTION = MOVE_W;
		else if (keycode[SDL_SCANCODE_DOWN])
			JUMP_DIRECTION = MOVE_S;
		else if (keycode[SDL_SCANCODE_LEFT])
			JUMP_DIRECTION = MOVE_A;
		else if (keycode[SDL_SCANCODE_RIGHT])
			JUMP_DIRECTION = MOVE_D;
		else
			JUMP_DIRECTION = 0;
	}
	return (1);
}

static int	gere_down(const Uint8 *keycode, t_env *env)
{
	if (keycode[SDL_SCANCODE_C] && ACCR == 0)
		ACCR -= HEIGHT / 2;
	else if (keycode[SDL_SCANCODE_C] && ACCR == (-HEIGHT) / 2)
	{
		SPEED /= 4;
		ACCR -= HEIGHT / 3;
	}
	else if ((keycode[SDL_SCANCODE_C] && ACCR == (-5 * HEIGHT) / 6) ||
			(keycode[SDL_SCANCODE_SPACE] && ACCR == (-5 * HEIGHT) / 6))
	{
		SPEED *= 4;
		ACCR = 0;
	}
	gere_jump(keycode, env);
	return (1);
}

static int	gere_key2(const Uint8 *keycode, t_env *env)
{
	if (keycode[SDL_SCANCODE_UP] && check_up(env))
	{
		CAMERA.x -= cos(DIRECTION) * SPEED;
		CAMERA.y -= sin(DIRECTION) * SPEED;
	}
	if (keycode[SDL_SCANCODE_DOWN] && check_down(env))
	{
		CAMERA.x += cos(DIRECTION) * SPEED;
		CAMERA.y += sin(DIRECTION) * SPEED;
	}
	gere_down(keycode, env);
	return (1);
}

int			gere_key(const Uint8 *keycode, t_env *env)
{
	if (keycode[SDL_SCANCODE_ESCAPE])
	{
		kill_everything(env);
		return (1);
	}
	if (keycode[SDL_SCANCODE_LEFT] && check_left(env))
	{
		CAMERA.x += cos(M_PI / 2 + DIRECTION) * SPEED / 2;
		CAMERA.y += sin(M_PI / 2 + DIRECTION) * SPEED / 2;
	}
	if (keycode[SDL_SCANCODE_RIGHT] && check_right(env))
	{
		CAMERA.x -= cos(M_PI / 2 + DIRECTION) * SPEED / 2;
		CAMERA.y -= sin(M_PI / 2 + DIRECTION) * SPEED / 2;
	}
	if (keycode[SDL_SCANCODE_R])
		init_pos(env);
	gere_key2(keycode, env);
	REDRAW = 1;
	return (0);
}
