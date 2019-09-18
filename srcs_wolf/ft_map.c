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
	//printf("set_map_size IN");
	t_setmap	set;
	int			ret;

	set.line = NULL;
	set.h = 0;
	set.w = 0;
	if (!(set.fd = open(info->map.name, O_RDONLY)))
		return (-1);
	while ((ret = ft_get_next_line(set.fd, &set.line)))
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
	if (ret == -1)
		return (-1);
	info->map.height = set.h;
	info->map.width = set.w;
	//printf("set_map_size OUT\n");
	return (0);
}

int		create_map(t_info *info)
{
	//printf("create_map IN\n");
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
	//printf("create_map OUT\n");
	return (0);
}

void	tp_destination(t_fillmap *fill, t_info *info, char *str, int *i)
{
	//printf("tp_destination IN\n");
	int		x;
	int		ten;

	ten = 1;
	*i += 1;
	x = fill->x * 100 + fill->y;
	info->player.tp[x] = 10;
	while (str[*i] != ',')
	{
		info->player.tp[x] += str[*i] - 48;
		*i += 1;
	}
	fill->j += 1;
	*i += 1;
	info->player.tp[x] *= 10;
	while (str[*i] != ' ')
	{
		info->player.tp[x] += str[*i] - 48;
		if (ten)
		{
			info->player.tp[x] *= 10;
			ten = 0;
		}
		*i += 1;
	}
	fill->j += 1;
	//printf("tp_destination OUT\n");
}

void	fill_map_plus(t_fillmap *fill, t_info *info)
{
	//printf("fill_map_plus IN\n");
	if (fill->line[fill->i] == '0' || fill->line[fill->i] == '1'
	|| fill->line[fill->i] == '2' || fill->line[fill->i] == '3'
	|| fill->line[fill->i] == '4' || fill->line[fill->i] == '5'
	|| fill->line[fill->i] == '6')
		info->map.map[fill->x++][fill->y] = fill->line[fill->i];
	if (fill->line[fill->i] == '3')
		tp_destination(fill, info, fill->line, &fill->i);
	//printf("fill_map_plus OUT\n");
}

int	fill_map(t_info *info)
{
	//printf("fill_map IN\n");
	t_fillmap	fill;
	int			ret;

	fill.i = 0;
	fill.x = 0;
	fill.y = 0;
	fill.j = 0;
	fill.line = NULL;
	if (!(fill.fd = open(info->map.name, O_RDONLY)))
		return (-1);
	while ((ret = ft_get_next_line(fill.fd, &fill.line)))
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
	if (ret == -1)
		return (-1);
	return (0);
	//printf("fill_map OUT\n");
}
