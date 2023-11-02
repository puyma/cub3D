/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:25:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/02 03:04:04 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* WIP:
 * https://lodev.org/cgtutor/raycasting.html
 */


static void	ft_ver_line(t_game *game, int x, t_vector draw, int color)
{
	int	start;
	int	finish;

	start = draw.intx;
	finish = draw.inty;
	while (start <= finish)
	{
		ft_mlx_pixel_put(&game->i_main_frame, x, start, color);
		++start;
	}
}

static void	ft_recalculate_ray(t_ray *r, t_player *pl, int x)
{
	r->camera_x = 2 * x / (double) WIN_WIDTH - 1;
	r->dir.x = pl->dir.x + pl->plane.x * r->camera_x;
	r->dir.y = pl->dir.x + pl->plane.y + r->camera_x;
	r->map.intx = (int)(pl->pos.x);
	r->map.inty = (int)(pl->pos.y);
	if (r->dir.x == 0)
		r->delta_dist.x = 1e30;
	else
		r->delta_dist.x = fabs(1 / r->dir.x);
	if (r->dir.y == 0)
		r->delta_dist.y = 1e30;
	else
		r->delta_dist.y = fabs(1 / r->dir.x);
	r->hit = 0;
	if (r->dir.x < 0)
	{
		r->step.intx = -1;
		r->side_dist.x = (pl->pos.x - r->map.intx) * r->delta_dist.x;
	}
	else
	{
		r->step.intx = 1;
		r->side_dist.x = (r->map.intx + 1.0 - pl->pos.x) * r->delta_dist.y;
	}
	if (r->dir.y < 0)
	{
		r->step.inty = -1;
		r->side_dist.y = (pl->pos.y - r->map.inty) * r->delta_dist.y;
	}
	else
	{
		r->step.inty = 1;
		r->side_dist.y = (r->map.inty + 1.0 - pl->pos.y) * r->delta_dist.y;
	}
	return ;
}

static void	calculate_hit(t_ray *r, t_map *map)
{
	while (r->hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map.intx += r->step.intx;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map.inty += r->step.inty;
			r->side = 1;
		}
		if (map->board[r->map.inty][r->map.intx] != '0')
			r->hit = 1;
	}
	if (r->side == 0)
		r->perp_wall_dist = (r->side_dist.x - r->delta_dist.x);
	else
		r->perp_wall_dist = (r->side_dist.y - r->delta_dist.y);
	return ;
}

void	ft_raycast_loop(t_game *game, t_player *pl, t_ray *r, t_imgdata *img)
{
	int			x;
	t_vector	draw_start;
	t_color		color;
	int			line_height;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_recalculate_ray(r, pl, x);
		calculate_hit(r, game->map);
		line_height = (int)(WIN_HEIGHT / r->perp_wall_dist);
		draw_start.intx = -line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start.intx < 0)
			draw_start.intx = 0;
		draw_start.inty = line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start.inty >= WIN_HEIGHT)
			draw_start.inty = WIN_HEIGHT - 1;
		color.argb = 0x00FFFFFF;
		if (game->map->board[r->map.inty][r->map.intx] == '1')
			color.argb = 0x00000000;
		else if (game->map->board[r->map.inty][r->map.intx] == '2')
			color.argb = 0x000000FF;
		else if (game->map->board[r->map.inty][r->map.intx] == '3')
			color.argb = 0x00FF0000;
		else if (game->map->board[r->map.inty][r->map.intx] == '4')
			color.argb = 0x0000FF00;
		else if (game->map->board[r->map.inty][r->map.intx] == '5')
					color.argb = 0x00101010;
		if (r->side == 1)
			color.argb = color.argb / 2;
		ft_ver_line(game, x, draw_start, color.argb);
		++x;
	}
	(void) img;
}
