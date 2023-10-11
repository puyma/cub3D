/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:33:58 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/11 17:42:11 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL || ft_load_textures(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->mlx_window = mlx_new_window(game->mlx,
			WIN_WIDTH, WIN_HEIGHT, EXEC_NAME);
	mlx_hook(game->mlx_window, ON_DESTROY, 0, &ft_destroy, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, 0, &ft_keycode, (void *) game);
	mlx_mouse_hide();
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
