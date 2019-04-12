/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 11:58:35 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:33:21 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') ||
			(s2[i] == '\0' && s1[i] != '\0'))
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
