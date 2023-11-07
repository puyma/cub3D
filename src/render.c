/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/07 15:18:45 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define START	0
#define END		1

int	ft_render(t_game *game)
{
	t_imgdata	*i;

	i = &game->i_main_frame;
	background(i, game);
	raycast_loop(game, &game->player, &game->ray, i);
	minimap(&game->i_main_frame, game);
	ft_add_handheld(&game->i_main_frame, game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, i->img, 0, 0);
	return (EXIT_SUCCESS);
}
