/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/09 09:02:36 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:05:03 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_atoi(const char *s1)
{
	int s;
	int x;
	int r;
	int n;

	n = 1;
	s = 0;
	r = 0;
	x = 0;
	while (s1[s] == '\t' || s1[s] == '\n' || s1[s] == '\r' ||
			s1[s] == '\v' || s1[s] == '\f' || s1[s] == ' ')
		s++;
	x = s;
	while (s1[x] != '\0' && ((s1[x] >= '0' && s1[x] <= '9') ||
				(s1[s] == '-' && x == s) || (s1[s] == '+' && x == s)))
	{
		if (s1[s] == '-')
			n = -1;
		if (s1[x] >= '0' && s1[x] <= '9')
			r = (r * 10) + (s1[x] - 48);
		x++;
	}
	return (r * n);
}