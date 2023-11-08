/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:06:05 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/08 11:21:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_resize_win(t_game *game)
{
	if (game->resize == 0)
	{
		game->win_height = 1080;
		game->win_width = 720;
		mlx_clear_window(game->mlx, game->mlx_window);
		mlx_destroy_window(game->mlx, game->mlx_window);
		game->mlx_window = mlx_new_window(game->mlx,
				game->win_width, game->win_height, EXEC_NAME);
		game->resize = 1;
	}
	else if (game->resize == 1)
	{
		game->win_width = WIN_WIDTH;
		game->win_height = WIN_HEIGHT;
		mlx_clear_window(game->mlx, game->mlx_window);
		mlx_destroy_window(game->mlx, game->mlx_window);
		game->mlx_window = mlx_new_window(game->mlx,
				game->win_width, game->win_height, EXEC_NAME);
		game->resize = 0;
	}
	return (EXIT_SUCCESS);
}
