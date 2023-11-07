/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/07 18:45:49 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse(int x, int y, t_game *game)
{
	const static double	half_width = WIN_WIDTH / 2;
	static double		old_mouse_dir = 0;
	static double		current_mouse_dir = 0;
	static double		diff = 0;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (mlx_mouse_show(), EXIT_SUCCESS);
	x -= WIN_WIDTH / 2;
	(void)y;
	old_mouse_dir = current_mouse_dir;
	current_mouse_dir = x / half_width;
	diff = current_mouse_dir - old_mouse_dir;
	if (diff < 0)
		ft_left(&game->player);
	else if (diff > 0)
		ft_right(&game->player);
	return (EXIT_SUCCESS);
}

void ft_left(t_player *pl)
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

void ft_right(t_player *pl)
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
