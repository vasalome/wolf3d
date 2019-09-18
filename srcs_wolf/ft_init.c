/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:32:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 19:05:38 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Initate default variables when game start
*/

void	weapons(t_info *info)
{
	info->weapon[0].img = mlx_xpm_file_to_image(info->window.mlx,\
		"weapons/pistol/pistol_1.xpm", &info->weapon[0].xhud, &info->weapon[0].yhud);
	info->weapon[1].img = mlx_xpm_file_to_image(info->window.mlx,\
		"knife/knife1.xpm", &info->weapon[1].xhud, &info->weapon[1].yhud);
	info->weapon[2].img = mlx_xpm_file_to_image(info->window.mlx,\
		"pistol/pistol1.xpm", &info->weapon[2].xhud, &info->weapon[2].yhud);
}

void	hub_life(t_info *info)
{
	info->head[0].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/0_hub_2.xpm", &info->head[0].xhud, &info->head[0].yhud);
	info->head[1].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/10_hub_2.xpm", &info->head[1].xhud, &info->head[1].yhud);
	info->head[2].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/20_hub_2.xpm", &info->head[2].xhud, &info->head[2].yhud);
	info->head[3].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/30_hub_2.xpm", &info->head[3].xhud, &info->head[3].yhud);
	info->head[4].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/40_hub_2.xpm", &info->head[4].xhud, &info->head[4].yhud);
	info->head[5].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/50_hub_2.xpm", &info->head[5].xhud, &info->head[5].yhud);
	info->head[6].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/60_hub_2.xpm", &info->head[6].xhud, &info->head[6].yhud);
	info->head[7].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/70_hub_2.xpm", &info->head[7].xhud, &info->head[7].yhud);
	info->head[8].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/80_hub_2.xpm", &info->head[8].xhud, &info->head[8].yhud);
	info->head[9].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/90_hub_2.xpm", &info->head[9].xhud, &info->head[9].yhud);
	info->head[10].img = mlx_xpm_file_to_image(info->window.mlx,\
		"hub/100_hub_2.xpm", &info->head[10].xhud, &info->head[10].yhud);
}

void	textures_wall_1(t_info *info)
{
	info->wt[0].img = mlx_xpm_file_to_image(info->window.mlx,\
		"wall/1/face_c-dark.xpm", &info->wt[0].xhud, &info->wt[0].yhud);
	info->wt[0].data = mlx_get_data_addr(info->wt[0].img, &info->wt[0].bpp,\
		&info->wt[0].sizeline, &info->wt[0].endian);

	info->wt[1].img = mlx_xpm_file_to_image(info->window.mlx,\
		"wall/1/face_a-light.xpm", &info->wt[1].xhud, &info->wt[1].yhud);
	info->wt[1].data = mlx_get_data_addr(info->wt[1].img, &info->wt[1].bpp,\
		&info->wt[1].sizeline, &info->wt[1].endian);

	info->wt[2].img = mlx_xpm_file_to_image(info->window.mlx,\
		"wall/1/face_b-mid.xpm", &info->wt[2].xhud, &info->wt[2].yhud);
	info->wt[2].data = mlx_get_data_addr(info->wt[2].img, &info->wt[2].bpp,\
		&info->wt[2].sizeline, &info->wt[2].endian);

	info->wt[3].img = mlx_xpm_file_to_image(info->window.mlx,\
		"wall/1/face_d-mid.xpm", &info->wt[3].xhud, &info->wt[3].yhud);
	info->wt[3].data = mlx_get_data_addr(info->wt[3].img, &info->wt[3].bpp,\
		&info->wt[3].sizeline, &info->wt[3].endian);
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
	info->wt[4].img = mlx_xpm_file_to_image(info->window.mlx,\
		"wall/3/door_broke-mid.xpm", &info->wt[4].xhud, &info->wt[4].yhud);
	info->wt[4].data = mlx_get_data_addr(info->wt[4].img, &info->wt[4].bpp,\
		&info->wt[4].sizeline, &info->wt[4].endian);
}

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
	info->player.turn_rate = 0.2;
	info->player.move_speed = 0.05;
	info->player.tp_index = 0;
	info->player.life = 9;
	info->player.canTrap = 1;
}

void	init_window(t_info *info)
{
	info->window.w = WIDTH;
	info->window.h = HEIGHT;
	info->window.mlx = mlx_init();
	info->window.win = mlx_new_window(info->window.mlx, info->window.w,\
		info->window.h, "LES NAZIS C'EST PAS TRES LE COOL");
}

void	init(t_info *info)
{
	init_window(info);
	load_textures(info);
	init_map(info);
	init_player(info);
	ray_casting_image(info);
}