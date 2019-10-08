/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_weapon.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 13:56:47 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 16:32:36 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

void	weapons(t_info *info)
{
	info->wp[0].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/fist_1.xpm", &info->wp[0].xhud, &info->wp[0].yhud);
	info->wp[1].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/p_1.xpm", &info->wp[1].xhud, &info->wp[1].yhud);
	info->wp[2].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/cs_1.xpm", &info->wp[2].xhud, &info->wp[2].yhud);
	info->wp[3].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/shot_1.xpm", &info->wp[3].xhud, &info->wp[3].yhud);
	info->wp[4].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/s_s_1.xpm", &info->wp[4].xhud, &info->wp[4].yhud);
	info->wp[5].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/cg_1.xpm", &info->wp[5].xhud, &info->wp[5].yhud);
	info->wp[6].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/pl_1.xpm", &info->wp[6].xhud, &info->wp[6].yhud);
	info->wp[8].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/rock_1.xpm", &info->wp[8].xhud, &info->wp[8].yhud);
	info->wp[9].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/bfg_1.xpm", &info->wp[9].xhud, &info->wp[9].yhud);
	info->wp[10].img = mlx_xpm_file_to_image(info->win.mlx,\
		"img/oof.xpm", &info->wp[10].xhud, &info->wp[10].yhud);
	info->wp[7].img = mlx_xpm_file_to_image(info->win.mlx,\
		"img/victory.xpm", &info->wp[7].xhud, &info->wp[7].yhud);
}
