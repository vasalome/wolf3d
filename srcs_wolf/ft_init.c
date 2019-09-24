/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:32:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 14:01:05 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Initate default variables when game start
*/

void	init_player(t_info *info)
{
	info->player.x_pos = info->map.x_spawn;
	info->player.y_pos = info->map.y_spawn;
	info->player.x_dir = -1;
	info->player.y_dir = 0;
	info->player.x_plane = 0;
	info->player.y_plane = 0.66;
	info->player.move_down = 0;
	info->player.move_up = 0;
	info->player.turn_left = 0;
	info->player.turn_right = 0;
	info->player.turn_rate = 0.1;
	info->player.move_speed = 0.05;
	info->player.tp_index = 0;
	info->player.life = 11;
	info->player.can_trap = 1;
}

void	init_map(t_info *info)
{
	if (set_map_size(info) == -1)
	{
		ft_usage();
		exit(0);
	}
	create_map(info);
	if (fill_map(info) == -1)
	{
		ft_usage();
		exit(0);
	}
	get_spawn(info);
}

void	load_textures(t_info *info)
{
	info->w_i = 0;
	info->w_j = 0;
	weapons(info);
	hub_life(info);
	textures_wall_1(info);
	textures_door_1(info);
	textures_wall_2(info);
	textures_door_2(info);
}

void	init_window(t_info *info)
{
	info->win.w = WIDTH;
	info->win.h = HEIGHT;
	info->win.mlx = mlx_init();
	info->win.win = mlx_new_window(info->win.mlx, info->win.w,\
		info->win.h, "LES NAZIS C'EST PAS TRES LE COOL");
}

void	init(t_info *info)
{
	info->shot = 1;
	init_window(info);
	load_textures(info);
	init_map(info);
	init_player(info);
	icon(info);
	ray_casting_image(info);
}
