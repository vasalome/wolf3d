/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 19:19:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/24 19:19:42 by vasalome    ###    #+. /#+    ###.fr     */
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
	write(1, "\n", 1);
	write(1, "Choose your map           \n", 27);
	write(1, ". 1 : lnieto_1.map        \n", 27);
	write(1, ". 2 : lnieto_2.map        \n", 27);
	write(1, ". 3 : vasalome_1.map      \n", 27);
	write(1, ". 4 : vasalome_2.map      \n", 27);
	write(1, "or a map of your choice   \n", 27);
	write(1, "\n", 1);
	return (64);
}
