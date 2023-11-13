/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:02:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/13 15:55:42 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define COL		0
#define ROW		1
#define CURRENT	0
#define PREV	1
#define FAIL	EXIT_FAILURE

/** WIP: refactorization **/

int			ft_check_up(t_map *map);
int			ft_check_down(t_map *map);
int			ft_check_left(t_map *map);
int			ft_check_right(t_map *map);
int			ft_check_range(int **board, int type, size_t pos, int range[2]);

int	ft_check_map(t_map *map)
{
	printf("ft_check_map\n");
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

int	ft_check_range(int **board, int type, size_t pos, int range[2])
{
	int	from;
	int	to;

	printf("ft_check_range\n");
	printf("  pos=%lu range %d to %d\n", pos, range[0], range[1]);
	from = range[0];
	to = range[1];
	if (range [0] > range[1])
	{
		from = range[1];
		to = range[0];
	}
	printf("  from is: %d, to: %d\n", from, to);
	while (from++ < to - 1)
	{
		if (type == COL)
			printf("  checking: '%c' (from=%d)\n", board[pos][from], from);
		else
			printf("  checking: '%c' (from=%d)\n", board[from][pos], from);
if (type == COL && board[pos][from] != '1')
			return (EXIT_FAILURE);
		if (type == ROW && board[from][pos] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_check_up(t_map *map)
{
	int	range[2];
	int	x;
	int	sub;

	printf("ft_check_up\n");
	x = 0;
	range[PREV] = 0;
	while (x < map->width)
	{
		printf("up: %d ", x);
		range[CURRENT] = 0;
		while (range[CURRENT] < map->height
			&& map->board[x][range[CURRENT]] != '1')
			++range[CURRENT];
		sub = range[CURRENT] - range[PREV];
		printf("sub: %d\n", sub);
		if (x != 0 && (sub > 1 || sub < -1))
		{
			printf("will check x=%d\n", x);
			if (ft_check_range(map->board, COL, x, range) == FAIL
				&& ft_check_range(map->board, COL, x - 1, range) == FAIL)
				return (ft_fprintf(stderr, "UP\n"), EXIT_FAILURE);
		}
		++x;
		range[PREV] = range[CURRENT];
	}
	return (EXIT_SUCCESS);
}

int	ft_check_down(t_map *map)
{
	int	range[2];
	int	x;
	int	sub;

	printf("ft_check_down\n");
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
				return (ft_fprintf(stderr, "DOWN\n"), EXIT_FAILURE);
		}
		++x;
		range[PREV] = range[CURRENT];
	}
	return (EXIT_SUCCESS);
}
