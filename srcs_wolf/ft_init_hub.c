/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_hub.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 13:53:37 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:01:56 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

void	hub_life(t_info *info)
{
	info->head[0].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/0_hub_2.xpm", &info->head[0].xhud, &info->head[0].yhud);
	info->head[1].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/10_hub_2.xpm", &info->head[1].xhud, &info->head[1].yhud);
	info->head[2].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/20_hub_2.xpm", &info->head[2].xhud, &info->head[2].yhud);
	info->head[3].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/30_hub_2.xpm", &info->head[3].xhud, &info->head[3].yhud);
	info->head[4].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/40_hub_2.xpm", &info->head[4].xhud, &info->head[4].yhud);
	info->head[5].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/50_hub_2.xpm", &info->head[5].xhud, &info->head[5].yhud);
	info->head[6].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/60_hub_2.xpm", &info->head[6].xhud, &info->head[6].yhud);
	info->head[7].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/70_hub_2.xpm", &info->head[7].xhud, &info->head[7].yhud);
	info->head[8].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/80_hub_2.xpm", &info->head[8].xhud, &info->head[8].yhud);
	info->head[9].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/90_hub_2.xpm", &info->head[9].xhud, &info->head[9].yhud);
	info->head[10].img = mlx_xpm_file_to_image(info->win.mlx,\
		"hub/100_hub_2.xpm", &info->head[10].xhud, &info->head[10].yhud);
}

void	icon_2(t_info *info)
{
	info->wp[5].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/cg_icon.xpm", &info->wp[5].iconx,\
		&info->wp[5].icony);
	info->wp[6].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/pl_icon.xpm", &info->wp[6].iconx,\
		&info->wp[6].icony);
	info->wp[8].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/rock_icon.xpm", &info->wp[8].iconx,\
		&info->wp[8].icony);
	info->wp[9].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/bfg_icon.xpm", &info->wp[9].iconx,\
		&info->wp[9].icony);
}

void	icon(t_info *info)
{
	info->wp[0].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/finger_icon.xpm", &info->wp[0].iconx,\
		&info->wp[0].icony);
	info->wp[1].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/p_icon.xpm", &info->wp[1].iconx,\
		&info->wp[1].icony);
	info->wp[2].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/cs_icon.xpm", &info->wp[2].iconx,\
		&info->wp[2].icony);
	info->wp[3].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/shot_icon.xpm", &info->wp[3].iconx,\
		&info->wp[3].icony);
	info->wp[4].icon = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/icon/s_s_icon.xpm", &info->wp[4].iconx,\
		&info->wp[4].icony);
	icon_2(info);
}
