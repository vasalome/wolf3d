/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wall.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 15:37:11 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/13 16:27:37 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_wolf/wolf.h"

/*
** draw image with vertical lines
*/

void	create_img(t_info *info)
{
	//printf("create_img IN\n");
	info->fps.img = mlx_new_image(info->window.mlx, WIDTH, HEIGHT);
	info->fps.data = mlx_get_data_addr(info->fps.img, &info->fps.bpp,\
		&info->fps.sizeline, &info->fps.endian);
	//printf("create_img OUT\n");
}

void	draw_wall(int x, int draw_start, int draw_end, t_info *info)
{
	//printf("draw_wall IN\n");
	int		y;
	int 	d;
	int		texY;

	y = -1;
	while (++y <= draw_start)
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)255;	
	while (++draw_start <= draw_end)
	{
		/*info->fps.data[x * 4 + 4 * WIDTH * draw_start] = (char)info->wall.b;
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 1] = (char)info->wall.g;
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 2] = (char)info->wall.r;
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 3] = (char)0;*/
		d = draw_start * 256 - info->window.h * 128 + info->wall.line_height * 128;
		texY = ((d * info->wt[info->w_j].yhud) / info->wall.line_height) / 256;
		
		info->fps.data[x * 4 + 4 * WIDTH * draw_start] = (char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 * info->wt[info->w_j].xhud * texY] ;
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 1] = (char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 * info->wt[info->w_j].xhud * texY + 1];
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 2] = (char)info->wt[info->w_j].data[info->wt[info->w_j].tex_x * 4 + 4 * info->wt[info->w_j].xhud * texY + 2];
		info->fps.data[x * 4 + 4 * WIDTH * draw_start + 3] = (char)0;
	}
	y = draw_start - 5;

	while (++y < info->window.h)
	{
		info->fps.data[x * 4 + 4 * WIDTH * y] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 1] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 2] = (char)120;
		info->fps.data[x * 4 + 4 * WIDTH * y + 3] = (char)0;
	}
	//printf("draw_wall OUT\n");
}

/*
** Initiate variables to default values for wall detection
*/

void	wall_detection_init_y(t_info *info)
{
	//printf("__wall_detection_init_y IN\n");
	info->ray.y_delta_distance = sqrt(1 + (info->ray.x_ray_direction *\
		info->ray.x_ray_direction) / (info->ray.y_ray_direction *\
		info->ray.y_ray_direction));
	if (info->ray.y_ray_direction < 0)
	{
		info->map.y_step = -1;
		info->ray.y_side_distance = (info->ray.y_ray_position -\
			info->map.y) * info->ray.y_delta_distance;
	}
	else
	{
		info->map.y_step = 1;
		info->ray.y_side_distance = (info->map.y + 1.0 -\
			info->ray.y_ray_position) * info->ray.y_delta_distance;
	}
	//printf("__wall_detection_init_y OUT\n");
}

void	wall_detection_init_x(t_info *info)
{
	//printf("__wall_detection_init_x IN\n");
	info->ray.x_delta_distance = sqrt(1 + (info->ray.y_ray_direction *\
		info->ray.y_ray_direction) / (info->ray.x_ray_direction *\
		info->ray.x_ray_direction));
	if (info->ray.x_ray_direction < 0)
	{
		info->map.x_step = -1;
		info->ray.x_side_distance = (info->ray.x_ray_position -\
			info->map.x) * info->ray.x_delta_distance;
	}
	else
	{
		info->map.x_step = 1;
		info->ray.x_side_distance = (info->map.x + 1.0 -\
			info->ray.x_ray_position) * info->ray.x_delta_distance;
	}
	//printf("__wall_detection_init_x OUT\n");
	wall_detection_init_y(info);
}

/*
** Test if ray hit a wall
*/

void	wall_detection(t_info *info)
{
	//printf("\n__wall_detection IN\n\n");
	info->map.hit = 0;
	while (info->map.hit == 0)
	{
		//write(1, "WD-> 1\n", 7);
		if (info->ray.x_side_distance < info->ray.y_side_distance)
		{
			//write(1, "WD-> 2\n", 7);
			info->ray.x_side_distance += info->ray.x_delta_distance;
			info->map.x += info->map.x_step;
			info->wall.side = 0;
		}
		else
		{
			//write(1, "WD-> 3\n", 7);
			info->ray.y_side_distance += info->ray.y_delta_distance;
			info->map.y += info->map.y_step;
			info->wall.side = 1;
		}
		if (info->map.map[info->map.x][info->map.y] == '1' ||\
			info->map.map[info->map.x][info->map.y] == '5' ||\
			info->map.map[info->map.x][info->map.y] == '6')
		{
			//write(1, "WD-> 4\n", 7);
			info->map.hit = 1;
		}
		if (info->map.map[info->map.x][info->map.y] == '5')
		{
			info->wall.trap = 1;
			//write(1, "WD-> 5\n", 7);
		}
		else if (info->map.map[info->map.x][info->map.y] == '6')
		{
			info->wall.trap = 2;
			//write(1, "WD-> 6\n", 7);
		}
		else
		{
			info->wall.trap = 0;
			//write(1, "WD-> 7\n", 7);
		}
	}
	//printf("\n__wall_detection OUT\n\n");
}
