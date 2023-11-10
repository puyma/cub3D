/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/08 16:12:23 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_frontal_moves(t_player *pl, t_game *game);
static void	ft_lateral_moves(t_player *pl, t_game *game);

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
	static t_player		*pl = NULL;

	pl = &game->player;
	pl->move_speed = 0.06;
	pl->rot_speed = 0.04;
	if (game->key.sprint == 1)
		pl->move_speed = 0.09;
	if (game->key.sprint == 0)
		pl->move_speed = 0.06;
	ft_frontal_moves(pl, game);
	ft_lateral_moves(pl, game);
}

static void	ft_frontal_moves(t_player *pl, t_game *game)
{
	if (game->key.up_w == 1)
	{
		if (game->map->board[(int)(pl->pos.x + pl->dir.x * pl->move_speed)]
				[(int)pl->pos.y] != '1')
			pl->pos.x += pl->dir.x * pl->move_speed;
		if (game->map->board[(int)pl->pos.x]
			[(int)(pl->pos.y + pl->dir.y * pl->move_speed)] != '1')
			pl->pos.y += pl->dir.y * pl->move_speed;
	}
	if (game->key.down_s == 1)
	{
		if (game->map->board[(int)(pl->pos.x - pl->dir.x * pl->move_speed)]
				[(int)pl->pos.y] != '1')
			pl->pos.x -= pl->dir.x * pl->move_speed;
		if (game->map->board[(int)pl->pos.x]
			[(int)(pl->pos.y - pl->dir.y * pl->move_speed)] != '1')
			pl->pos.y -= pl->dir.y * pl->move_speed;
	}
}

static void	ft_lateral_moves(t_player *pl, t_game *game)
{
	if (game->key.left_a == 1 || game->key.mouse == -1)
		ft_left(pl);
	if (game->key.right_d == 1 || game->key.mouse == 1)
		ft_right(pl);
}
