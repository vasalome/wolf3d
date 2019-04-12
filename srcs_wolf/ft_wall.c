/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wall.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:37:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 15:58:43 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** draw image with vertical lines
*/

void	draw_wall(int x, int drawstart, int drawend, t_info *info)
{
	int		y;

	y = -1;
	while (++y <= drawstart)
		mlx_pixel_put(info->window.mlx, info->window.win, x, y, 0xAAEEFF);
	while (++drawstart <= drawend)
		mlx_pixel_put(info->window.mlx, info->window.win, x,
				drawstart, info->wall.color);
	y = drawstart - 1;
	while (++y < info->window.h)
		mlx_pixel_put(info->window.mlx, info->window.win, x, y, 0xDEB887);
}

/*
** Initiate variables to default values for wall detection
*/

void	wall_detection_init_y(t_info *info)
{
	info->ray.ydeltadistance = sqrt(1 + (info->ray.xraydirection *
				info->ray.xraydirection) / (info->ray.yraydirection *
					info->ray.yraydirection));
	if (info->ray.yraydirection < 0)
	{
		info->map.ystep = -1;
		info->ray.ysidedistance = (info->ray.yrayposition -
				info->map.y) * info->ray.ydeltadistance;
	}
	else
	{
		info->map.ystep = 1;
		info->ray.ysidedistance = (info->map.y + 1.0 -
				info->ray.yrayposition) * info->ray.ydeltadistance;
	}
}

void	wall_detection_init_x(t_info *info)
{
	info->ray.xdeltadistance = sqrt(1 + (info->ray.yraydirection *
				info->ray.yraydirection) / (info->ray.xraydirection *
					info->ray.xraydirection));
	if (info->ray.xraydirection < 0)
	{
		info->map.xstep = -1;
		info->ray.xsidedistance = (info->ray.xrayposition -
				info->map.x) * info->ray.xdeltadistance;
	}
	else
	{
		info->map.xstep = 1;
		info->ray.xsidedistance = (info->map.x + 1.0 -
				info->ray.xrayposition) * info->ray.xdeltadistance;
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
		if (info->ray.xsidedistance < info->ray.ysidedistance)
		{
			info->ray.xsidedistance += info->ray.xdeltadistance;
			info->map.x += info->map.xstep;
			info->wall.side = 0;
		}
		else
		{
			info->ray.ysidedistance += info->ray.ydeltadistance;
			info->map.y += info->map.ystep;
			info->wall.side = 1;
		}
		if (info->map.map[info->map.x][info->map.y] == '1')
			info->map.hit = 1;
	}
}
