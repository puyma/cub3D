/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:01:08 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/17 12:55:28 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_fill_map(t_list *map_lst, t_map *map);
static int	ft_check_map(t_map *map);

int	ft_set_board(t_list *map_lst, t_game *game)
{
	size_t	i;

	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL)
		return (EXIT_FAILURE);
	game->map->width = ft_lstwidth(map_lst);
	game->map->height = ft_lstheight(map_lst);
	game->map->board = (int **) ft_calloc(game->map->width, sizeof(int *));
	if (game->map->board == NULL)
		return (free(game->map), EXIT_FAILURE);
	i = 0;
	while (i < game->map->width)
		game->map->board[i++] = ft_calloc(game->map->height, sizeof(int));
	if (ft_fill_map(map_lst, game->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_check_map(game->map) == EXIT_FAILURE)
		return (ft_fprintf(stderr, "%s: %s: invalid map\n",
				EXEC_NAME, game->map_filename_ptr), EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
			if (ft_strchr(C_ALLOWED, str[x]) != NULL || str[x] == '1' || str[x] == '0')
				map->board[x][y] = str[x];
			++x;
		}
		++y;
		map_lst = map_lst->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_check_map(t_map *map)
{
	PRINT_MAP(map)
	(void) map;
	return (EXIT_SUCCESS);
}
