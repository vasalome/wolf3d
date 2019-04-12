/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keys.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:34:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 16:02:27 by vasalome    ###    #+. /#+    ###.fr     */
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
		info->player.movespeed = 0.2;
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
		info->player.movespeed = 0.05;
	return (0);
}
