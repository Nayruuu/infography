/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 15:15:05 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 16:16:32 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_img	*get_img(t_env *env)
{
	t_img		*img;

	img = (t_img*)ft_xmalloc(sizeof(t_img));
	img->renderer = SDL_CreateRenderer(WIN, -1, OPTI);
	if (!img->renderer)
		exit(!ft_putendl_fd(_ERROR_4, 2));
	img->texture = SDL_CreateTexture(img->renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	if (!img->texture)
		exit(!ft_putendl_fd(_ERROR_4, 2));
	img->data = (Uint32*)ft_xmalloc(sizeof(Uint32) * WIDTH * HEIGHT);
	return (img);
}

static int		check_map(t_env *env)
{
	int			x;
	int			y;

	y = -1;
	while (++y < MAX_H)
	{
		x = -1;
		while (++x < MAX_W)
		{
			if (!MAP[y][x])
				return (0);
		}
	}
	ft_putendl_fd("Wolf3d : map only contains walls.", 2);
	kill_everything(env);
	return (1);
}

static t_env	*init_env(int fd)
{
	t_env		*env;

	env = (t_env*)ft_xmalloc(sizeof(t_env));
	WIN = SDL_CreateWindow("Wolf3d", CENTER, CENTER, WIDTH, HEIGHT,
				SDL_WINDOW_ALLOW_HIGHDPI);
	if (!WIN)
	{
		free(env);
		env = NULL;
		SDL_Quit();
	}
	env->img = get_img(env);
	env->map = (t_map*)ft_xmalloc(sizeof(t_map));
	MAP = get_map(fd, &MAX_H, &MAX_W);
	check_map(env);
	BLOCK = 64;
	OFF = 0;
	REDRAW = 1;
	ANGLE = 1.047195512;
	ACCR = 0;
	JUMP = 0;
	SPEED = 10;
	DIRECTION = M_PI / 2;
	close(fd);
	return (env);
}

int				main(void)
{
	int			fd;
	t_env		*env;

	srand(time(NULL));
	if (SDL_Init(SDL_INIT_VIDEO) <= -1)
		exit(!ft_putendl_fd(_ERROR_3, 2));
	if ((fd = open("map.wlf", O_RDONLY)) < 0)
		exit(!ft_putendl_fd(_ERROR_1, 2));
	env = init_env(fd);
	init_pos(env);
	gere_sdl(env);
	return (0);
}
