/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_move.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:33:41 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 15:52:21 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Movements
*/

void	turn_left(t_info *info)
{
	if (info->player.turn_left == 1)
	{
		info->player.xolddirection = info->player.xdir;
		info->player.xdir = info->player.xdir *
			cos(info->player.turnrate) - info->player.ydir *
			sin(info->player.turnrate);
		info->player.ydir = info->player.xolddirection *
			sin(info->player.turnrate) + info->player.ydir *
			cos(info->player.turnrate);
		info->player.xoldplane = info->player.xplane;
		info->player.xplane = info->player.xplane *
			cos(info->player.turnrate) - info->player.yplane *
			sin(info->player.turnrate);
		info->player.yplane = info->player.xoldplane *
			sin(info->player.turnrate) + info->player.yplane *
			cos(info->player.turnrate);
	}
}

void	turn_right(t_info *info)
{
	if (info->player.turn_right == 1)
	{
		info->player.xolddirection = info->player.xdir;
		info->player.xdir = info->player.xdir *
			cos(-info->player.turnrate) - info->player.ydir *
			sin(-info->player.turnrate);
		info->player.ydir = info->player.xolddirection *
			sin(-info->player.turnrate) + info->player.ydir *
			cos(-info->player.turnrate);
		info->player.xoldplane = info->player.xplane;
		info->player.xplane = info->player.xplane *
			cos(-info->player.turnrate) - info->player.yplane *
			sin(-info->player.turnrate);
		info->player.yplane = info->player.xoldplane *
			sin(-info->player.turnrate) + info->player.yplane *
			cos(-info->player.turnrate);
	}
	turn_left(info);
}

void	move_plus1(t_info *info)
{
	if (info->map.map[(int)(info->player.xpos + info->player.xdir
				* info->player.movespeed)][(int)(info->player.ypos)] != '1')
		info->player.xpos += info->player.xdir * info->player.movespeed;
	if (info->map.map[(int)(info->player.xpos)][(int)(info->player.ypos
				+ info->player.ydir * info->player.movespeed)] != '1')
		info->player.ypos += info->player.ydir * info->player.movespeed;
	if (info->map.map[(int)(info->player.xpos + info->player.xdir
				* info->player.movespeed)][(int)(info->player.ypos)] == '3')
	{
		info->player.xpos += info->player.xdir * info->player.movespeed;
		info->player.xpos = info->player.tp[info->player.tpindex++] +
			(info->player.xpos - (int)info->player.xpos);
		info->player.ypos = info->player.tp[info->player.tpindex++] +
			(info->player.ypos - (int)info->player.ypos);
	}
	/*if (info->map.map[(int)(info->player.xpos)][(int)(info->player.ypos
				+ info->player.ydir * info->player.movespeed)] == '3')
	{
		info->player.ypos += info->player.ydir * info->player.movespeed;
	}*/
}

void	move_plus2(t_info *info)
{
	if (info->map.map[(int)(info->player.xpos - info->player.xdir
			* info->player.movespeed)][(int)(info->player.ypos)] != '1')
		info->player.xpos -= info->player.xdir * info->player.movespeed;
	if (info->map.map[(int)(info->player.xpos)][(int)(info->player.ypos
			- info->player.ydir * info->player.movespeed)] != '1')
		info->player.ypos -= info->player.ydir * info->player.movespeed;
	if (info->map.map[(int)(info->player.xpos - info->player.xdir
			* info->player.movespeed)][(int)(info->player.ypos)] == '3')
	{
		info->player.xpos -= info->player.xdir * info->player.movespeed;
		info->player.xpos = info->player.tp[info->player.tpindex++] +
			(info->player.xpos - (int)info->player.xpos);
		info->player.ypos = info->player.tp[info->player.tpindex++] +
			(info->player.ypos - (int)info->player.ypos);
	}
	/*if (info->map.map[(int)(info->player.xpos)][(int)(info->player.ypos
			- info->player.ydir * info->player.movespeed)] == '3')
	{
		info->player.ypos -= info->player.ydir * info->player.movespeed;
	}*/
}

int		move(t_info *info)
{
	if (info->player.move_up == 1)
		move_plus1(info);
	if (info->player.move_down == 1)
		move_plus2(info);
	turn_right(info);
	if ((info->player.move_up || info->player.move_down ||
				info->player.turn_right || info->player.turn_left) == 1)
		ray_casting_image(info);
	return (0);
}
