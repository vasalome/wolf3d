/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 19:19:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/20 15:38:06 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

int		red_cross(void)
{
	exit(0);
	return (0);
}

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
	if (!(ft_strcmp(info->map.name, "maps/prison_escape.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/test_texture.map")))
		return (0);
	if (!(ft_strcmp(info->map.name, "maps/test_tp.map")))
		return (0);
	return (64);
}

int		ft_usage(void)
{
	write(1, "\n", 1);
	write(1, "How to use ?                   \n", 32);
	write(1, "\n", 1);
	write(1, "Exemple : ./wolf3d 'map'       \n", 32);
	write(1, "\n\n", 2);
	write(1, "Choose your map                \n", 32);
	write(1, ". 1 : maps/mindfuck.map        \n", 32);
	write(1, ". 2 : maps/big_cube.map        \n", 32);
	write(1, ". 3 : maps/lnieto_2.map        \n", 32);
	write(1, ". 4 : maps/prison_escape.map   \n", 32);
	write(1, ".etc                           \n", 32);
	write(1, "\n", 1);
	return (64);
}
