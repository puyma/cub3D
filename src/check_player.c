/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:54:04 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 15:23:34 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//check theres only one player (at least)
int	check_player(t_list *map_lst)
{
	char	*str;
	int		counter;

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

	x = player->pos.x;
	y = player->pos.y;
	if (x == 0 || map->board[x - 1][y] == '\0')
		return (EXIT_FAILURE);
	if (x == map->width - 1 || map->board[x + 1][y] == '\0')
		return (EXIT_FAILURE);
	if (y == 0 || map->board[x][y - 1] == '\0')
		return (EXIT_FAILURE);
	if (y == map->height - 1 || map->board[x][y + 1] == '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
