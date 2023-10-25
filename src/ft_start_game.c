/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:33:58 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/25 18:29:45 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rays(t_game *game)
{
	PRINT_MAP(game->map)
	double	Px = 3, Py = 2;
	size_t	view_angle = 90;
	size_t	i = view_angle - 30;
	double	FirstIntersectX, FirstIntersectY;

	exit(0);
}

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
	ft_rays(game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
