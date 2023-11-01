/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 20:42:08 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	g_move_speed;
double	g_rot_speed;

int	ft_keycode(int k, t_game *game)
{
	double		old_dir_x;
	double		old_plane_x;
	t_player	*pl;

	pl = &game->player;
	g_move_speed = 0.25;
	g_rot_speed = 0.25;
	if (k == KEY_ESC)
		return (ft_destroy(game), EXIT_SUCCESS);
	if ((k == KEY_W || k == KEY_UP) && pl->hit != 1)
	{
		if (game->map->board[(int)(pl->pos.x + pl->dir.x * g_move_speed)][(int)pl->pos.y] != '1')
			pl->pos.x += pl->dir.x * g_move_speed;
		if (game->map->board[(int)pl->pos.x][(int)(pl->pos.y + pl->dir.y * g_move_speed)] != '1')
			pl->pos.y += pl->dir.y * g_move_speed;
	}
	else if (k == KEY_S || k == KEY_DOWN)
	{
		if (game->map->board[(int)(pl->pos.x - pl->dir.x * g_move_speed)][(int)pl->pos.y] != '1')
			pl->pos.x -= pl->dir.x * g_move_speed;
		if (game->map->board[(int)pl->pos.x][(int)(pl->pos.y - pl->dir.y * g_move_speed)] != '1')
			pl->pos.y -= pl->dir.y * g_move_speed;
	}
	else if (k == KEY_A || k == KEY_LEFT)
	{
		old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(g_rot_speed) - pl->dir.y * sin(g_rot_speed);
		pl->dir.y = old_dir_x * sin(g_rot_speed) + pl->dir.y * cos(g_rot_speed);
		old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(g_rot_speed) - pl->plane.y * sin(g_rot_speed);
		pl->plane.y = old_plane_x * sin(g_rot_speed) + pl->plane.y * cos(g_rot_speed);
	}
	else if (k == KEY_D || k == KEY_RIGHT)
	{
		old_dir_x = pl->dir.x;
		pl->dir.x = pl->dir.x * cos(-g_rot_speed) - pl->dir.y * sin(-g_rot_speed);
		pl->dir.y = old_dir_x * sin(-g_rot_speed) + pl->dir.y * cos(-g_rot_speed);
		old_plane_x = pl->plane.x;
		pl->plane.x = pl->plane.x * cos(-g_rot_speed) - pl->plane.y * sin(-g_rot_speed);
		pl->plane.y = old_plane_x * sin(-g_rot_speed) + pl->plane.y * cos(-g_rot_speed);
	}
	return (EXIT_SUCCESS);
}
