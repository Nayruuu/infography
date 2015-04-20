/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:25:41 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 11:58:07 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static t_img	*get_img(void *mlx)
{
	t_img		*img;

	img = (t_img*)ft_xmalloc(sizeof(t_img));
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->img, &img->opp, &img->line_s,
			&img->endian);
	if (!img->img || !img->data)
		exit(!ft_putstr_fd(_ERROR_3, 2));
	img->opp /= 8;
	return (img);
}

static t_env	*init_env(char *name, int choice, void *mlx)
{
	t_env		*env;

	env = (t_env*)ft_xmalloc(sizeof(t_env));
	if (!(MLX = (void *)mlx) ||
		!(WIN = mlx_new_window(MLX, WIDTH, HEIGHT, name)))
	{
		free(env);
		env = NULL;
		exit(!ft_putstr_fd(_ERROR_2, 2));
	}
	POWER = 2;
	MOUSE_ON = 0;
	MOUSE_2_ON = 0;
	env->destroy = 0;
	REDRAW = 0;
	LOCK_CAM = 1;
	PRECI = 0;
	MAX_ITER = 150;
	CHOICE = choice;
	env->img = get_img(MLX);
	return (env);
}

static void		get_fractals(char **argv, void *mlx, t_env **env, int i)
{
	if (argv[i][0] != '-' || ft_strlen(argv[i]) > 2 || ft_strlen(argv[i]) < 2)
		exit(!ft_putendl_fd(_ERROR_5, 2));
	else if ((argv[i][1] == 'M' || argv[i][1] == 'm') && !env[0])
		env[0] = init_env("Mandelbrot", 0, mlx);
	else if ((argv[i][1] == 'J' || argv[i][1] == 'j') && !env[1])
		env[1] = init_env("Julia", 1, mlx);
	else if ((argv[i][1] == 'P' || argv[i][1] == 'p') && !env[2])
		env[2] = init_env("Phoenix", 2, mlx);
	else if ((argv[i][1] == 'E' || argv[i][1] == 'e') && !env[3])
		env[3] = init_env("Black Hole", 3, mlx);
	else if ((argv[i][1] == 'B' || argv[i][1] == 'b') && !env[4])
		env[4] = init_env("Burning Ship", 4, mlx);
	else if ((argv[i][1] == 'L' || argv[i][1] == 'l') && !env[5])
		env[5] = init_env("Barnsley Leaf", 5, mlx);
	else if ((argv[i][1] == 'S' || argv[i][1] == 's') && !env[6])
		env[6] = init_env("Sauron", 6, mlx);
	else if ((argv[i][1] == 'U' || argv[i][1] == 'u') && !env[7])
		env[7] = init_env("Unity", 7, mlx);
	else if (!ft_strchr("MJPEBLSU", ft_toupper(argv[i][1])))
		exit(!ft_putendl_fd(_ERROR_4, 2));
}

static void		gere_events(t_env **env, void *mlx)
{
	gere_mlx(env[0]);
	gere_mlx(env[1]);
	gere_mlx(env[2]);
	gere_mlx(env[3]);
	gere_mlx(env[4]);
	gere_mlx(env[5]);
	gere_mlx(env[6]);
	gere_mlx(env[7]);
	mlx_loop_hook(mlx, &gere_loop, env);
	mlx_loop(mlx);
}

int				main(int argc, char **argv)
{
	int			i;
	t_env		*env[8];
	void		*mlx;

	i = -1;
	mlx = NULL;
	while (++i < 8)
		env[i] = NULL;
	if (argc <= 1)
		exit(!ft_putendl_fd(_ERROR_1, 2));
	else
	{
		i = 0;
		mlx = mlx_init();
		while (++i < argc)
		{
			get_fractals(argv, mlx, env, i);
		}
	}
	gere_events(env, mlx);
	return (0);
}
