/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keys.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:34:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 16:27:30 by vasalome    ###    #+. /#+    ###.fr     */
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
		info->weapon[0].img = mlx_xpm_file_to_image(info->window.mlx, "pistol/pistol2.xpm",  &info->weapon[0].xhud, &info->weapon[0].yhud);
		info->weapon[1].img = mlx_xpm_file_to_image(info->window.mlx, "knife/knife2.xpm",  &info->weapon[1].xhud, &info->weapon[1].yhud);
		ray_casting_image(info);
	}
	else if (keycode == KEY_ESC)
		exit(1);
	return (0);
}

/*
** When releasing key
*/

int		key_release(int keycode, t_info *info)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		info->player.move_up = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		info->player.move_down = 0;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		info->player.turn_right = 0;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		info->player.turn_left = 0;
	else if (keycode == KEY_SHIFT_L || keycode == KEY_SHIFT_R)
		info->player.move_speed = 0.05;
	else if (keycode == 49)
	{
		info->weapon[0].img = mlx_xpm_file_to_image(info->window.mlx, "pistol/pistol1.xpm", &info->weapon[0].xhud, &info->weapon[0].yhud);
		info->weapon[1].img = mlx_xpm_file_to_image(info->window.mlx, "knife/knife1.xpm",  &info->weapon[1].xhud, &info->weapon[1].yhud);
		ray_casting_image(info);
	}
	else if (keycode == 83 || keycode == 84 || keycode == 85)
	{
		info->w_i = keycode - 83;
		ray_casting_image(info);
	}
	return (0);
}
