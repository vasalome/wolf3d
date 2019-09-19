/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_wolf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/08 17:53:57 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 19:11:52 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

int		check_map(t_info *info)
{
	if (!(ft_strcmp(info->map.name, "maps/mindfuck.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/big_cube.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/lnieto_1.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/lnieto_2.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/vasalome_1.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/vasalome_2.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/test_texture.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/test_tp.map")))
		return (0);
	return (64);
}

int		main(int argc, char **argv)
{
	t_info	info;
	void	*mlx;

	if (argc != 2)
	{
		ft_usage();
		exit(0);
	}
	info.map.name = argv[1];
	if (check_map(&info) == 64)
	{
		ft_usage();
		exit(0);
	}
	init(&info);
	mlx_hook(info.win.win, 17, 0, red_cross, (void *)0);
	mlx_hook(info.win.win, 2, (1L << 0), key_press, &info);
	mlx_hook(info.win.win, 3, (1L << 1), key_release, &info);
	mlx_loop_hook(info.win.mlx, move, &info);
	mlx = info.win.mlx;
	mlx_loop(mlx);
	return (0);
}
