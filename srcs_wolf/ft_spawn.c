/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_spawn.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:39:26 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 15:41:02 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Spawn player
*/

int		get_spawn(t_info *info)
{
	int		x;
	int		y;

	x = 0;
	info->map.xspawn = 1.5;
	info->map.yspawn = 1.5;
	while (x < info->map.width)
	{
		y = 0;
		while (y < info->map.height)
		{
			if (info->map.map[x][y] == '2')
			{
				info->map.xspawn = x + 0.5;
				info->map.yspawn = y + 0.5;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
