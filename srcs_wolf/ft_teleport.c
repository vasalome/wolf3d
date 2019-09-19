/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_teleport.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:37:15 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:40:01 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

void	teleport2(t_info *info)
{
	int		x;
	int		y;
	int		tpx;

	info->player.x_pos -= info->player.x_dir * info->player.move_speed;
	tpx = (int)(info->player.x_pos + 1) * 100 + (int)info->player.y_pos;
	x = (int)((info->player.tp[tpx] / 100) - 10);
	y = (int)(info->player.tp[tpx] % 100);
	if (!(x > info->map.width || y > info->map.height || y < 0 || x < 0))
	{
		info->player.x_pos = x + (info->player.x_pos -\
			(int)info->player.x_pos);
		info->player.y_pos = y + (info->player.y_pos -\
			(int)info->player.y_pos);
	}
}

void	teleport(t_info *info)
{
	int		x;
	int		y;
	int		tpx;

	info->player.x_pos += info->player.x_dir * info->player.move_speed;
	tpx = (int)(info->player.x_pos + 1) * 100 + (int)info->player.y_pos;
	x = (int)((info->player.tp[tpx] / 100) - 10);
	y = (int)(info->player.tp[tpx] % 100);
	if (!(x > info->map.width || y > info->map.height || y < 0 || x < 0))
	{
		info->player.x_pos = x + (info->player.x_pos -\
			(int)info->player.x_pos);
		info->player.y_pos = y + (info->player.y_pos -\
			(int)info->player.y_pos);
	}
}
