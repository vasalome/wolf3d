/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:33:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 16:27:33 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Movements
*/

void	turn_left(t_info *info)
{
	//printf("__turn_left IN\n");
	if (info->player.turn_left == 1)
	{
		info->player.x_old_direction = info->player.x_dir;
		info->player.x_dir = info->player.x_dir *
			cos(info->player.turn_rate) - info->player.y_dir *
			sin(info->player.turn_rate);
		info->player.y_dir = info->player.x_old_direction *
			sin(info->player.turn_rate) + info->player.y_dir *
			cos(info->player.turn_rate);
		info->player.x_old_plane = info->player.x_plane;
		info->player.x_plane = info->player.x_plane *
			cos(info->player.turn_rate) - info->player.y_plane *
			sin(info->player.turn_rate);
		info->player.y_plane = info->player.x_old_plane *
			sin(info->player.turn_rate) + info->player.y_plane *
			cos(info->player.turn_rate);
	}
	//printf("__turn_left OUT\n");
}

void	turn_right(t_info *info)
{
	//printf("__turn_right IN\n");
	if (info->player.turn_right == 1)
	{
		info->player.x_old_direction = info->player.x_dir;
		info->player.x_dir = info->player.x_dir *
			cos(-info->player.turn_rate) - info->player.y_dir *
			sin(-info->player.turn_rate);
		info->player.y_dir = info->player.x_old_direction *
			sin(-info->player.turn_rate) + info->player.y_dir *
			cos(-info->player.turn_rate);
		info->player.x_old_plane = info->player.x_plane;
		info->player.x_plane = info->player.x_plane *
			cos(-info->player.turn_rate) - info->player.y_plane *
			sin(-info->player.turn_rate);
		info->player.y_plane = info->player.x_old_plane *
			sin(-info->player.turn_rate) + info->player.y_plane *
			cos(-info->player.turn_rate);
	}
	//printf("__turn_right OUT\n");
	turn_left(info);
}

void	move_plus1(t_info *info)
{
	//printf("move_plus1 IN\n");
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir
				* info->player.move_speed)][(int)(info->player.y_pos)] != '1')
		info->player.x_pos += info->player.x_dir * info->player.move_speed;
	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos
				+ info->player.y_dir * info->player.move_speed)] != '1')
		info->player.y_pos += info->player.y_dir * info->player.move_speed;
	if (info->map.map[(int)(info->player.x_pos + info->player.x_dir
				* info->player.move_speed)][(int)(info->player.y_pos)] == '3')
	{
		info->player.x_pos += info->player.x_dir * info->player.move_speed;
		info->player.x_pos = info->player.tp[info->player.tp_index++] +
			(info->player.x_pos - (int)info->player.x_pos);
		info->player.y_pos = info->player.tp[info->player.tp_index++] +
			(info->player.y_pos - (int)info->player.y_pos);
	}
	//printf("move_plus1 OUT\n");
}

void	move_plus2(t_info *info)
{
	//printf("move_plus2 IN\n");
	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir
			* info->player.move_speed)][(int)(info->player.y_pos)] != '1')
		info->player.x_pos -= info->player.x_dir * info->player.move_speed;
	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos
			- info->player.y_dir * info->player.move_speed)] != '1')
		info->player.y_pos -= info->player.y_dir * info->player.move_speed;
	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir
			* info->player.move_speed)][(int)(info->player.y_pos)] == '3')
	{
		info->player.x_pos -= info->player.x_dir * info->player.move_speed;
		info->player.x_pos = info->player.tp[info->player.tp_index++] +
			(info->player.x_pos - (int)info->player.x_pos);
		info->player.y_pos = info->player.tp[info->player.tp_index++] +
			(info->player.y_pos - (int)info->player.y_pos);
	}
	//printf("move_plus2 OUT\n");
}

int		move(t_info *info)
{
	//printf("\nmove IN\n\n");
	if (info->player.move_up == 1)
		move_plus1(info);
	if (info->player.move_down == 1)
		move_plus2(info);
	turn_right(info);
	if ((info->player.move_up || info->player.move_down ||
				info->player.turn_right || info->player.turn_left) == 1)
		ray_casting_image(info);
	return (0);
	//printf("move OUT\n");
}
