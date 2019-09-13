/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:40:07 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 16:27:32 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Do the map !
*/

int		set_map_size(t_info *info)
{
	t_setmap	set;

	set.line = NULL;
	set.h = 0;
	set.w = 0;
	set.fd = open(info->map.name, O_RDONLY);
	while (ft_get_next_line(set.fd, &set.line))
	{
		set.tmp = ft_countchar(set.line, '1');
		set.tmp += ft_countchar(set.line, '0');
		set.tmp += ft_countchar(set.line, '2');
		set.tmp += ft_countchar(set.line, '3');
		set.tp = ft_countchar(set.line, '3');
		if (set.tmp > set.w)
			set.w = set.tmp;
		ft_strdel(&set.line);
		set.h++;
	}
	if (!(set.tlp = malloc(sizeof(int *) * set.tp * 2 + 2)))
		return (-1);
	info->player.tp = set.tlp;
	info->map.height = set.h;
	info->map.width = set.w;
	return (0);
}

int		create_map(t_info *info)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = malloc(sizeof(char *) * info->map.width + 1)))
		return (-1);
	while (i < info->map.width)
	{
		if (!(map[i++] = malloc(sizeof(char) * info->map.height + 1)))
			return (-1);
	}
	info->map.map = map;
	return (0);
}

void	tp_destination(int *x, t_info *info, char *str, int *i)
{
	*i += 1;
	info->player.tp[*x] = 0;
	while (str[*i] != ',')
	{
		info->player.tp[*x] *= 10;
		info->player.tp[*x] += str[*i] - 48;
		*i += 1;
	}
	*x += 1;
	*i += 1;
	info->player.tp[*x] = 0;
	while (str[*i] != ' ')
	{
		info->player.tp[*x] *= 10;
		info->player.tp[*x] += str[*i] - 48;
		*i += 1;
	}
	*x += 1;
}

void	fill_map_plus(t_fillmap *fill, t_info *info)
{
	if (fill->line[fill->i] == '0' || fill->line[fill->i] == '1'
	|| fill->line[fill->i] == '2' || fill->line[fill->i] == '3'
	|| fill->line[fill->i] == '4' || fill->line[fill->i] == '5'
	|| fill->line[fill->i] == '6')
		info->map.map[fill->x++][fill->y] = fill->line[fill->i];
	if (fill->line[fill->i] == '3')
		tp_destination(&fill->j, info, fill->line, &fill->i);
}

void	fill_map(t_info *info)
{
	t_fillmap	fill;

	fill.i = 0;
	fill.x = 0;
	fill.y = 0;
	fill.j = 0;
	fill.line = NULL;
	fill.fd = open(info->map.name, O_RDONLY);
	while (ft_get_next_line(fill.fd, &fill.line))
	{
		fill.i = 0;
		while (fill.line[fill.i] != '\0')
		{
			fill_map_plus(&fill, info);
			fill.i++;
		}
		ft_strdel(&fill.line);
		fill.y++;
		fill.x = 0;
	}
}
