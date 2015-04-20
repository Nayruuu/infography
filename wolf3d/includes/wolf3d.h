/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 15:10:55 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/14 15:59:34 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>
# include "../sdl2/2.0.3/include/SDL2/SDL.h"
# include "../libft/includes/libft.h"

# define _ERROR_1 "wolf3d: cannot open file..."
# define _ERROR_2 "wolf3d: map seems to be empty..."
# define _ERROR_3 "wolf3d: sdl_init: fail..."
# define _ERROR_4 "wolf3d: failing to get_image..."

# define WIDTH 1600
# define HEIGHT 1000
# define CENTER SDL_WINDOWPOS_CENTERED
# define OPTI SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

# define X ray.pos.x
# define Y ray.pos.y

# define CST_A ANGLE / WIDTH
# define SCREEN (WIDTH / 2) / tan(ANGLE / 2)

# define REDRAW env->redraw
# define WIN env->win
# define IMG env->img->renderer
# define TEXTURE env->img->texture
# define DATA env->img->data

# define MAP env->map->map
# define MAX_W env->map->max_width
# define MAX_H env->map->max_height
# define BLOCK env->map->block_size
# define ACCR env->map->player.accr
# define JUMP env->map->player.jump
# define JUMP_DIRECTION env->map->player.jump_direction
# define ANGLE env->map->player.angle
# define SPEED env->map->player.speed
# define OFF env->map->player.look
# define CAMERA env->map->player.camera
# define DIRECTION env->map->player.direction

# define KEY key_event.key.keysym.sym
# define MOVE_W SDLK_UP
# define MOVE_A SDLK_LEFT
# define MOVE_D SDLK_RIGHT
# define MOVE_S SDLK_DOWN
# define ECHAP 27

# define SET(x, y) (t_pos){x, y}
# define ISET(x, y) (t_point){x, y}
# define POW2(x) (x) * (x)
# define RGB(r, g, b) ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF)
# define MAX(a, b) (a) < (b) ? (b) : (a)

/*
**		Blocks/
**				Blocks management
*/

enum				e_type
{
	VOID,
	WALL
};

typedef enum e_type	t_type;

/*
**		Map/
**			Map Functions
*/

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_player
{
	t_pos			camera;
	int				look;
	double			direction;
	int				accr;
	int				speed;
	int				jump;
	double			angle;
	int				jump_direction;
}					t_player;

t_type				**get_map(int fd, int *max_h, int *max_w);
void				free_line(char **data);

/*
**		Env/
**			Env Functions
*/

typedef struct		s_img
{
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	Uint32			*data;
}					t_img;

typedef struct		s_map
{
	t_type			**map;
	t_player		player;
	int				max_width;
	int				max_height;
	int				block_size;

}					t_map;

typedef struct		s_env
{
	int				redraw;
	t_map			*map;
	SDL_Window		*win;
	t_img			*img;
}					t_env;

/*
**		Draw/
**			Drawing Functions
*/

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_ray
{
	t_pos			pos;
	Uint32			color;
	double			angle;
	double			dist;
}					t_ray;

void				init_pos(t_env *env);
double				dist(t_pos pos, t_pos camera);
int					hsv_to_rgb(double h, double s, double v);
void				put_pix_to_img(t_env *env, int x, int y, Uint32 color);
void				draw(t_env *env, t_point pos, int wall, int color);
void				check(t_env *env);
void				draw_map(t_env *env);

/*
**		SDL/
**			Mlx Functions
*/

int					check_left(const t_env *env);
int					check_right(const t_env *env);
int					check_down(const t_env *env);
int					check_up(const t_env *env);
int					gere_motion(int x, int y, t_env *env);
int					gere_mouse(int y, t_env *env);
int					gere_key(const Uint8 *keycode, t_env *env);
int					gere_expose(t_env *env);
void				gere_sdl(t_env *env);
void				kill_everything(t_env *env);

#endif
