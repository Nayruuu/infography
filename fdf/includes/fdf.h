/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:20:26 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/10 18:07:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include </opt/X11/include/X11/X.h>
# include "../libft/includes/libft.h"

# define _ERROR_1 "fdf: No selected file\nusage: ./fdf [file]\n"
# define _ERROR_2 "fdf: Too much files\nusage: ./fdf [file]\n"
# define _ERROR_3 "fdf: Something seems to be wrong... Please select new map.\n"
# define _ERROR_4 "fdf: Your map seems to be empty... Please select new one.\n"
# define _ERROR_5 "fdf: mlx_init: Fail...\n"
# define _ERROR_6 "fdf: failing to get image...\n"
# define _ERROR_7 "fdf: invalid map. Map must be a square or a rectangle.\n"
# define ISO "Isometric Projection"
# define PAR "Parallel Projection"

# define WIDTH 2300
# define HEIGHT 1300
# define DEF_COLOR 0xFFFF230C

# define RED (COLOR & 0xFF0000) >> 16
# define GREEN (COLOR & 0xFF00) >> 8
# define BLUE (COLOR & 0xFF)

# define X env->map->point.x
# define Y env->map->point.y
# define Z env->map->point.z

# define X1 p1.x
# define X2 p2.x
# define Y1 p1.y
# define Y2 p2.y
# define Z1 p1.z
# define Z2	p2.z

# define DX draw.dx
# define DY draw.dy
# define _X draw.x
# define _Y draw.y
# define XINC draw.xinc
# define YINC draw.yinc
# define CUMUL draw.cumul

# define COEFFZ env->coeffz
# define CHOICE env->choice
# define COLOR env->color
# define ANGLEX env->anglex
# define ANGLEZ env->anglez
# define MLX env->mlx
# define WIN env->win
# define MAP env->map
# define OFF env->offset
# define MAX_X env->max_x
# define MAX_Y env->max_y
# define C env->c
# define IMG env->img->img
# define OPP env->img->opp
# define DATA env->img->data
# define ENDIAN env->img->endian
# define LINE_S env->img->line_s

# define NEW_P(x, y, z) ft_new_point(x, y, z)
# define MIN(x, y) ft_min(x, y)

# define GC(mlx, z) get_color_value(mlx, z)

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_map
{
	t_point			point;
	struct s_map	*right;
	struct s_map	*left;
}					t_map;

int					ft_min(int x, int y);
int					ft_getnbr(const char *str);
void				free_line(char **stock);
t_point				set_point(int x, int y, int z);

/*
**					Env/
**						Get Environnement
*/

typedef struct		s_img
{
	int				opp;
	int				line_s;
	int				endian;
	char			*data;
	void			*img;
}					t_img;

typedef struct		s_draw
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	int				cumul;
}					t_draw;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**map;
	int				c;
	int				coeffz;
	int				max_x;
	int				max_y;
	t_point			offset;
	t_img			*img;
	double			anglex;
	double			anglez;
	unsigned int	color;
	unsigned int	choice;
}					t_env;

/*
**					Mlx/
**						Mlx Functions
*/

int					gere_key(int keycode, t_env *env);
int					gere_expose(t_env *env);
void				gere_mlx(t_env *env);
void				kill_everything(t_env *env);

/*
**					Draw/
**						 Draw Functions
*/

void				print_menu(void);
void				print_msgs(t_env *env);
t_point				project_para(t_env *env, t_point p);
t_point				project_iso(t_env *env, t_point p);
t_point				choice(t_env *env, t_point p);
void				get_points(t_env *env);
unsigned int		get_color_value(t_env *env, int z);
void				put_pix_to_img(t_env *env, int x, int y,
		unsigned int color);
void				draw_hline(t_point p1, int i, int j, t_env *env);
void				draw_vline(t_point p1, int i, int j, t_env *env);
void				draw(t_env *env);

/*
**					Map/
**						Map control
*/

int					**get_map(int fd, int *max_x, int *max_y);
t_map				*ft_new_point(int x, int y, int z);
t_map				*ft_init_map(void);
void				ft_go_first_point(t_map **map);
void				ft_insert_elem(t_map **map, t_map *elem);
void				ft_destroy_lst(t_map **map);
void				ft_destroy_point(t_map **map);

#endif
