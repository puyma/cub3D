/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:25:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 04:03:12 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* WIP:
 * https://lodev.org/cgtutor/raycasting.html
 */

static void	ft_init_player(t_player *player)
{
	player->plane.x = 0;
	player->plane.y = 0.66;
}

static void	ft_verLine(t_game *game, int x, t_vector draw, int color)
{
	int	start;
	int	finish;

	start = draw.x;
	finish = draw.y;
	while (start <= finish)
	{
		ft_mlx_pixel_put(&game->i_main_frame, x, start, color);
		++start;
	}
}

void	ft_raycast_loop(t_game *game, t_player *pl, t_ray *r, t_imgdata *img)
{
	int			x;
	t_vector	draw_start;
	t_color		color;
	int			line_height;

	x = 0;
	ft_init_player(pl);
	while (x < WIN_WIDTH)
	{
		r->camera_x = 2 * x / (double) WIN_WIDTH - 1;
		r->dir.x = pl->dir.x + pl->plane.x * r->camera_x;
		r->dir.y = pl->dir.x + pl->plane.y + r->camera_x;
		r->map.intx = (int)pl->pos.x;
		r->map.inty = (int)pl->pos.y;
		if (r->dir.x == 0)
			r->delta_dist.x = 0.1;
		else
			r->delta_dist.x = sqrt(1 + pow(r->dir.y, 2) / pow(r->dir.x, 2));
		if (r->dir.y == 0)
			r->delta_dist.y = 0.1;
		else
			r->delta_dist.y = sqrt(1 + pow(r->dir.x, 2) / pow(r->dir.y, 2));
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
			if (game->map->board[r->map.intx][r->map.inty] > 0)
				r->hit = 1;
		}
		if (r->side == 0)
			r->perp_wall_dist = (r->side_dist.x - r->delta_dist.x);
		else
			r->perp_wall_dist = (r->side_dist.y - r->delta_dist.y);
		line_height = (int)(WIN_HEIGHT / r->perp_wall_dist);
		draw_start.intx = -line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start.intx < 0)
			draw_start.intx = 0;
		draw_start.inty = line_height / 2 + WIN_HEIGHT / 2;
		if (draw_start.inty >= WIN_HEIGHT)
			draw_start.inty = WIN_HEIGHT - 1;
		color.argb = 0x00171717;
		if (game->map->board[r->map.intx][r->map.inty] == '1')
			color.argb = 0x00387959;
		else if (game->map->board[r->map.intx][r->map.inty] == '2')
			color.argb = 0x000000FF;
		else if (game->map->board[r->map.intx][r->map.inty] == '3')
			color.argb = 0x00FFFF00;
		else if (game->map->board[r->map.intx][r->map.inty] == '4')
			color.argb = 0x00AA8895;
		else if (game->map->board[r->map.intx][r->map.inty] == '5')
					color.argb = 0x00FF7F00;
		if (r->side == 1)
			color.argb = color.argb / 2;
		ft_verLine(game, x, draw_start, ft_get_color(&game->color));
		++x;
	}
	(void) img;
}
