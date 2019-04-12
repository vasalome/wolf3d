/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 11:13:39 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		y;
	int		x;
	int		color;

	x = 0;
	y = 0;
	ft_putstr("ok");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF test");
	while (y <= 15)
	{
		x = 0;
		while (x < 15)
			mlx_pixel_put(mlx_ptr, win_ptr, x++, y, 0xcd);
		y++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
