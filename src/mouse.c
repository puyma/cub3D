/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/13 10:32:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_move_mouse(t_game *game, int x, int y);

int	ft_mouse(int x, int y, t_game *game)
{
	static double	half_width = WIN_WIDTH / 2;
	static double	old_mouse_dir = 0;
	static double	current_mouse_dir = 0;
	static double	diff = 0;

	if (game->key.pause == 0)
	{
		if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		{
			ft_move_mouse(game, x, y);
			return (EXIT_SUCCESS);
		}
		old_mouse_dir = current_mouse_dir;
		x -= half_width;
		current_mouse_dir = x / half_width;
		diff = current_mouse_dir - old_mouse_dir;
		if (diff < 0)
			game->key.mouse = -1;
		else if (diff > 0)
			game->key.mouse = 1;
		else
			game->key.mouse = 0;
	}
	return (EXIT_SUCCESS);
}

void	ft_left(t_player *pl)
{
	static double	old_dir_x = 0;
	static double	old_plane_x = 0;

	old_dir_x = pl->dir.x;
	pl->dir.x = pl->dir.x * cos(pl->rot_speed)
		- pl->dir.y * sin(pl->rot_speed);
	pl->dir.y = old_dir_x * sin(pl->rot_speed)
		+ pl->dir.y * cos(pl->rot_speed);
	old_plane_x = pl->plane.x;
	pl->plane.x = pl->plane.x * cos(pl->rot_speed)
		- pl->plane.y * sin(pl->rot_speed);
	pl->plane.y = old_plane_x * sin(pl->rot_speed)
		+ pl->plane.y * cos(pl->rot_speed);
}

void	ft_right(t_player *pl)
{
	static double	old_dir_x = 0;
	static double	old_plane_x = 0;

	old_dir_x = pl->dir.x;
	pl->dir.x = pl->dir.x * cos(-pl->rot_speed)
		- pl->dir.y * sin(-pl->rot_speed);
	pl->dir.y = old_dir_x * sin(-pl->rot_speed)
		+ pl->dir.y * cos(-pl->rot_speed);
	old_plane_x = pl->plane.x;
	pl->plane.x = pl->plane.x * cos(-pl->rot_speed)
		- pl->plane.y * sin(-pl->rot_speed);
	pl->plane.y = old_plane_x * sin(-pl->rot_speed)
		+ pl->plane.y * cos(-pl->rot_speed);
}

static void	ft_move_mouse(t_game *game, int x, int y)
{
	if (y <= 0 && (x < WIN_WIDTH && x > 0))
		mlx_mouse_move(game->mlx_window, x, WIN_HEIGHT - 1);
	else if (y >= WIN_HEIGHT && (x < WIN_WIDTH && x > 0))
		mlx_mouse_move(game->mlx_window, x, 1);
	else if (x >= WIN_WIDTH && (y < WIN_WIDTH && y > 0))
		mlx_mouse_move(game->mlx_window, 1, y);
	else if (x <= 0 && (y < WIN_WIDTH && y > 0))
		mlx_mouse_move(game->mlx_window, WIN_WIDTH - 1, y);
	else if (x <= 0 && y <= 0)
		mlx_mouse_move(game->mlx_window, WIN_WIDTH - 1, WIN_HEIGHT - 1);
	else if (x >= WIN_WIDTH && y >= WIN_HEIGHT)
		mlx_mouse_move(game->mlx_window, 1, 1);
	else if (x >= WIN_WIDTH && y <= 0)
		mlx_mouse_move(game->mlx_window, 1, WIN_HEIGHT - 1);
	else
		mlx_mouse_move(game->mlx_window, WIN_WIDTH - 1, 1);
}
