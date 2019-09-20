/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_teleport.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:37:15 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/20 15:37:57 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

void	teleport_2(t_info *info)
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
	printf("x_pos: %f\n", info->player.x_pos);
	printf("y_pos: %f\n", info->player.y_pos);
	printf("x_dir: %f\n", info->player.x_dir);
	printf("y_dir: %f\n\n", info->player.y_dir);
	printf("\033[0;31mx:%d\ny:%d\ntpx:%d\n\033[0;0m\n_________________\n\n",x, y, tpx);
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
	printf("x_pos: %f\n", info->player.x_pos);
	printf("y_pos: %f\n", info->player.y_pos);
	printf("x_dir: %f\n", info->player.x_dir);
	printf("y_dir: %f\n\n", info->player.y_dir);
	printf("\033[0;31mx:%d\ny:%d\ntpx:%d\n\033[0;0m\n_________________\n\n",x, y, tpx);
}

/*
void	teleport_2(t_info *info)
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
*/
