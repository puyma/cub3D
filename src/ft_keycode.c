/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/02 19:28:31 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_keycode(int k, t_game *game)
{
	double		old_dir_x;
	double		old_plane_x;
	t_player	*pl;

	pl = &game->player;
	pl->move_speed = 0.10;
	pl->rot_speed = 0.10;
	if (k == KEY_ESC)
		return (ft_destroy(game), EXIT_SUCCESS);
	if ((k == KEY_W || k == KEY_UP) && pl->hit != 1)
	{
		if (game->map->board[(int)(pl->pos.x + pl->dir.x * pl->move_speed)][(int)pl->pos.y] != '1')
			pl->pos.x += pl->dir.x * pl->move_speed;
		if (game->map->board[(int)pl->pos.x][(int)(pl->pos.y + pl->dir.y * pl->move_speed)] != '1')
			pl->pos.y += pl->dir.y * pl->move_speed;
	}
	else if (k == KEY_S || k == KEY_DOWN)
	{
		if (game->map->board[(int)(pl->pos.x - pl->dir.x * pl->move_speed)][(int)pl->pos.y] != '1')
			pl->pos.x -= pl->dir.x * pl->move_speed;
		if (game->map->board[(int)pl->pos.x][(int)(pl->pos.y - pl->dir.y * pl->move_speed)] != '1')
			pl->pos.y -= pl->dir.y * pl->move_speed;
	}
	else if (k == KEY_A || k == KEY_LEFT)
	{
		old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(pl->rot_speed) - pl->dir.y * sin(pl->rot_speed);
		pl->dir.y = old_dir_x * sin(pl->rot_speed) + pl->dir.y * cos(pl->rot_speed);
		old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(pl->rot_speed) - pl->plane.y * sin(pl->rot_speed);
		pl->plane.y = old_plane_x * sin(pl->rot_speed) + pl->plane.y * cos(pl->rot_speed);
	}
	else if (k == KEY_D || k == KEY_RIGHT)
	{
		old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(-pl->rot_speed) - pl->dir.y * sin(-pl->rot_speed);
		pl->dir.y = old_dir_x * sin(-pl->rot_speed) + pl->dir.y * cos(-pl->rot_speed);
		old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(-pl->rot_speed) - pl->plane.y * sin(-pl->rot_speed);
		pl->plane.y = old_plane_x * sin(-pl->rot_speed) + pl->plane.y * cos(-pl->rot_speed);
	}
	return (EXIT_SUCCESS);
}
