/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_textures.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/19 14:55:54 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

void	game_over(t_info *info)
{
	void	*img;
	int		w;
	int		h;
	int		x;
	int		y;

	y = 0;
	img = mlx_xpm_file_to_image(info->win.mlx, "game_over_p.xpm", &w, &h);
	while (y < info->win.h)
	{
		x = 0;
		while (x < info->win.w)
		{
			info->fps.data[x * 4 + 4 * WIDTH * y] = (char)27;
			info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)27;
			info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)205;
			info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->win.mlx, info->win.win, info->fps.img, 0, 0);
	mlx_put_image_to_window(info->win.mlx, info->win.win,
			img, info->win.w / 2 - w / 2, info->win.h / 2 - h / 2);
}

void	skybox(t_info *info)
{
	int		offset;

	offset = WIDTH;
	if (info->player.y_dir > 0)
		offset = -offset;
	info->tex.img = mlx_xpm_file_to_image(info->win.mlx, "sky.xpm",\
		&info->tex.xhud, &info->tex.yhud);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir, -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir - info->tex.xhud, -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir + info->tex.xhud, -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir + \
		(info->tex.xhud * 2), -150);
	mlx_put_image_to_window(info->win.mlx, info->win.win,\
		info->tex.img, offset * info->player.x_dir - \
		(info->tex.xhud * 2), -150);
}

void	choose_texture_2(t_info *info)
{
	if (info->wall.trap == 4)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 12;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 13;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 14;
		else
			info->w_j = 15;
	}
	if (info->wall.trap == 3)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 0;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 1;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 2;
		else
			info->w_j = 3;
	}
}

void	choose_texture_1(t_info *info)
{
	if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		info->w_j = 8;
	else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
		info->w_j = 9;
	else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
		info->w_j = 10;
	else
		info->w_j = 11;
	if (info->wall.trap == 1 || info->wall.trap == 2)
	{
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->w_j = 4;
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
			info->w_j = 5;
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
			info->w_j = 6;
		else
			info->w_j = 7;
	}
	else
		choose_texture_2(info);
}

void	texture_calc(t_info *info)
{
	if (info->wall.side == 0)
		info->wall.ux = info->player.y_pos + \
		info->wall.wall_distance * info->ray.y_ray_direction;
	else
		info->wall.ux = info->player.x_pos + \
		info->wall.wall_distance * info->ray.x_ray_direction;
	info->wall.ux -= floor((info->wall.ux));
	info->wt[info->w_j].tex_x = (int)(info->wall.ux * \
	(double)info->wt[info->w_j].xhud);
	if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].xhud - \
		info->wt[info->w_j].tex_x - 1;
	if (info->wall.side == 1 && info->ray.y_ray_direction < 0)
		info->wt[info->w_j].tex_x = info->wt[info->w_j].xhud - \
		info->wt[info->w_j].tex_x - 1;
}
