/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 18:02:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:55:36 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <Tk/X11/X.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <time.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct		s_fillmap
{
	int				fd;
	char			*line;
	int				i;
	int				x;
	int				y;
	int				j;
}					t_fillmap;

typedef struct		s_setmap
{
	int				fd;
	char			*line;
	int				h;
	int				w;
	int				tmp;
	int				tp;
}					t_setmap;

typedef struct		s_tex
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	int				xhud;
	int				yhud;
	int				tex_x;
	int				tex_y;
}					t_tex;

typedef struct		s_ray
{
	double			x_ray_position;
	double			y_ray_position;
	double			x_ray_direction;
	double			y_ray_direction;
	double			x_side_distance;
	double			y_side_distance;
	double			x_delta_distance;
	double			y_delta_distance;
}					t_ray;

typedef struct		s_player
{
	double			x_camera;
	double			x_pos;
	double			y_pos;
	double			x_old_position;
	double			y_old_position;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			x_old_direction;
	double			x_old_plane;
	double			move_speed;
	double			turn_rate;
	int				turn_right;
	int				turn_left;
	int				move_up;
	int				move_down;
	int				tp[9999];
	int				tp_index;
	int				life;
	int				can_trap;
}					t_player;

typedef struct		s_win
{
	int				w;
	int				h;
	void			*mlx;
	void			*win;
}					t_win;

typedef struct		s_map
{
	int				x;
	int				y;
	int				x_step;
	int				y_step;
	int				hit;
	int				width;
	int				height;
	double			x_spawn;
	double			y_spawn;
	char			*name;
	char			**map;
}					t_map;

typedef struct		s_wall
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				side;
	int				color;
	int				r;
	int				g;
	int				b;
	int				a;
	double			wall_distance;
	int				x;
	double			ux;
	int				trap;
}					t_wall;

typedef struct		s_weapon
{
	void			*img;
	int				xhud;
	int				yhud;
	void			*icon;
	int				iconx;
	int				icony;
}					t_weapon;

typedef struct		s_info
{
	t_tex			tex;
	t_ray			ray;
	t_player		player;
	t_win			win;
	t_map			map;
	t_wall			wall;
	t_weapon		wp[11];
	t_weapon		head[10];
	t_weapon		img;
	t_tex			fps;
	t_tex			wt[30];
	int				w_i;
	int				w_j;
	int				shot;
}					t_info;

/*
** srcs:			ft_init.c
*/

void				init(t_info *info);
void				init_window(t_info *info);
void				load_textures(t_info *info);
void				init_map(t_info *info);
void				init_player(t_info *info);

/*
** srcs:			ft_init_hub.c
*/

void				icon(t_info *info);
void				icon_2(t_info *info);
void				hub_life(t_info *info);

/*
** srcs:			ft_init_texture.c
*/

void				textures_wall_1(t_info *info);
void				textures_wall_2(t_info *info);
void				textures_door_1(t_info *info);
void				textures_door_2(t_info *info);

/*
** srcs:			ft_init_weapon.c
*/

void				weapons(t_info *info);

/*
** srcs:			ft_map.c
*/

int					fill_map(t_info *info);
void				fill_map_plus(t_fillmap *fill, t_info *info);
void				tp_destination(t_fillmap *fill, t_info *info,\
						char *str, int *i);
int					create_map(t_info *info);
int					set_map_size(t_info *info);

/*
** srcs:			ft_ray.c
*/

void				ray_casting_image(t_info *info);
void				its_a_trap(t_info *info);
void				hud(t_info *info);
int					ray_casting(t_info *info);
void				ray_casting_init(t_info *info, int x);

/*
** srcs:			ft_wall.c
*/

void				wall_detection(t_info *info);
void				wall_detection_plus(t_info *info);
void				wall_detection_init_x(t_info *info);
void				wall_detection_init_y(t_info *info);
void				create_img(t_info *info);

/*
** srcs:			ft_draw_wall.c
*/

void				draw_wall(int x, int draw_start, int draw_end,\
						t_info *info);
void				draw_wall_plus(int x, int draw_start,\
						t_info *info, int tex_y);

/*
** srcs:			ft_spawn.c
*/

int					get_spawn(t_info *info);

/*
** srcs:			ft_keys.c
*/

int					key_release(int key, t_info *info);
void				reset_weapon(t_info *info);
int					key_press(int keycode, t_info *info);
void				press_weapon(t_info *info);
void				press_weapon_2(t_info *info);

/*
** srcs:			ft_move.c
*/

int					move(t_info *info);
void				move_plus1(t_info *info);
void				move_plus2(t_info *info);
void				turn_right(t_info *info);
void				turn_left(t_info *info);

/*
** srcs:			ft_teleport.c
*/

void				teleport(t_info *info);
void				teleport2(t_info *info);

/*
** srcs:			ft_textures.c
*/

void				texture_calc(t_info *info);
void				choose_texture_1(t_info *info);
void				choose_texture_2(t_info *info);
void				skybox(t_info *info);
void				game_over(t_info *info);

/*
** srcs:			ft_usage.c
*/

int					red_cross(void);
int					ft_usage(void);

#endif
