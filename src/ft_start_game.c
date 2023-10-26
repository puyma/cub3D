/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:33:58 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/26 17:27:45 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* This function loads the game's images and graphic stuff.
 * This includes initializing mlx, mlx's events,
 * calling mlx_loop, etc. */

int	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (EXIT_FAILURE);
	if (ft_load_textures(game) == EXIT_FAILURE)
		return (mlx_destroy_font(game->mlx), EXIT_FAILURE);
	game->mlx_window = mlx_new_window(game->mlx,
			game->win_width, game->win_height, EXEC_NAME);
	mlx_hook(game->mlx_window, ON_DESTROY, 0, &ft_destroy, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, 0, &ft_keycode, (void *) game);
	mlx_hook(game->mlx_window, ON_MOUSEMOVE, 0, &ft_mouse, (void *) game);
	mlx_loop_hook(game->mlx, &ft_render, (void *) game);
	PRINT_MAP(game->map)
	ft_rays(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
