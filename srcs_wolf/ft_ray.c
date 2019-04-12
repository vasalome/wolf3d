/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ray.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 15:40:25 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Initiate variables at default values for raycasting
*/

void	ray_casting_init(t_info *info, int x)
{
	info->player.xcamera = 2 * x / (double)(info->window.w) - 1;
	info->ray.xrayposition = info->player.xpos;
	info->ray.yrayposition = info->player.ypos;
	info->ray.xraydirection = info->player.xdir + info->player.xplane *
		info->player.xcamera;
	info->ray.yraydirection = info->player.ydir + info->player.yplane *
		info->player.xcamera;
	info->map.x = (int)info->ray.xrayposition;
	info->map.y = (int)info->ray.yrayposition;
	wall_detection_init_x(info);
	wall_detection(info);
	if (info->wall.side == 0)
		info->wall.walldistance = (info->map.x - info->ray.xrayposition +
				(1 - info->map.xstep) / 2) / info->ray.xraydirection;
	else
		info->wall.walldistance = (info->map.y - info->ray.yrayposition +
				(1 - info->map.ystep) / 2) / info->ray.yraydirection;
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
		info->wall.lineheight = (int)(info->window.h / info->wall.walldistance);
		info->wall.drawstart = -info->wall.lineheight / 2 + info->window.h / 2;
		if (info->wall.drawstart < 0)
			info->wall.drawstart = 0;
		info->wall.drawend = info->wall.lineheight / 2 + info->window.h / 2;
		if (info->wall.drawend >= info->window.h)
			info->wall.drawend = info->window.h - 1;
		if (info->wall.side == 1)
			info->wall.color = 0x3E2A1A;
		else
			info->wall.color = 0x25190F;
		draw_wall(info->wall.x, info->wall.drawstart - 1,
				info->wall.drawend, info);
	}
	return (0);
}

/*
** put resulting image of raycasting on scren
*/

void	ray_casting_image(t_info *info)
{
	ray_casting(info);
	if (info->map.map[(int)info->player.xpos][(int)info->player.ypos] == '4')
		mlx_string_put(info->window.mlx, info->window.win, info->window.w / 2,
			info->window.h / 2, 255, "GG BRO!");
	/*mlx_put_image_to_window(info->window.mlx, info->window.win,
			info->tex.img, info->window.w / 2, info->window.h - 65);*/
}
