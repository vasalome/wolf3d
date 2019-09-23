/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_teleport.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/19 14:37:15 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/23 19:13:40 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

void	teleport_2(t_info *info)
{
	int		x;
	int		y;
	int		tpx;

	printf("\033[0;36m-x_pos: %f\n", info->player.x_pos);
	printf("-y_pos: %f\n", info->player.y_pos);
	printf("-x_dir: %f\n", info->player.x_dir);
	printf("-y_dir: %f\n\n\033[0;0m", info->player.y_dir);

	info->player.x_pos -= info->player.x_dir * info->player.move_speed;
	tpx = (int)(info->player.x_pos + 1) * 100 + (int)info->player.y_pos;

	printf("\033[0;38m__x_pos: %f\n", info->player.x_pos);
	printf("__y_pos: %f\n", info->player.y_pos);
	printf("__x_dir: %f\n", info->player.x_dir);
	printf("__y_dir: %f\n\n\033[0;0m", info->player.y_dir);

	x = (int)((info->player.tp[tpx] / 100) - 10);
	y = (int)(info->player.tp[tpx] % 100);

	printf("\033[0;31mA\nx:%d\ny:%d\ntpx:%d\n\033[0;0m\n\n",x, y, tpx);
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

	printf("\033[0;36m1 -x_pos: %f\n", info->player.x_pos);
	printf("1 -y_pos: %f\n", info->player.y_pos);
	printf("1 -x_dir: %f\n", info->player.x_dir);
	printf("1 -y_dir: %f\n\n\033[0;0m", info->player.y_dir);

	info->player.x_pos += info->player.x_dir * info->player.move_speed;
	tpx = (int)(info->player.x_pos + 1) * 100 + (int)info->player.y_pos;

	printf("\033[0;38m1 __x_pos: %f\n", info->player.x_pos);
	printf("1 __y_pos: %f\n", info->player.y_pos);
	printf("1 __x_dir: %f\n", info->player.x_dir);
	printf("1 __y_dir: %f\n\n\033[0;0m", info->player.y_dir);
	
	x = (int)((info->player.tp[tpx] / 100) - 10);
	y = (int)(info->player.tp[tpx] % 100);
	printf("\033[0;31mA\n1 x:%d\n1 y:%d\n1 tpx:%d\n\033[0;0m\n\n",x, y, tpx);
	if (!(x > info->map.width || y > info->map.height || y < 0 || x < 0))
	{
		info->player.x_pos = x + (info->player.x_pos -\
			(int)info->player.x_pos);
		info->player.y_pos = y + (info->player.y_pos -\
			(int)info->player.y_pos);
	}
	printf("1 x_pos: %f\n", info->player.x_pos);
	printf("1 y_pos: %f\n", info->player.y_pos);
	printf("1 x_dir: %f\n", info->player.x_dir);
	printf("1 y_dir: %f\n\n", info->player.y_dir);
	printf("\033[0;31mB\n1 x:%d\n1 y:%d\n1 tpx:%d\n\033[0;0m\n_________________\n\n",x, y, tpx);
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
