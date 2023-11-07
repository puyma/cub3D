/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:25:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/06 22:15:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* WIP:
 * https://lodev.org/cgtutor/raycasting.html */

static void		ft_init_ray(t_ray *r, t_player *pl);
static void		ft_recalculate_ray(t_ray *r, t_player *pl);
static void		calculate_hit(t_ray *r, t_map *map);
static void		ft_calculate_textures(t_ray *r, t_game *game, t_player *pl);

void	raycast_loop(t_game *game, t_player *pl, t_ray *r, t_imgdata *img)
{
	r->x = 0;
	while (r->x < WIN_WIDTH)
	{
		ft_init_ray(r, pl);
		ft_recalculate_ray(r, pl);
		calculate_hit(r, game->map);
		ft_calculate_textures(r, game, pl);
		++r->x;
	}
	ft_moves(game);
	(void) img;
}

static void	ft_init_ray(t_ray *r, t_player *pl)
{
	r->camera_x = 2 * r->x / (double) WIN_WIDTH - 1;
	r->dir.x = pl->dir.x + pl->plane.x * r->camera_x;
	r->dir.y = pl->dir.y + pl->plane.y * r->camera_x;
	r->map.intx = (int)(pl->pos.x);
	r->map.inty = (int)(pl->pos.y);
	r->delta_dist.x = fabs(1 / r->dir.x);
	r->delta_dist.y = fabs(1 / r->dir.y);
	r->hit = 0;
}

static void	ft_recalculate_ray(t_ray *r, t_player *pl)
{
	if (r->dir.x < 0)
	{
		r->step.intx = -1;
		r->side_dist.x = (pl->pos.x - r->map.intx) * r->delta_dist.x;
	}
	else
	{
		r->step.intx = 1;
		r->side_dist.x = (r->map.intx + 1.0 - pl->pos.x) * r->delta_dist.x;
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
		if (map->board[r->map.intx][r->map.inty] == '1')
			r->hit = 1;
	}
	if (r->side == 0)
		r->perp_wall_dist = (r->side_dist.x - r->delta_dist.x);
	else
		r->perp_wall_dist = (r->side_dist.y - r->delta_dist.y);
	return ;
}

static void	ft_calculate_textures(t_ray *r, t_game *game, t_player *pl)
{
	static int			start = 0;
	static int			finish = 0;
	static double		wall_x = 0;

	game->line_height = (int)(WIN_HEIGHT / r->perp_wall_dist);
	start = -game->line_height / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	finish = game->line_height / 2 + WIN_HEIGHT / 2;
	if (finish >= WIN_HEIGHT)
		finish = WIN_HEIGHT - 1;
	if (r->side == 0)
		wall_x = pl->pos.y + r->perp_wall_dist * r->dir.y;
	else
		wall_x = pl->pos.x + r->perp_wall_dist * r->dir.x;
	wall_x -= floor(wall_x);
	ft_draw_textures(r, start, finish, game, wall_x);
}