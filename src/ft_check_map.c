/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:02:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/17 16:02:40 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_check_map(t_map *map)
{
	size_t	prev_left;
	size_t	prev_right;
	size_t	y;

	PRINT_MAP(map)
	y = 0;
	while (y < map->height)
	{
		prev_left = 0;
		prev_right = map->width - 1;
		while (prev_left < map->width && map->board[prev_left][y] != '1')
			++prev_left;
		while (prev_right > 0 && map->board[prev_right][y] != '1')
			--prev_right;
		ft_printf("%u: l: %u, r: %u\n", y, prev_left, prev_right);
		++y;
	}
	return (EXIT_SUCCESS);
}
