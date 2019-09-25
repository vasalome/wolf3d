/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 19:19:21 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/25 11:01:44 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

int		red_cross(void)
{
	exit(0);
	return (0);
}

int		f_exist(t_info *info)
{
	struct stat	buffer;

	if (stat(info->map.name, &buffer) == 0)
		return (S_ISREG(buffer.st_mode));
	else
		return (0);
}

int		ft_usage(char *error)
{
	write(1, "Error: ", 7);
	ft_putstr(error);
	write(1, "\n", 1);
	write(1, "\033[31mHow to use ?                   \n", 32);
	write(1, "\n", 1);
	write(1, "Exemple : ./wolf3d 'map'       \n", 32);
	write(1, "\n\n", 2);
	write(1, "Choose your map                \n", 32);
	write(1, ". 1 : maps/mindfuck.map        \n", 32);
	write(1, ". 2 : maps/big_cube.map        \n", 32);
	write(1, ". 3 : maps/lnieto_2.map        \n", 32);
	write(1, ". 4 : maps/prison_escape.map   \n", 32);
	write(1, ".etc\033[0m                           \n", 32);
	write(1, "\n", 1);
	exit(0);
	return (64);
}
