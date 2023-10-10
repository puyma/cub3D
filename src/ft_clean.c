/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:34:07 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/10 16:22:20 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_clean(t_game *game)
{
	free(game->i_north.path_to_image_file);
	free(game->i_south.path_to_image_file);
	free(game->i_west.path_to_image_file);
	free(game->i_east.path_to_image_file);
	//free(game->i_load_cueue);
}

void	ft_clean_textures(t_game *game)
{
	free(game->i_north.img);
	free(game->i_south.img);
	free(game->i_west.img);
	free(game->i_east.img);
}

void	ft_clean_map(t_map *map)
{
	size_t	i;

	if (map != NULL)
	{
		i = 0;
		while (i < map->height)
			free(map->board[i++]);
		free(map->board);
		free(map);
	}
}
