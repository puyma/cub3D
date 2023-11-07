/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/07 12:48:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	keycode_side_left(t_player *pl, t_game *game,
		double *old_dir_x, double *old_plane_x);
static void	keycode_side_right(t_player *pl, t_game *game,
		double *old_dir_x, double *old_plane_x);
static void	keycode_up(t_player *pl, t_game *game);
static void	keycode_down(t_player *pl, t_game *game);

int	ft_keycode(int k, t_game *game)
{
	static t_player		*pl;
	static double		old_dir_x;
	static double		old_plane_x;

	pl = &game->player;
	pl->move_speed = 0.10;
	pl->rot_speed = 0.10;
	if (k == KEY_ESC)
		return (ft_destroy(game), EXIT_SUCCESS);
	if ((k == KEY_W || k == KEY_UP) && pl->hit != 1)
		keycode_up(pl, game);
	else if (k == KEY_S || k == KEY_DOWN)
		keycode_down(pl, game);
	else if (k == KEY_A || k == KEY_LEFT)
		keycode_side_left(pl, game, &old_dir_x, &old_plane_x);
	else if (k == KEY_D || k == KEY_RIGHT)
		keycode_side_right(pl, game, &old_dir_x, &old_plane_x);
	return (EXIT_SUCCESS);
}

static void	keycode_up(t_player *pl, t_game *game)
{
	if (game->map->board[(int)(pl->pos.x + pl->dir.x * pl->move_speed)]
			[(int)pl->pos.y] != '1')
		pl->pos.x += pl->dir.x * pl->move_speed;
	if (game->map->board[(int)pl->pos.x]
		[(int)(pl->pos.y + pl->dir.y * pl->move_speed)] != '1')
		pl->pos.y += pl->dir.y * pl->move_speed;
}

static void	keycode_down(t_player *pl, t_game *game)
{
	if (game->map->board[(int)(pl->pos.x - pl->dir.x * pl->move_speed)]
			[(int)pl->pos.y] != '1')
		pl->pos.x -= pl->dir.x * pl->move_speed;
	if (game->map->board[(int)pl->pos.x]
		[(int)(pl->pos.y - pl->dir.y * pl->move_speed)] != '1')
		pl->pos.y -= pl->dir.y * pl->move_speed;
}

static void	keycode_side_left(t_player *pl, t_game *game,
		double *old_dir_x, double *old_plane_x)
{
	*old_dir_x = pl->dir.x;
	pl->dir.x = pl->dir.x * cos(pl->rot_speed)
		- pl->dir.y * sin(pl->rot_speed);
	pl->dir.y = *old_dir_x * sin(pl->rot_speed)
		+ pl->dir.y * cos(pl->rot_speed);
	*old_plane_x = pl->plane.x;
	pl->plane.x = pl->plane.x * cos(pl->rot_speed)
		- pl->plane.y * sin(pl->rot_speed);
	pl->plane.y = *old_plane_x * sin(pl->rot_speed)
		+ pl->plane.y * cos(pl->rot_speed);
	(void) game;
}

static void	keycode_side_right(t_player *pl, t_game *game,
		double *old_dir_x, double *old_plane_x)
{
	*old_dir_x = pl->dir.x;
	pl->dir.x = pl->dir.x * cos(-pl->rot_speed)
		- pl->dir.y * sin(-pl->rot_speed);
	pl->dir.y = *old_dir_x * sin(-pl->rot_speed)
		+ pl->dir.y * cos(-pl->rot_speed);
	*old_plane_x = pl->plane.x;
	pl->plane.x = pl->plane.x * cos(-pl->rot_speed)
		- pl->plane.y * sin(-pl->rot_speed);
	pl->plane.y = *old_plane_x * sin(-pl->rot_speed)
		+ pl->plane.y * cos(-pl->rot_speed);
	(void) game;
}
