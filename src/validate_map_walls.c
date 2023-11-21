/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:16:52 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/21 21:56:04 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_walls(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (map->board[x][y] == '0')
			{
				if (x == 0 || map->board[x - 1][y] == '\0')
					return (EXIT_FAILURE);
				if (x == map->width - 1 || map->board[x + 1][y] == '\0')
					return (EXIT_FAILURE);
				if (y == 0 || map->board[x][y - 1] == '\0')
					return (EXIT_FAILURE);
				if (y == map->height - 1 || map->board[x][y + 1] == '\0')
					return (EXIT_FAILURE);
			}
			++y;
		}
		++x;
	}
	return (EXIT_SUCCESS);
}
