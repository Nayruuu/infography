/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 02:20:26 by sde-toda          #+#    #+#             */
/*   Updated: 2015/02/27 14:09:56 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include </opt/X11/include/X11/X.h>
# include "../libft/includes/libft.h"

# define _ERROR_1 "fractol: no selected fractol\nusage: ./fractol -[MJPEBLSU]"
# define _ERROR_2 "fractol: mlx_init: Fail... \n"
# define _ERROR_3 "fractol: failing to get image... \n"
# define _ERROR_4 "fractol: no such fractol\nusage: ./fractol -[MJPEBWSUA]"
# define _ERROR_5 "fractol: illegal option\nusage: ./fractol -[MJPEBLSUA]"

# define WIDTH 645
# define HEIGHT 390
# define DEF_COLOR 0xFFFF230C
# define BLACK 0xFF000000
# define WHITE 0xFFFFFFFF

# define UP 65362
# define DOWN 65364
# define RIGHT 65361
# define LEFT 65363
# define ECHAP 65307

# define CSTE cste
# define CSTEX cste.x
# define CSTEY cste.y
# define Z z

# define REEL z.x
# define IMA z.y

# define X p.x
# define Y p.y
# define POWER env->fract.power
# define POS env->fract.pos_mouse
# define MIN env->fract.p1
# define MAX env->fract.p2
# define MIN_X env->fract.p1.x
# define MIN_Y env->fract.p1.y
# define MAX_X env->fract.p2.x
# define MAX_Y env->fract.p2.y
# define POS_X env->fract.pos_mouse.x
# define POS_Y env->fract.pos_mouse.y

# define MODE env->fract.mode
# define REDRAW env->draw
# define OFF env->fract.offset
# define ZOOM env->fract.zoom
# define MOUSE_ON env->fract.mouse_on
# define MOUSE_2_ON env->fract.mouse_2_on

# define PRECI env->preci_iter
# define DESTROY0 env[0]->destroy
# define DESTROY1 env[1]->destroy
# define DESTROY2 env[2]->destroy
# define DESTROY3 env[3]->destroy
# define DESTROY4 env[4]->destroy
# define DESTROY5 env[5]->destroy
# define DESTROY6 env[6]->destroy
# define DESTROY7 env[7]->destroy
# define LOCK_CAM env->lock_cam
# define MAX_ITER env->interations
# define MLX env->mlx
# define WIN env->win
# define CHOICE env->choice
# define IMG env->img->img
# define OPP env->img->opp
# define LINE_S env->img->line_s
# define ENDIAN env->img->endian
# define DATA env->img->data

# define POW2(x) x * x
# define ABS(x) x > 0.0 ? x : -x
# define GET_MAX(x, y) x > y ? x : y
# define MOUSE_X (2 * POS_X - WIDTH) / WIDTH
# define MOUSE_Y (2 * POS_Y - HEIGHT) / HEIGHT
# define SET(x, y) ((t_point){(x), (y)})
# define RGB(r, g, b) ((r & 0xff) << 16) + ((g & 0xFF) << 8) + (b & 0xFF)
# define PUT_STR(m, w, w2, h, c, m2) mlx_string_put(m, w, w2, h, c, m2)

typedef long double	t_ld;

typedef struct		s_point
{
	long double		x;
	long double		y;
}					t_point;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

unsigned int		color(double i, int max_iter, int mode);
t_point				power_complex(const t_point p1, const int power);
t_point				set_point(long double x, long double y);
t_point				mult_comp(const t_point p1, const t_point p2);
t_point				add_complex(const t_point p1, const t_point p2);
t_point				mult_const(t_point p1, t_ld constante);

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

typedef struct		s_fract
{
	t_point			p1;
	t_point			p2;
	t_point			zoom;
	t_point			offset;
	t_point			pos_mouse;
	int				mode;
	int				mouse_on;
	int				mouse_2_on;
	int				power;
}					t_fract;

typedef struct		s_env
{
	int				destroy;
	void			*mlx;
	void			*win;
	t_img			*img;
	int				choice;
	char			draw;
	int				interations;
	int				preci_iter;
	char			lock_cam;
	t_fract			fract;
}					t_env;

/*
**					Mlx/
**						Mlx Functions
*/

void				print_msg(t_env *env);
void				kill_everything(t_env **env);
void				gere_cam(const t_env *env);
void				gere_mlx(t_env *env);
int					gere_loop(t_env **env);
int					gere_expose(t_env *env);
int					gere_motion(int x, int y, t_env *env);
int					gere_click(int keycode, int x, int y, t_env *env);
int					gere_mouse(int keycode, int x, int y, t_env *env);
int					gere_key(int keycode, t_env *env);

/*
**					Draw/
**						 Draw Functions
*/

void				unity(t_env *env);
void				square(t_env *env);
void				escher(t_env *env);
void				phoenix(t_env *env);
void				barnsley(t_env *env);
void				julia(t_env *env);
void				mandelbrot(t_env *env);
void				burning(t_env *env);
void				put_pix_to_img(t_env *env, int x, int y, unsigned color);
#endif
