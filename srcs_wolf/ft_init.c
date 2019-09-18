/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:32:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 16:42:12 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Initate default variables when game start
*/

void	init_map(t_info *info)
{
	//printf("init_map IN\n");
	
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

	//printf("init_map OUT\n");
}

void	load_textures(t_info *info)
{
	//printf("load_textures IN\n");
	info->w_i = 0;
	info->w_j = 0;
	info->weapon[0].img = mlx_xpm_file_to_image(info->window.mlx,\
		"pistol/pistol1.xpm", &info->weapon[0].xhud, &info->weapon[0].yhud);
	info->weapon[1].img = mlx_xpm_file_to_image(info->window.mlx,\
		"knife/knife1.xpm", &info->weapon[1].xhud, &info->weapon[1].yhud);
	info->head[0].img = mlx_xpm_file_to_image(info->window.mlx,\
		"head/head8.xpm", &info->head[0].xhud, &info->head[0].yhud);
	info->head[1].img = mlx_xpm_file_to_image(info->window.mlx,\
		"head/head7.xpm", &info->head[1].xhud, &info->head[1].yhud);
	info->head[2].img = mlx_xpm_file_to_image(info->window.mlx,\
		"head/head6.xpm", &info->head[2].xhud, &info->head[2].yhud);
	info->head[3].img = mlx_xpm_file_to_image(info->window.mlx,\
		"head/head5.xpm", &info->head[3].xhud, &info->head[3].yhud);
	info->head[4].img = mlx_xpm_file_to_image(info->window.mlx,\
		"head/head4.xpm", &info->head[4].xhud, &info->head[4].yhud);
	info->head[5].img = mlx_xpm_file_to_image(info->window.mlx,\
		"head/head3.xpm", &info->head[5].xhud, &info->head[5].yhud);
	info->head[6].img = mlx_xpm_file_to_image(info->window.mlx,\
		"head/head2.xpm", &info->head[6].xhud, &info->head[6].yhud);
	info->head[7].img = mlx_xpm_file_to_image(info->window.mlx,\
		"100_hub_2.xpm", &info->head[7].xhud, &info->head[7].yhud);
		
	info->wt[0].img = mlx_xpm_file_to_image(info->window.mlx,"face_d-dark.xpm", &info->wt[0].xhud, &info->wt[0].yhud);
	info->wt[0].data = mlx_get_data_addr(info->wt[0].img, &info->wt[0].bpp,\
		&info->wt[0].sizeline, &info->wt[0].endian);

	info->wt[1].img = mlx_xpm_file_to_image(info->window.mlx,"face_a-light.xpm", &info->wt[1].xhud, &info->wt[1].yhud);
	info->wt[1].data = mlx_get_data_addr(info->wt[1].img, &info->wt[1].bpp,\
		&info->wt[1].sizeline, &info->wt[1].endian);

	info->wt[2].img = mlx_xpm_file_to_image(info->window.mlx,"face_b-mid.xpm", &info->wt[2].xhud, &info->wt[2].yhud);
	info->wt[2].data = mlx_get_data_addr(info->wt[2].img, &info->wt[2].bpp,\
		&info->wt[2].sizeline, &info->wt[2].endian);

	info->wt[3].img = mlx_xpm_file_to_image(info->window.mlx,"face_d-mid.xpm", &info->wt[3].xhud, &info->wt[3].yhud);
	info->wt[3].data = mlx_get_data_addr(info->wt[3].img, &info->wt[3].bpp,\
		&info->wt[3].sizeline, &info->wt[3].endian);

	info->wt[4].img = mlx_xpm_file_to_image(info->window.mlx,"door_broke-light.xpm", &info->wt[4].xhud, &info->wt[4].yhud);
	info->wt[4].data = mlx_get_data_addr(info->wt[4].img, &info->wt[4].bpp,\
		&info->wt[4].sizeline, &info->wt[4].endian);
	//printf("load_textures OUT\n");
}

void	init_player(t_info *info)
{
	//printf("init_player IN\n");
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
	info->player.life = 8;
	info->player.canTrap = 1;
	//printf("init_player OUT\n");
}

void	init_window(t_info *info)
{
	//printf("init_window IN\n");
	info->window.w = WIDTH;
	info->window.h = HEIGHT;
	info->window.mlx = mlx_init();
	info->window.win = mlx_new_window(info->window.mlx, info->window.w,\
		info->window.h, "LES NAZIS C'EST PAS TRES LE COOL");
	//printf("init_window OUT\n");
}

void	init(t_info *info)
{
	//printf("init IN\n");
	init_window(info);
	load_textures(info);
	init_map(info);
	init_player(info);
	ray_casting_image(info);
	//printf("init OUT\n");
}