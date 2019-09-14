/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_wolf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/24 19:24:39 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
	{
		ft_usage();
		exit(0);
	}
	info.map.name = argv[1];
	init(&info);
	printf("AFTER INFO: WHY CRASH _____1\n");
	mlx_hook(info.window.win, 17, 0, red_cross, (void *)0);
	printf("AFTER INFO: WHY CRASH _____2\n");
	mlx_hook(info.window.win, 2, (1L << 0), key_press, &info);
	printf("AFTER INFO: WHY CRASH _____3\n");
	mlx_hook(info.window.win, 3, (1L << 1), key_release, &info);
	printf("AFTER INFO: WHY CRASH _____4\n");
	mlx_loop_hook(info.window.mlx, move, &info);
	printf("AFTER INFO: WHY CRASH _____5\n");
	mlx_loop(info.window.mlx);
	return (0);
}
