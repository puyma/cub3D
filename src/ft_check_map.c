/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:02:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/31 13:03:36 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define COL		0
#define ROW		1
#define CURRENT	0
#define PREV	1
#define FAIL	EXIT_FAILURE

/** WIP: refactorization **/

static int	ft_check_up(t_map *map);
static int	ft_check_down(t_map *map);
static int	ft_check_left(t_map *map);
static int	ft_check_right(t_map *map);
static int	ft_check_range(int **board, int type, size_t pos, int range[2]);

int	ft_check_map(t_map *map)
{
	if (ft_check_left(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_right(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_up(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_down(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_check_range(int **board, int type, size_t pos, int range[2])
{
	int	from;
	int	to;

	from = range[0];
	to = range[1];
	if (range [0] > range[1])
	{
		from = range[1];
		to = range[0];
	}
	while (from-- > to + 1)
	{
		if (type == COL && board[pos][from] != '1')
			return (EXIT_FAILURE);
		if (type == ROW && board[from][pos] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_left(t_map *map)
{
	int	range[2];
	int	y;
	int	sub;

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

static int	ft_check_right(t_map *map)
{
	int	range[2];
	int	y;
	int	sub;

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

static int	ft_check_up(t_map *map)
{
	int	range[2];
	int	x;
	int	sub;

	x = 0;
	range[PREV] = 0;
	while (x < map->width)
	{
		range[CURRENT] = 0;
		while (range[CURRENT] < map->height
			&& map->board[x][range[CURRENT]] != '1')
			++range[CURRENT];
		sub = range[CURRENT] - range[PREV];
		if (x != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_range(map->board, COL, x, range) == FAIL
				&& ft_check_range(map->board, COL, x - 1, range) == FAIL)
				return (ft_fprintf(stderr, "UP\n"), FAIL);
		}
		++x;
		range[PREV] = range[CURRENT];
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_down(t_map *map)
{
	int	range[2];
	int	x;
	int	sub;

	x = 0;
	range[PREV] = 0;
	while (x < map->width)
	{
		range[CURRENT] = map->height - 1;
		while (range[CURRENT] > 0
			&& map->board[x][range[CURRENT]] != '1')
			--range[CURRENT];
		sub = range[CURRENT] - range[PREV];
		if (x != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_range(map->board, COL, x, range) == FAIL
				&& ft_check_range(map->board, COL, x - 1, range) == FAIL)
				return (ft_fprintf(stderr, "DOWN\n"), FAIL);
		}
		++x;
		range[PREV] = range[CURRENT];
	}
	return (EXIT_SUCCESS);
}
