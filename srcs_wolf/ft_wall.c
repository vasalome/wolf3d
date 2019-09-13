/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wall.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:37:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 16:27:37 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** draw image with vertical lines
*/

void	create_img(t_info *info)
{
	info->fps.img = mlx_new_image(info->window.mlx, WIDTH, HEIGHT);
	info->fps.data = mlx_get_data_addr(info->fps.img, &info->fps.bpp,\
		&info->fps.sizeline, &info->fps.endian);
}

void	draw_wall(int x, int draw_start, int draw_end, t_info *info)
{
	int		y;

	y = -1;
	while (++y <= draw_start)
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)255;	
	while (++draw_start <= draw_end)
	{
		info->fps.data[x * 4 + 4 * WIDTH * draw_start] = (char)info->wall.b;
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 1] = (char)info->wall.g;
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 2] = (char)info->wall.r;
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 3] = (char)0;
	}
	y = draw_start - 1;
	while (++y < info->window.h)
	{
		info->fps.data[x * 4 + 4 * WIDTH * y] = (char)226;
		info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)0;
		info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)229;
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;
	}
}

/*
** Initiate variables to default values for wall detection
*/

void	wall_detection_init_y(t_info *info)
{
	info->ray.y_delta_distance = sqrt(1 + (info->ray.x_ray_direction *\
		info->ray.x_ray_direction) / (info->ray.y_ray_direction *\
		info->ray.y_ray_direction));
	if (info->ray.y_ray_direction < 0)
	{
		info->map.y_step = -1;
		info->ray.y_side_distance = (info->ray.y_ray_position -\
			info->map.y) * info->ray.y_delta_distance;
	}
	else
	{
		info->map.y_step = 1;
		info->ray.y_side_distance = (info->map.y + 1.0 -\
			info->ray.y_ray_position) * info->ray.y_delta_distance;
	}
}

void	wall_detection_init_x(t_info *info)
{
	info->ray.x_delta_distance = sqrt(1 + (info->ray.y_ray_direction *\
		info->ray.y_ray_direction) / (info->ray.x_ray_direction *\
		info->ray.x_ray_direction));
	if (info->ray.x_ray_direction < 0)
	{
		info->map.x_step = -1;
		info->ray.x_side_distance = (info->ray.x_ray_position -\
			info->map.x) * info->ray.x_delta_distance;
	}
	else
	{
		info->map.x_step = 1;
		info->ray.x_side_distance = (info->map.x + 1.0 -\
			info->ray.x_ray_position) * info->ray.x_delta_distance;
	}
	wall_detection_init_y(info);
}

/*
** Test if ray hit a wall
*/

void	wall_detection(t_info *info)
{
	info->map.hit = 0;
	while (info->map.hit == 0)
	{
		if (info->ray.x_side_distance < info->ray.y_side_distance)
		{
			info->ray.x_side_distance += info->ray.x_delta_distance;
			info->map.x += info->map.x_step;
			info->wall.side = 0;
		}
		else
		{
			info->ray.y_side_distance += info->ray.y_delta_distance;
			info->map.y += info->map.y_step;
			info->wall.side = 1;
		}
		if (info->map.map[info->map.x][info->map.y] == '1' ||\
			info->map.map[info->map.x][info->map.y] == '5' ||\
			info->map.map[info->map.x][info->map.y] == '6')
			info->map.hit = 1;
		if (info->map.map[info->map.x][info->map.y] == '5')
			info->wall.trap = 1;
		else if (info->map.map[info->map.x][info->map.y] == '6')
			info->wall.trap = 2;
		else
			info->wall.trap = 0;
	}
}
