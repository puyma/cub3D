/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/08 11:20:18 by mpuig-ma         ###   ########.fr       */
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
	mlx_put_image_to_window(game->mlx, game->mlx_window, i->img, 0, 0);
	return (EXIT_SUCCESS);
}
