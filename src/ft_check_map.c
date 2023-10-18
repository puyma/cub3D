/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:02:30 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/18 17:24:06 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define EX_F EXIT_FAILURE

/** WIP **/

static int	ft_check_up(t_map *map);
static int	ft_check_down(t_map *map);
static int	ft_check_left(t_map *map);
static int	ft_check_right(t_map *map);
static int	ft_check_row(int **board, size_t y, size_t from, size_t to);
static int	ft_check_column(int **board, size_t x, size_t from, size_t to);

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

static int	ft_check_left(t_map *map)
{
	size_t	y;
	size_t	left;
	size_t	prev_left;
	int		sub;

	y = 0;
	prev_left = 0;
	while (y < map->height)
	{
		left = 0;
		while (left < map->width && map->board[left][y] != '1')
			++left;
		sub = left - prev_left;
		if (y != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_row(map->board, y, left, prev_left) == EXIT_FAILURE
				&& ft_check_row(map->board, y - 1, left, prev_left) == EX_F)
				return (ft_fprintf(stderr, "LEFT\n"), EXIT_FAILURE);
		}
		++y;
		prev_left = left;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_right(t_map *map)
{
	size_t	y;
	size_t	right;
	size_t	prev_right;
	int		sub;

	y = 0;
	prev_right = 0;
	while (y < map->height)
	{
		right = map->width - 1;
		while (right > 0 && map->board[right][y] != '1')
			--right;
		sub = right - prev_right;
		if (y != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_row(map->board, y, right, prev_right) == EXIT_FAILURE
				&& ft_check_row(map->board, y - 1, right, prev_right) == EX_F)
				return (ft_fprintf(stderr, "RIGHT\n"), EXIT_FAILURE);
		}
		++y;
		prev_right = right;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_up(t_map *map)
{
	size_t	x;
	size_t	up;
	size_t	prev_up;
	int		sub;

	x = 0;
	prev_up = 0;
	while (x < map->width)
	{
		up = 0;
		while (up < map->height && map->board[x][up] != '1')
			++up;
		sub = up - prev_up;
		if (x != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_column(map->board, x, up, prev_up) == EXIT_FAILURE
				&& ft_check_column(map->board, x - 1, up, prev_up) == EX_F)
				return (ft_fprintf(stderr, "UP\n"), EXIT_FAILURE);
		}
		++x;
		prev_up = up;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_down(t_map *map)
{
	size_t	x;
	size_t	down;
	size_t	prev_down;
	int		sub;

	x = 0;
	prev_down = 0;
	while (x < map->width)
	{
		down = map->height - 1;
		while (down > 0 && map->board[x][down] != '1')
			--down;
		while (down > 0 && map->board[x][down - 1] == '\0')
		{
			while (down > 0 && map->board[x][down] != '1')
				--down;
			--down;
		}
		sub = down - prev_down;
		if (x != 0 && (sub > 1 || sub < -1))
		{
			if (ft_check_column(map->board, x, down, prev_down) == EXIT_FAILURE
				&& ft_check_column(map->board, x - 1, down, prev_down) == EX_F)
				return (ft_fprintf(stderr, "DOWN\n"), EXIT_FAILURE);
		}
		++x;
		prev_down = down;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_row(int **board, size_t y, size_t from, size_t to)
{
	if (from > to)
	{
		while (from-- > to + 1)
			if (board[from][y] != '1')
				return (EXIT_FAILURE);
	}
	else
	{
		while (to-- > from + 1)
			if (board[to][y] != '1')
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_column(int **board, size_t x, size_t from, size_t to)
{
	if (from > to)
	{
		while (from-- > to + 1)
			if (board[x][from] != '1')
				return (EXIT_FAILURE);
	}
	else
	{
		while (to-- > from + 1)
			if (board[x][to] != '1')
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
