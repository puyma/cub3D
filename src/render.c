/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 15:36:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	minimap_background(t_imgdata *img);
void	minimap_content(t_imgdata *img, t_game *game);

int	ft_render(t_game *game)
{
	t_imgdata	*i;

	i = &game->i_main_frame;
	background(i, game);
	raycast_loop(game, &game->player, &game->ray);
	mlx_put_image_to_window(game->mlx, game->mlx_window, i->img, 0, 0);
	game->key.mouse = 0;
	return (EXIT_SUCCESS);
}
