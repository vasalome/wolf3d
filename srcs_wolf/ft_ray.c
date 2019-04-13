/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ray.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 16:27:35 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Initiate variables at default values for raycasting
*/

void	ray_casting_init(t_info *info, int x)
{
	info->player.x_camera = 2 * x / (double)(info->window.w) - 1;
	info->ray.x_ray_position = info->player.x_pos;
	info->ray.y_ray_position = info->player.y_pos;
	info->ray.x_ray_direction = info->player.x_dir + info->player.x_plane *
		info->player.x_camera;
	info->ray.y_ray_direction = info->player.y_dir + info->player.y_plane *
		info->player.x_camera;
	info->map.x = (int)info->ray.x_ray_position;
	info->map.y = (int)info->ray.y_ray_position;
	wall_detection_init_x(info);
	wall_detection(info);
	if (info->wall.side == 0)
		info->wall.wall_distance = (info->map.x - info->ray.x_ray_position +
				(1 - info->map.x_step) / 2) / info->ray.x_ray_direction;
	else
		info->wall.wall_distance = (info->map.y - info->ray.y_ray_position +
				(1 - info->map.y_step) / 2) / info->ray.y_ray_direction;
}

/*
** Main raycasting function
*/

int		ray_casting(t_info *info)
{
	info->wall.x = -1;
	while (++info->wall.x < info->window.w)
	{
		ray_casting_init(info, info->wall.x);
		info->wall.line_height = (int)(info->window.h / info->wall.wall_distance);
		info->wall.draw_start = -info->wall.line_height / 2 + info->window.h / 2;
		if (info->wall.draw_start < 0)
			info->wall.draw_start = 0;
		info->wall.draw_end = info->wall.line_height / 2 + info->window.h / 2;
		if (info->wall.draw_end >= info->window.h)
			info->wall.draw_end = info->window.h - 1;
		if (info->wall.side == 1)
			info->wall.color = 0x3E2A1A;
		else
			info->wall.color = 0x25190F;
		draw_wall(info->wall.x, info->wall.draw_start - 1,
				info->wall.draw_end, info);
	}
	return (0);
}

/*
** put resulting image of raycasting on scren
*/

void	ray_casting_image(t_info *info)
{
	ray_casting(info);
	if (info->map.map[(int)info->player.x_pos][(int)info->player.y_pos] == '4')
		mlx_string_put(info->window.mlx, info->window.win, info->window.w / 2,
			info->window.h / 2, 255, "GG BRO!");
	/*mlx_put_image_to_window(info->window.mlx, info->window.win,
			info->tex.img, info->window.w / 2, info->window.h - 65);*/
}
