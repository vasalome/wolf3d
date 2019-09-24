/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_wolf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/24 18:42:47 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

int		main(int argc, char **argv)
{
	t_info	info;
	void	*mlx;

	if (argc != 2)
		ft_usage();
	info.map.name = argv[1];
	if (f_exist(&info) == 0)
		ft_usage();
	init(&info);
	mlx_hook(info.win.win, 17, 0, red_cross, (void *)0);
	mlx_hook(info.win.win, 2, (1L << 0), key_press, &info);
	mlx_hook(info.win.win, 3, (1L << 1), key_release, &info);
	mlx_loop_hook(info.win.mlx, move, &info);
	mlx = info.win.mlx;
	mlx_loop(mlx);
	return (0);
}
