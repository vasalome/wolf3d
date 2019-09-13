/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 18:02:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/24 19:24:34 by vasalome    ###    #+. /#+    ###.fr     */
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
# include <pthread.h>

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
	int				*tlp;
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
	int				*tp;
	int				tp_index;
	int				life;
	int				canTrap;
}					t_player;

typedef struct		s_window
{
	int				w;
	int				h;
	void			*mlx;
	void			*win;
}					t_window;

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
	int				trap;
}					t_wall;

typedef struct		s_weapon
{
	void			*img;
	int				xhud;
	int				yhud;
}					t_weapon;

typedef struct		s_info
{
	t_tex			tex;
	t_ray			ray;
	t_player		player;
	t_window		window;
	t_map			map;
	t_wall			wall;
	t_weapon		weapon[3];
	t_weapon		head[8];
	t_weapon		img;
	t_tex			fps;
	int				w_i;
}					t_info;

void				init_map(t_info *info);
void				init_player(t_info *info);
void				init_window(t_info *info);
void				init(t_info *info);

int					key_press(int keycode, t_info *info);
int					key_release(int keycode, t_info *info);

int					set_map_size(t_info *info);
int					create_map(t_info *info);
void				create_img(t_info *info);
void				fill_map(t_info *info);

void				turn_left(t_info *info);
void				turn_right(t_info *info);
int					move(t_info *info);

void				ray_casting_init(t_info *info, int x);
int					ray_casting(t_info *info);
void				ray_casting_image(t_info *info);

int					get_spawn(t_info *info);

void				draw_wall(int x, int drawstart, int drawend, t_info *info);
void				wall_detection_init_y(t_info *info);
void				wall_detection_init_x(t_info *info);
void				wall_detection(t_info *info);

int					red_cross(void);
int					ft_usage(void);

#endif
