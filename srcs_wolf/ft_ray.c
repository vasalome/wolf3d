/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ray.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:35:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 16:27:35 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** Initiate variables at default values for raycasting
*/

void	ray_casting_init(t_info *info, int x)
{
	//printf("\nray_casting_init IN\n\n");
	info->player.x_camera = 2 * x / (double)(info->window.w) - 1;
	info->ray.x_ray_position = info->player.x_pos;
	info->ray.y_ray_position = info->player.y_pos;
	info->ray.x_ray_direction = info->player.x_dir + info->player.x_plane *
		info->player.x_camera;
	info->ray.y_ray_direction = info->player.y_dir + info->player.y_plane *
		info->player.x_camera;
	info->map.x = (int)info->ray.x_ray_position;
	info->map.y = (int)info->ray.y_ray_position;
	wall_detection_init_x(info);
	wall_detection(info);
	if (info->wall.side == 0)
		info->wall.wall_distance = (info->map.x - info->ray.x_ray_position +
				(1 - info->map.x_step) / 2) / info->ray.x_ray_direction;
	else
		info->wall.wall_distance = (info->map.y - info->ray.y_ray_position +
				(1 - info->map.y_step) / 2) / info->ray.y_ray_direction;
	//printf("\nray_casting_init OUT\n\n");
}

/*
** Main raycasting function
*/

int		ray_casting(t_info *info)
{
	////////printf("ray_casting IN\n");
	info->wall.x = -1;
	while (++info->wall.x < info->window.w)
	{
		ray_casting_init(info, info->wall.x);
		info->wall.line_height = (int)(info->window.h / info->wall.wall_distance);
		info->wall.draw_start = -info->wall.line_height / 2 + info->window.h / 2;
		if (info->wall.draw_start < 0)
			info->wall.draw_start = 0;
		info->wall.draw_end = info->wall.line_height / 2 + info->window.h / 2;
		if (info->wall.draw_end >= info->window.h)
			info->wall.draw_end = info->window.h - 1;
		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
		{
			info->w_j = 0;
		}
		else if (info->wall.side == 0 && info->ray.x_ray_direction < 0)
		{
			info->w_j = 1;
		}
		else if (info->wall.side == 1 && info->ray.y_ray_direction > 0)
		{
			info->w_j = 2;
		}
		else
		{
			info->w_j = 3;
		}
		if (info->wall.trap == 1)
		{
			info->w_j = 4;
			/*if (info->wall.side == 1)
			{
				
				info->wall.color = 0xDB2222;
				info->wall.r = 219;
				info->wall.g = 34;
				info->wall.b = 34;
				info->wall.a = 255;
			}
			else
			{
				info->wall.color = 0xB61A1A;
				info->wall.r = 182;
				info->wall.g = 26;
				info->wall.b = 26;
				info->wall.a = 255;
			}*/
		}
		if (info->wall.trap == 2)
		{
			info->w_j = 4;
			/*if (info->wall.side == 1)
			{
				info->wall.color = 0xB66530;
				info->wall.r = 182;
				info->wall.g = 101;
				info->wall.b = 48;
				info->wall.a = 255;
			}
			else
			{
				info->wall.color = 0x8D4D22;
				info->wall.r = 141;
				info->wall.g = 77;
				info->wall.b = 34;
				info->wall.a = 255;
			}*/
		}

		//Wall textures
		if (info->wall.side == 0)
			info->wall.ux = info->player.y_pos + info->wall.wall_distance * info->ray.y_ray_direction;
		else
			info->wall.ux = info->player.x_pos + info->wall.wall_distance * info->ray.x_ray_direction;
		info->wall.ux -= floor((info->wall.ux));
		info->wt[info->w_j].tex_x = (int)(info->wall.ux * (double)info->wt[info->w_j].xhud);

		if (info->wall.side == 0 && info->ray.x_ray_direction > 0)
			info->wt[info->w_j].tex_x = info->wt[info->w_j].xhud - info->wt[info->w_j].tex_x - 1;
		if (info->wall.side == 1 && info->ray.y_ray_direction < 0)
			info->wt[info->w_j].tex_x = info->wt[info->w_j].xhud - info->wt[info->w_j].tex_x - 1;

		//printf("%f\n",info->wall.x);

		draw_wall(info->wall.x, info->wall.draw_start - 1,
				info->wall.draw_end, info);
	}
	/////////printf("ray_casting OUT\n");
	return (0);
}

void	skybox(t_info *info)
{
	//printf("skybox IN\n");
	int		offset;
	offset = WIDTH;
	if (info->player.y_dir > 0)
		offset = -offset;
	info->tex.img = mlx_xpm_file_to_image(info->window.mlx, "sky.xpm",\
		&info->tex.xhud, &info->tex.yhud);
	mlx_put_image_to_window(info->window.mlx, info->window.win,\
		info->tex.img, offset * info->player.x_dir, -150);
	mlx_put_image_to_window(info->window.mlx, info->window.win,\
		info->tex.img, offset * info->player.x_dir - info->tex.xhud, -150);
	mlx_put_image_to_window(info->window.mlx, info->window.win,\
		info->tex.img, offset * info->player.x_dir + info->tex.xhud, -150);
	mlx_put_image_to_window(info->window.mlx, info->window.win,\
		info->tex.img, offset * info->player.x_dir + (info->tex.xhud * 2) , -150);
	mlx_put_image_to_window(info->window.mlx, info->window.win,\
		info->tex.img, offset * info->player.x_dir - (info->tex.xhud * 2) , -150);
	//printf("skybox OUT\n");
}

void	game_over(t_info *info)
{
	//printf("game_over IN\n");
	void	*img;
	int		w;
	int		h;
	img = mlx_xpm_file_to_image(info->window.mlx, "gameoverscreen.xpm", &w, &h);
	mlx_put_image_to_window(info->window.mlx, info->window.win,
			img, 0, 0);
	//printf("game_over OUT\n");
}

/*
** put resulting image of raycasting on screen
*/

void	ray_casting_image(t_info *info)
{
	
	//printf("ray_casting_image IN\n");
	if (!(info->player.life - 1 <= 0))
	{
		skybox(info);
		create_img(info);
		ray_casting(info);
		mlx_put_image_to_window(info->window.mlx, info->window.win,
			info->fps.img, 0, 0);
		if (info->map.map[(int)info->player.x_pos][(int)info->player.y_pos] == '4')
			mlx_string_put(info->window.mlx, info->window.win, info->window.w / 2,
				info->window.h / 2, 255, "GG BRO!");
		if (info->map.map[(int)info->player.x_pos][(int)info->player.y_pos] == '5')
		{
			if (info->player.canTrap)
			{
				info->player.canTrap = 0;
				info->player.life -= 1;
			}
			mlx_string_put(info->window.mlx, info->window.win, info->window.w / 2,
				info->window.h / 2, 255, "-1 life");
			//printf("ray_casting_image OUT1\n");
		}
		else
			info->player.canTrap = 1;
		mlx_put_image_to_window(info->window.mlx, info->window.win,\
			info->head[info->player.life - 1].img, 0, 0);
		mlx_put_image_to_window(info->window.mlx, info->window.win,\
			info->weapon[info->w_i].img, info->window.w / 2 - 4 + (rand() % 8),\
			info->window.h - info->weapon[info->w_i].yhud);
		mlx_destroy_image(info->window.mlx, info->fps.img);
		//printf("ray_casting_image OUT2\n");
	}
	else {
		//printf("ray_casting_image OUT3\n");
		game_over(info);
	}
}
