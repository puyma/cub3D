/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/08 11:18:33 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse(int x, int y, t_game *game)
{
	double			half_width;
	static double	old_mouse_dir = 0;
	static double	current_mouse_dir = 0;
	static double	diff = 0;

	half_width = game->win_width / 2;
	if (x < 0 || y < 0 || x > game->win_width || y > game->win_height)
		return (EXIT_SUCCESS);
	x -= half_width;
	old_mouse_dir = current_mouse_dir;
	current_mouse_dir = x / half_width;
	diff = current_mouse_dir - old_mouse_dir;
	if (diff < 0)
		game->key.mouse = -1;
	else if (diff > 0)
		game->key.mouse = 1;
	else
		game->key.mouse = 0;
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
