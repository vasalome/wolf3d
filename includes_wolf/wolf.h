/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 18:02:24 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 14:57:27 by vasalome    ###    #+. /#+    ###.fr     */
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
}					t_tex;

typedef struct		s_ray
{
	double			xrayposition;
	double			yrayposition;
	double			xraydirection;
	double			yraydirection;
	double			xsidedistance;
	double			ysidedistance;
	double			xdeltadistance;
	double			ydeltadistance;
}					t_ray;

typedef struct		s_player
{
	double			xcamera;
	double			xpos;
	double			ypos;
	double			xoldposition;
	double			yoldposition;
	double			xdir;
	double			ydir;
	double			xplane;
	double			yplane;
	double			xolddirection;
	double			xoldplane;
	double			movespeed;
	double			turnrate;
	int				turn_right;
	int				turn_left;
	int				move_up;
	int				move_down;
	int				*tp;
	int				tpindex;
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
	int				xstep;
	int				ystep;
	int				hit;
	int				width;
	int				height;
	double			xspawn;
	double			yspawn;
	char			*name;
	char			**map;
}					t_map;

typedef struct		s_wall
{
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				side;
	int				color;
	double			walldistance;
	int				x;
}					t_wall;

typedef struct		s_info
{
	t_tex			tex;
	t_ray			ray;
	t_player		player;
	t_window		window;
	t_map			map;
	t_wall			wall;
}					t_info;

void				init_map(t_info *info);
void				init_player(t_info *info);
void				init_window(t_info *info);
void				init(t_info *info);

int					key_press(int keycode, t_info *info);
int					key_release(int keycode, t_info *info);

int					set_map_size(t_info *info);
int					create_map(t_info *info);
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

#endif
