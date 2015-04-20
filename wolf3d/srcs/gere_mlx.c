/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 23:41:22 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 16:00:46 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				gere_expose(t_env *env)
{
	int			width;

	width = WIDTH;
	if (REDRAW)
	{
		check(env);
		draw_map(env);
		SDL_UpdateTexture(TEXTURE, NULL, DATA, width * sizeof(Uint32));
		SDL_RenderCopy(IMG, TEXTURE, NULL, NULL);
		SDL_RenderPresent(IMG);
	}
	REDRAW = 0;
	return (1);
}

static void		check_side(t_env *env)
{
	if (check_up(env) && JUMP_DIRECTION == MOVE_W)
	{
		CAMERA.x -= cos(DIRECTION) * SPEED;
		CAMERA.y -= sin(DIRECTION) * SPEED;
	}
	else if (check_down(env) && JUMP_DIRECTION == MOVE_S)
	{
		CAMERA.x += cos(DIRECTION) * SPEED;
		CAMERA.y += sin(DIRECTION) * SPEED;
	}
	else if (check_left(env) && JUMP_DIRECTION == MOVE_A)
	{
		CAMERA.x += cos(M_PI / 2 + DIRECTION) * SPEED / 2;
		CAMERA.y += sin(M_PI / 2 + DIRECTION) * SPEED / 2;
	}
	else if (check_left(env) && JUMP_DIRECTION == MOVE_D)
	{
		CAMERA.x -= cos(M_PI / 2 + DIRECTION) * SPEED / 2;
		CAMERA.y -= sin(M_PI / 2 + DIRECTION) * SPEED / 2;
	}
}

static void		gere_jump(t_env *env)
{
	if (JUMP > 0)
	{
		ACCR += HEIGHT / 20;
		JUMP -= HEIGHT / 20;
		check_side(env);
		REDRAW = 1;
	}
	if (ACCR > 0 && JUMP <= 0)
	{
		ACCR -= HEIGHT / 20;
		check_side(env);
		REDRAW = 1;
	}
}

void			gere_sdl(t_env *env)
{
	int			end;
	const Uint8	*state = SDL_GetKeyboardState(NULL);
	SDL_Event	key_event;

	end = 0;
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(1);
	SDL_WarpMouseInWindow(WIN, WIDTH / 2, HEIGHT / 2);
	while (!end)
	{
		while (SDL_PollEvent(&key_event))
		{
			if (key_event.type == SDL_KEYDOWN)
				end = gere_key(state, env);
			if (key_event.type == SDL_MOUSEMOTION)
				gere_motion(key_event.motion.x, key_event.motion.y, env);
			else if (key_event.type == SDL_QUIT)
				end = 1;
			if (key_event.type == SDL_MOUSEWHEEL)
				gere_mouse(key_event.wheel.y, env);
		}
		gere_jump(env);
		gere_expose(env);
	}
	SDL_Quit();
}
