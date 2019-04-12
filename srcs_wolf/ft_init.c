/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:32:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 14:31:02 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** initate default variables when game start
*/

void	init_map(t_info *info)
{
	set_map_size(info);
	create_map(info);
	fill_map(info);
	get_spawn(info);
}

void	init_player(t_info *info)
{
	info->player.xpos = info->map.xspawn;
	info->player.ypos = info->map.yspawn;
	info->player.xdir = -1;
	info->player.ydir = 0;
	info->player.xplane = 0;
	info->player.yplane = 0.66;
	info->player.move_down = 0;
	info->player.move_up = 0;
	info->player.turn_left = 0;
	info->player.turn_right = 0;
	info->player.turnrate = 0.1;
	info->player.movespeed = 0.05;
	info->player.tpindex = 0;
}

void	init_window(t_info *info)
{
	info->window.w = 640;
	info->window.h = 360;
	info->window.mlx = mlx_init();
	info->window.win = mlx_new_window(info->window.mlx, info->window.w,
			info->window.h, "Wold3d Lnieto");
}

void	init(t_info *info)
{
	init_window(info);
	init_map(info);
	init_player(info);
	ray_casting_image(info);
}
