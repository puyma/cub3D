/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:01:08 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/06 17:30:05 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_map	*ft_init_map(t_list *map_lst);
static int		ft_fill_map(t_list *map_lst, t_map *map);

int	ft_set_map(t_list *map_lst, t_game *game)
{
	game->map = ft_init_map(map_lst);
	if (game->map == NULL || ft_fill_map(map_lst, game->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//PRINT_MAP(game->map);
	return (EXIT_SUCCESS);
}

static t_map	*ft_init_map(t_list *map_lst)
{
	size_t	i;
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = ft_lstwidth(map_lst);
	map->height = ft_lstheight(map_lst);
	//ft_printf("w: %u, h: %u\n", map->width, map->height);
	map->board = (int **) ft_calloc(map->width, sizeof(int *));
	if (map->board == NULL)
		return (free(map), NULL);
	i = 0;
	while (i < map->width)
		map->board[i++] = (int *) ft_calloc(map->height, sizeof(int));
	return (map);
}

static int	ft_fill_map(t_list *map_lst, t_map *map)
{
	char	*str;
	size_t	x;
	size_t	y;

	y = 0;
	while (map_lst != NULL)
	{
		x = 0;
		str = map_lst->content;
		while (x < map->width && str[x] != '\0')
		{
			if (ft_strchr(C_ALLOWED, str[x]) != NULL)
				map->board[x][y] = str[x];
			++x;
		}
		++y;
		map_lst = map_lst->next;
	}
	return (EXIT_SUCCESS);
}
