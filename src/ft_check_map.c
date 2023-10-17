/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:02:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/17 20:20:51 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/** WIP **/

int	ft_check_map(t_map *map)
{
	size_t	left, prev_left;
	size_t	y;

	PRINT_MAP(map)
	prev_left = 0;
	y = 0;
	while (y < map->height)
	{
		left = 0;
		while (left < map->width && map->board[left][y] != '1')
			++left;

		int sub = left - prev_left;
		if (y != 0 && (sub > 1 || sub < -1))
		{
			printf("check from %lu to %lu\n", left, prev_left);
			if (left > prev_left)
			{
				while (left-- > prev_left)
				{
					printf("left: %lu, prev: %lu\n", left, prev_left);
					if (map->board[left][y] != '1')
					{
						ft_fprintf(stderr, "wrong\n");
						return (EXIT_FAILURE);
					}
				}
			}
			else
			{
				while (prev_left-- > left)
				{
					printf("prev_left: %lu, prev: %lu\n", prev_left, left);
					if (map->board[prev_left][y] != '1')
					{
						ft_fprintf(stderr, "wrrong\n");
						return (EXIT_FAILURE);
					}
				}
			}
		}
		
		printf("%02lu: l: %02lu\n", y, left);
		++y;
		prev_left = left;
	}
	return (EXIT_SUCCESS);
}
