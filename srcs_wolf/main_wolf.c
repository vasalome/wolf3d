/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_wolf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 15:43:18 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

int		main(int ac, char **av)
{
	t_info	info;

	info.map.name = av[1];
	init(&info);
	mlx_hook(info.window.win, 2, (1L << 0), key_press, &info);
	mlx_hook(info.window.win, 3, (1L << 1), key_release, &info);
	mlx_loop_hook(info.window.mlx, move, &info);
	mlx_loop(info.window.mlx);
	return (0);
}
