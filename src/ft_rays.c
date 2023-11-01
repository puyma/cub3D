/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:25:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 01:52:08 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* WIP:
 * https://lodev.org/cgtutor/raycasting.html
 */

static void	ft_init_ray(t_game *game)
{
	game->player.position.x = 2;
	game->player.position.y = 2;
	game->player.direction.x = 1;
	game->player.direction.y = 0;
	game->player.plane.x = 0.66;
	game->player.plane.y = -0.66;
}

void	ft_verLine(t_game *game, int x, int drawStart, int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y <= drawEnd)
	{
		ft_mlx_pixel_put(&game->i_main_frame, x, y, color);
		++y;
	}
}

void	ft_raycast_loop(t_game *game, t_imgdata *img)
{
	int x;

	x = 0;
	ft_init_ray(game);
	while (x < WIN_WIDTH)
	{
		game->ray.camera_x = 2 * x / (double) WIN_WIDTH - 1;
		game->ray.dir.x = game->player.direction.x + game->player.plane.x * game->ray.camera_x;
		game->ray.dir.y = game->player.direction.x + game->player.plane.y + game->ray.camera_x;

		game->ray.map.intx = (int)game->player.position.x;
		game->ray.map.inty = (int)game->player.position.y;

		game->ray.delta_dist.x = (game->ray.dir.x == 0) ? 0.1 : abs((int) (1 / game->ray.dir.x));
		game->ray.delta_dist.y = (game->ray.dir.y == 0) ? 0.1 : abs((int) (1 / game->ray.dir.y));

		int	hit = 0;
		int	side;

		if (game->ray.dir.x < 0)
		{
			game->ray.step.intx = -1;
			game->ray.side_dist.x = (game->player.position.x - game->ray.map.intx) * game->ray.delta_dist.x;
		}
		else
		{
			game->ray.step.intx = 1;
			game->ray.side_dist.x = (game->ray.map.intx + 1.0 - game->player.position.x) *game->ray.delta_dist.y;
		}
		if (game->ray.dir.y < 0)
		{
			game->ray.step.inty = -1;
			game->ray.side_dist.y = (game->player.position.y - game->ray.map.inty) * game->ray.delta_dist.y;
		}
		else
		{
			game->ray.step.inty = 1;
			game->ray.side_dist.y = (game->ray.map.inty + 1.0 - game->player.position.y) * game->ray.delta_dist.y;
		}

		// DDA
		while (hit == 0)
		{
			if (game->ray.side_dist.x < game->ray.side_dist.y)
			{
				game->ray.side_dist.x += game->ray.delta_dist.x;
				game->ray.map.intx += game->ray.step.intx;
				side = 0;
			}
			else
			{
				game->ray.side_dist.y += game->ray.delta_dist.y;
				game->ray.map.inty += game->ray.step.inty;
				side = 1;
			}
			if (game->map->board[game->ray.map.intx][game->ray.map.inty] != '0')
				hit = 1;
		}

		if (side == 0)
			game->ray.perp_wall_dist = (game->ray.side_dist.x - game->ray.delta_dist.x);
		else
			game->ray.perp_wall_dist = (game->ray.side_dist.y - game->ray.delta_dist.y);

		int	lineHeight = (int) (WIN_HEIGHT / game->ray.perp_wall_dist);

		int	drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;

		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		t_color color;
		color.argb = 0x00171717;
		if (game->map->board[game->ray.map.intx][game->ray.map.inty] == '1')
			color.argb = 0x00387959;
		else if (game->map->board[game->ray.map.intx][game->ray.map.inty] == '2')
			color.argb = 0x000000FF;
		else if (game->map->board[game->ray.map.intx][game->ray.map.inty] == '3')
			color.argb = 0x00FFFF00;
		else if (game->map->board[game->ray.map.intx][game->ray.map.inty] == '4')
			color.argb = 0x00AA8895;
		else if (game->map->board[game->ray.map.intx][game->ray.map.inty] == '5')
			color.argb = 0x00FF7F00;

		if (side == 1) {color.argb = color.argb / 2;}

		ft_verLine(game, x, drawStart, drawEnd, color.argb);
		++x;
	}

	// time FPS stuff

	(void) img;
}
