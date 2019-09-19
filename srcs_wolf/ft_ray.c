/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ray.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 19:04:06 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

void	ray_casting_init(t_info *info, int x)
{
	info->player.x_camera = 2 * x / (double)(info->win.w) - 1;
	info->ray.x_ray_position = info->player.x_pos;
	info->ray.y_ray_position = info->player.y_pos;
	info->ray.x_ray_direction = info->player.x_dir + info->player.x_plane *\
		info->player.x_camera;
	info->ray.y_ray_direction = info->player.y_dir + info->player.y_plane *\
		info->player.x_camera;
	info->map.x = (int)info->ray.x_ray_position;
	info->map.y = (int)info->ray.y_ray_position;
	wall_detection_init_x(info);
	wall_detection(info);
	if (info->wall.side == 0)
		info->wall.wall_distance = (info->map.x - info->ray.x_ray_position +\
		(1 - info->map.x_step) / 2) / info->ray.x_ray_direction;
	else
		info->wall.wall_distance = (info->map.y - info->ray.y_ray_position +\
		(1 - info->map.y_step) / 2) / info->ray.y_ray_direction;
}

int		ray_casting(t_info *info)
{
	info->wall.x = -1;
	while (++info->wall.x < info->win.w)
	{
		ray_casting_init(info, info->wall.x);
		info->wall.line_height = (int)(info->win.h / info->wall.wall_distance);
		info->wall.draw_start = -info->wall.line_height / 2 + info->win.h / 2;
		if (info->wall.draw_start < 0)
			info->wall.draw_start = 0;
		info->wall.draw_end = info->wall.line_height / 2 + info->win.h / 2;
		if (info->wall.draw_end >= info->win.h)\
			info->wall.draw_end = info->win.h - 1;
		choose_texture_1(info);
		texture_calc(info);
		draw_wall(info->wall.x, info->wall.draw_start - 1,\
				info->wall.draw_end, info);
	}
	return (0);
}

void	hud(t_info *info)
{
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->head[info->player.life - 1].img, 0, 0);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->wp[info->w_i].img, info->win.w / 2 - \
		info->wp[info->w_i].xhud / 2 - 4 + (rand() % 8),\
		info->win.h - info->wp[info->w_i].yhud);
	mlx_put_image_to_window(info->win.mlx, info->win.win, \
	info->wp[info->w_i].icon, 5, 315);
	mlx_destroy_image(info->win.mlx, info->fps.img);
}

void	its_a_trap(t_info *info)
{
	if (info->map.map[(int)info->player.x_pos][(int)info->player.y_pos] == '5')
	{
		if (info->player.can_trap)
		{
			info->player.can_trap = 0;
			info->player.life -= 1;
		}
		mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->wp[10].img, info->win.w / 2 - info->wp[10].xhud /\
		2, info->win.h / 2 - info->wp[10].yhud / 2);
	}
	else
		info->player.can_trap = 1;
}

void	ray_casting_image(t_info *info)
{
	if (!(info->player.life - 1 <= 0))
	{
		skybox(info);
		create_img(info);
		ray_casting(info);
		mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->fps.img, 0, 0);
		if (info->map.map[(int)info->player.x_pos]\
		[(int)info->player.y_pos] == '4')
			mlx_put_image_to_window(info->win.mlx, info->win.win,\
			info->wp[7].img, info->win.w / 2 - info->wp[7].xhud / 2,\
			info->win.h / 2 - info->wp[7].yhud / 2);
		its_a_trap(info);
		hud(info);
	}
	else
		game_over(info);
}
