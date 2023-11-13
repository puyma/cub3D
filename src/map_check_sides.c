/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_sides.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:28:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/13 15:37:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define COL		0
#define ROW		1
#define CURRENT	0
#define PREV	1
#define FAIL	EXIT_FAILURE

int	ft_check_range(int **board, int type, size_t pos, int range[2]);

int	ft_check_left(t_map *map)
{
	int	range[2];
	int	y;
	int	sub;

	printf("ft_check_left\n");
	y = 0;
	range[PREV] = 0;
	while (y < map->height)
	{
		range[CURRENT] = 0;
		while (range[CURRENT] < map->width
			&& map->board[range[CURRENT]][y] != '1')
			++range[CURRENT];
		sub = range[CURRENT] - range[PREV];
		if (y != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_range(map->board, ROW, y, range) == FAIL
				&& ft_check_range(map->board, ROW, y - 1, range) == FAIL)
				return (ft_fprintf(stderr, "LEFT\n"), FAIL);
		}
		++y;
		range[PREV] = range[CURRENT];
	}
	return (EXIT_SUCCESS);
}

int	ft_check_right(t_map *map)
{
	int	range[2];
	int	y;
	int	sub;

	printf("ft_check_right\n");
	y = 0;
	range[PREV] = 0;
	while (y < map->height)
	{
		range[CURRENT] = map->width - 1;
		while (range[CURRENT] > 0
			&& map->board[range[CURRENT]][y] != '1')
			--range[CURRENT];
		sub = range[CURRENT] - range[PREV];
		if (y != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_range(map->board, ROW, y, range) == FAIL
				&& ft_check_range(map->board, ROW, y - 1, range) == FAIL)
				return (ft_fprintf(stderr, "RIGHT\n"), FAIL);
		}
		++y;
		range[PREV] = range[CURRENT];
	}
	return (EXIT_SUCCESS);
}
