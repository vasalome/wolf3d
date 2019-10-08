/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keys.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:34:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 17:11:33 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"
#include "../includes_wolf/keys.h"

void	press_weapon_2(t_info *info)
{
	info->wp[0].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/fist_1.xpm", &info->wp[0].xhud, &info->wp[0].yhud);
	info->wp[1].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/p_2-2.xpm", &info->wp[1].xhud, &info->wp[1].yhud);
	info->wp[2].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/cs_2-2.xpm", &info->wp[2].xhud, &info->wp[2].yhud);
	info->wp[3].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/shot_1.xpm", &info->wp[3].xhud, &info->wp[3].yhud);
	info->wp[4].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/s_s_1.xpm", &info->wp[4].xhud, &info->wp[4].yhud);
	info->wp[5].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/cg_2-2.xpm", &info->wp[5].xhud, &info->wp[5].yhud);
	info->wp[6].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/pl_1.xpm", &info->wp[6].xhud, &info->wp[6].yhud);
	info->wp[8].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/rock_1.xpm", &info->wp[8].xhud, &info->wp[8].yhud);
	info->wp[9].img = mlx_xpm_file_to_image(info->win.mlx,\
		"weapons/xpm/bfg_1.xpm", &info->wp[9].xhud, &info->wp[9].yhud);
	info->shot += 1;
}

void	press_weapon(t_info *info)
{
	if (info->shot == 1)
	{
		info->wp[0].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/fist_2.xpm", &info->wp[0].xhud, &info->wp[0].yhud);
		info->wp[1].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/p_2.xpm", &info->wp[1].xhud, &info->wp[1].yhud);
		info->wp[2].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/cs_2.xpm", &info->wp[2].xhud, &info->wp[2].yhud);
		info->wp[3].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/shot_2.xpm", &info->wp[3].xhud, &info->wp[3].yhud);
		info->wp[4].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/s_s_2.xpm", &info->wp[4].xhud, &info->wp[4].yhud);
		info->wp[5].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/cg_2.xpm", &info->wp[5].xhud, &info->wp[5].yhud);
		info->wp[6].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/pl_2.xpm", &info->wp[6].xhud, &info->wp[6].yhud);
		info->wp[8].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/rock_2.xpm", &info->wp[8].xhud, &info->wp[8].yhud);
		info->wp[9].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/xpm/bfg_2.xpm", &info->wp[9].xhud, &info->wp[9].yhud);
		info->shot -= 1;
	}
	else if (info->shot == 0)
		press_weapon_2(info);
}

int		key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		info->player.move_up = 1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		info->player.move_down = 1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		info->player.turn_right = 1;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		info->player.turn_left = 1;
	else if (keycode == KEY_SHIFT_L || keycode == KEY_SHIFT_R)
		info->player.move_speed = 0.2;
	else if (keycode == KEY_SPACE)
	{
		press_weapon(info);
		ray_casting_image(info);
	}
	else if (keycode == KEY_ESC)
	{
		exit(1);
		mlx_destroy_window(info->win.mlx, info->win.win);
	}
	return (0);
}

void	reset_weapon(t_info *info)
{
	info->shot = 1;
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
}

int		key_release(int key, t_info *info)
{
	if (key == KEY_W || key == KEY_UP)
		info->player.move_up = 0;
	else if (key == KEY_S || key == KEY_DOWN)
		info->player.move_down = 0;
	else if (key == KEY_D || key == KEY_RIGHT)
		info->player.turn_right = 0;
	else if (key == KEY_A || key == KEY_LEFT)
		info->player.turn_left = 0;
	else if (key == KEY_SHIFT_L || key == KEY_SHIFT_R)
		info->player.move_speed = 0.05;
	else if (key == KEY_SPACE)
	{
		reset_weapon(info);
		ray_casting_image(info);
	}
	else if (key == KEY_1_NUM || key == KEY_2_NUM || key == KEY_3_NUM ||\
		key == KEY_4_NUM || key == KEY_5_NUM || key == KEY_6_NUM ||\
		key == KEY_7_NUM || key == KEY_8_NUM || key == KEY_9_NUM)
	{
		info->w_i = key - KEY_1_NUM;
		ray_casting_image(info);
	}
	return (0);
}
