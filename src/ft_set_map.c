/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:01:08 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/05 17:11:35 by mpuig-ma         ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}

static t_map	*ft_init_map(t_list *map_lst)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = ft_lstwidth(map_lst);
	map->height = ft_lstheight(map_lst);
	map->board = ft_calloc(map->width * map->height, sizeof(int));
	if (map->board == NULL)
		return (free(map), NULL);
	return (map);
}

static int	ft_fill_map(t_list *map_lst, t_map *map)
{
	(void) map;
	(void) map_lst;
	return (EXIT_SUCCESS);
}
