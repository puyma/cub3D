/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:01:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/14 12:35:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_clean(t_game *game)
{
	int	counter;

	if (game->i_north.image_file != NULL)
		free(game->i_north.image_file);
	if (game->i_south.image_file != NULL)
		free(game->i_south.image_file);
	if (game->i_west.image_file != NULL)
		free(game->i_west.image_file);
	if (game->i_east.image_file != NULL)
		free(game->i_east.image_file);
	if (game->mlx != NULL)
		free(game->mlx);
	if (game->mlx_window != NULL)
		mlx_destroy_window(game->mlx, game->mlx_window);
	(void) counter;
	/*
	if (game->map != NULL)
	{
		counter = game->map->width;
		while (counter-- > 0)
			free(game->map->board[counter]);
		free(game->map->board);
		free(game->map);
	}
	*/
}
