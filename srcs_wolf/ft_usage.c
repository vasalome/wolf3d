/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 19:19:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 16:44:05 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

int		red_cross(void)
{
	exit(0);
	return (0);
}

int		ft_usage(void)
{
	write(1, "\n", 1);
	write(1, "How to use ?              \n", 27);
	write(1, "\n", 1);
	write(1, "Exemple : ./wolf3d 'map'  \n", 27);
	write(1, "\n\n", 2);
	write(1, "Choose your map           \n", 27);
	write(1, ". 1 : maps/mindfuck.map   \n", 27);
	write(1, ". 2 : maps/big_cube.map   \n", 27);
	write(1, ". 3 : maps/lnieto_2.map   \n", 27);
	write(1, ". 4 : maps/vasalome_2.map \n", 27);
	write(1, ".etc                      \n", 27);
	write(1, "\n", 1);
	return (64);
}
