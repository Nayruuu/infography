/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:25:41 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 21:34:46 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_img	*get_img(void *mlx)
{
	t_img		*img;

	img = (t_img*)ft_xmalloc(sizeof(t_img));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->opp, &img->line_s,
			&img->endian);
	if (!img->img || !img->data)
		exit(!ft_putstr_fd(_ERROR_6, 2));
	img->opp /= 8;
	return (img);
}

static char		*get_name(char *name)
{
	if (ft_strrchr(name, '/'))
	{
		name = ft_strrchr(name, '/');
		name = ft_strjoin(&name[1], " ");
	}
	else
		name = ft_strjoin(name, " ");
	name = ft_strjoin(name, ft_itoa(WIDTH));
	name = ft_strjoin(name, " X ");
	name = ft_strjoin(name, ft_itoa(HEIGHT));
	return (name);
}

void			get_points(t_env *env)
{
	t_point		p1;
	t_point		p2;

	p1 = set_point(0, MAX_Y - 1, MAP[MAX_Y - 1][0]);
	p1 = choice(env, p1);
	p2 = set_point(MAX_X - 1, 0, MAP[0][MAX_X - 1]);
	p2 = choice(env, p2);
	OFF.x = (WIDTH - (p2.x - p1.x)) / 2 - p1.x;
	p1 = set_point(0, 0, MAP[0][0]);
	p1 = choice(env, p1);
	p2 = set_point(MAX_X - 1, MAX_Y - 1, MAP[MAX_Y - 1][MAX_X - 1]);
	p2 = choice(env, p2);
	OFF.y = (HEIGHT - (p2.y - p1.y)) / 2 - p1.y;
	if (MAX_X < 30)
		OFF.z = 8 * HEIGHT / WIDTH;
	else if (MAX_X < 90)
		OFF.z = 4 * HEIGHT / WIDTH;
	else if (MAX_X < 270)
		OFF.z = 2 * HEIGHT / WIDTH;
	else
		OFF.z = 1 * HEIGHT / WIDTH;
	OFF.z = OFF.z ? OFF.z : 1;
}

static t_env	*init_env(char *name, int fd)
{
	t_env		*env;

	env = (t_env*)ft_xmalloc(sizeof(t_env));
	name = get_name(name);
	if (!(MLX = mlx_init()) ||
		!(WIN = mlx_new_window(MLX, WIDTH, HEIGHT, name)))
	{
		free(env);
		env = NULL;
		exit(!ft_putstr_fd(_ERROR_5, 2));
	}
	MAX_X = 0;
	MAX_Y = 0;
	CHOICE = 0;
	ANGLEX = 0;
	ANGLEZ = 0;
	COLOR = DEF_COLOR;
	COEFFZ = 1;
	OFF = set_point(0, 0, 0);
	MAP = get_map(fd, &MAX_X, &MAX_Y);
	C = MIN(WIDTH / (MAX_X + 5), HEIGHT / (MAX_Y + 5));
	C = C ? C : 1;
	get_points(env);
	env->img = get_img(MLX);
	return (env);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_env	*env;

	if (argc <= 1)
		exit(!ft_putstr_fd(_ERROR_1, 2));
	else if (argc > 2)
		exit(!ft_putstr_fd(_ERROR_2, 2));
	fd = open(argv[1], O_RDONLY);
	env = init_env(argv[1], fd);
	close(fd);
	print_menu();
	gere_mlx(env);
	return (0);
}
