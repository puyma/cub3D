/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:54:04 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 16:22:14 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//check theres only one player (at least)
int	check_player(t_list *map_lst)
{
	char	*str;
	int		counter;

	printf("check_player\n");
	counter = 0;
	while (map_lst != NULL)
	{
		str = map_lst->content;
		while (*str != '\0')
		{
			if (ft_strchr("NSEW", *str) != NULL)
				++counter;
			++str;
		}
		map_lst = map_lst->next;
	}
	if (counter != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_player_edge(t_map *map, t_player *player)
{
	int	x;
	int	y;

	int ry = 0; int rx = 0;
	while (ry < map->height)
	{
		rx = 0;
		while (rx < map->width)
		{
			printf("%d ", map->board[ry][rx]);
			++rx;
		}
		printf("\n");
		++ry;
	}
	printf("check_player_edge\n");
	x = player->pos.x;
	y = player->pos.y;
	printf("width: %d\n", map->width);
	printf("height: %d\n", map->height);
	printf("%d %d\n", x, y);
	printf("a\n");

	if (x == 0 || map->board[y][x - 1] == '\0')
		return (EXIT_FAILURE);
	printf("b\n");
	if (x == map->width - 1 || map->board[y][x + 1] == '\0')
		return (EXIT_FAILURE);
	printf("c\n");
	if (y == 0 || map->board[y - 1][x] == '\0')
		return (EXIT_FAILURE);
	printf("d\n");
	if (y == map->height - 1 || map->board[y + 1][x] == '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
