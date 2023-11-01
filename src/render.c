/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 12:05:59 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define START	0
#define END		1

int	ft_render(t_game *game)
{
	t_imgdata	*i;

	i = &game->i_main_frame;
	ft_add_background(i, game);
	ft_raycast_loop(game, i);
	ft_add_minimap(&game->i_main_frame, game);
	ft_add_handheld(&game->i_main_frame, game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, i->img, 0, 0);
	return (EXIT_SUCCESS);
}
