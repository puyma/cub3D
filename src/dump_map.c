/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:26:11 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/14 16:26:50 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_map(t_list *map_lst, t_map *map);

int	dump_map(t_list *map_lst, t_map *map)
{
	int	i;

	map->width = ft_lstwidth(map_lst);
	map->height = ft_lstheight(map_lst);
	map->board = (int **)ft_calloc(map->width, sizeof(int *));
	if (map->board == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < map->width)
		map->board[i++] = ft_calloc(map->height, sizeof(int));
	fill_map(map_lst, map);
	return (EXIT_SUCCESS);
}

static void	fill_map(t_list *map_lst, t_map *map)
{
	char	*str;
	int		x;
	int		y;

	y = 0;
	while (map_lst != NULL)
	{
		x = 0;
		str = map_lst->content;
		while (x < map->width && str[x] != '\0')
		{
			if (ft_strchr("NSEW10", str[x]) != NULL)
				map->board[x][y] = str[x];
			++x;
		}
		++y;
		map_lst = map_lst->next;
	}
}
