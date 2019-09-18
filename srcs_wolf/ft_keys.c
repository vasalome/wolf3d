/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keys.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:34:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/18 21:47:15 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"
#include "../includes_wolf/keys.h"

/*
** When pressing key
*/

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
	else if (keycode == 49)
	{
		info->weapon[0].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/pistol/pistol_2_shot.xpm", &info->weapon[0].xhud, &info->weapon[0].yhud);
		info->weapon[1].img = mlx_xpm_file_to_image(info->win.mlx,\
			"knife/knife2.xpm", &info->weapon[1].xhud, &info->weapon[1].yhud);
		ray_casting_image(info);
	}
	else if (keycode == KEY_ESC)
		exit(1);
	return (0);
}

/*
** When releasing key
*/

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
	else if (key == 49)
	{
		info->weapon[0].img = mlx_xpm_file_to_image(info->win.mlx,\
			"weapons/pistol/pistol_1.xpm", &info->weapon[0].xhud, &info->weapon[0].yhud);
		info->weapon[1].img = mlx_xpm_file_to_image(info->win.mlx,\
			"knife/knife1.xpm", &info->weapon[1].xhud, &info->weapon[1].yhud);
		ray_casting_image(info);
	}
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 ||\
		key == KEY_4 || key == KEY_5 || key == KEY_6 ||\
		key == KEY_7 || key == KEY_8 || key == KEY_9)
	{
		info->w_i = key - KEY_1;
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
