/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/06 21:03:15 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_keydown(int k, t_game *game)
{
	if (k == KEY_ESC)
		return (ft_destroy(game), EXIT_SUCCESS);
	if (k == KEY_W || k == KEY_UP)
		game->key.up_w = 1;
	if (k == KEY_S || k == KEY_DOWN)
		game->key.down_s = 1;
	if (k == KEY_A || k == KEY_LEFT)
		game->key.left_a = 1;
	if (k == KEY_D || k == KEY_RIGHT)
		game->key.right_d = 1;
	if (k == KEY_SHIFT)
		game->key.sprint = 1;
	return (EXIT_SUCCESS);
}


int	ft_keyup(int k, t_game *game)
{
	if (k == KEY_W || k == KEY_UP)
		game->key.up_w = 0;
	if (k == KEY_S || k == KEY_DOWN)
		game->key.down_s = 0;
	if (k == KEY_A || k == KEY_LEFT)
		game->key.left_a = 0;
	if (k == KEY_D || k == KEY_RIGHT)
		game->key.right_d = 0;
	if (k == KEY_SHIFT)
		game->key.sprint = 0;
	return (EXIT_SUCCESS);
}
void	ft_moves(t_game *game)
{
	static double		old_dir_x = 0;
	static double		old_plane_x = 0;
	static t_player		*pl = NULL;

	pl = &game->player;
	pl->move_speed = 0.05;
	pl->rot_speed = 0.05;
	if (game->key.sprint == 1)
	{
		pl->move_speed = 0.09;
		pl->rot_speed = 0.09;
	}
	if (game->key.sprint == 0)
	{
		pl->move_speed = 0.05;
		pl->rot_speed = 0.05;
	}
	if (game->key.up_w == 1)
	{
		if (game->map->board[(int)(pl->pos.x + pl->dir.x * pl->move_speed)][(int)pl->pos.y] != '1')
			pl->pos.x += pl->dir.x * pl->move_speed;
		if (game->map->board[(int)pl->pos.x][(int)(pl->pos.y + pl->dir.y * pl->move_speed)] != '1')
			pl->pos.y += pl->dir.y * pl->move_speed;
	}
	if (game->key.down_s == 1)
	{
		if (game->map->board[(int)(pl->pos.x - pl->dir.x * pl->move_speed)][(int)pl->pos.y] != '1')
			pl->pos.x -= pl->dir.x * pl->move_speed;
		if (game->map->board[(int)pl->pos.x][(int)(pl->pos.y - pl->dir.y * pl->move_speed)] != '1')
			pl->pos.y -= pl->dir.y * pl->move_speed;
	}
	if (game->key.left_a == 1)
	{
		old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(pl->rot_speed) - pl->dir.y * sin(pl->rot_speed);
		pl->dir.y = old_dir_x * sin(pl->rot_speed) + pl->dir.y * cos(pl->rot_speed);
		old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(pl->rot_speed) - pl->plane.y * sin(pl->rot_speed);
		pl->plane.y = old_plane_x * sin(pl->rot_speed) + pl->plane.y * cos(pl->rot_speed);
	}
	if (game->key.right_d == 1)
	{
		old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(-pl->rot_speed) - pl->dir.y * sin(-pl->rot_speed);
		pl->dir.y = old_dir_x * sin(-pl->rot_speed) + pl->dir.y * cos(-pl->rot_speed);
		old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(-pl->rot_speed) - pl->plane.y * sin(-pl->rot_speed);
		pl->plane.y = old_plane_x * sin(-pl->rot_speed) + pl->plane.y * cos(-pl->rot_speed);
	}
}