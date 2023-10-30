/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:01:08 by mpuig-ma          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/27 18:23:23 by jsebasti         ###   ########.fr       */
=======
/*   Updated: 2023/10/19 12:35:04 by mpuig-ma         ###   ########.fr       */
>>>>>>> puyma-minimap
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_characters(t_game *game, t_list *map_lst);
static int	ft_fill_map(t_list *map_lst, t_map *map);
static void	ft_homogenize_map(t_map *map);

int	ft_set_board(t_list *map_lst, t_game *game)
{
	size_t	i;

	game->map = ft_calloc(sizeof(t_map), 1);
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
	if (ft_check_characters(game, map_lst) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_fill_map(map_lst, game->map);
	ft_homogenize_map(game->map);
	if (ft_check_map(game->map) == EXIT_FAILURE)
		return (ft_fprintf(stderr, "%s: %s: invalid map\n",
				EXEC_NAME, game->map_filename_ptr), EXIT_FAILURE);
	return (ft_fill_map(map_lst, game->map), EXIT_SUCCESS);
}

static int	ft_check_characters(t_game *game, t_list *map_lst)
{
	size_t	x;
	size_t	y;
	char	*str;

	y = 0;
	while (map_lst != NULL)
	{
		x = 0;
		str = map_lst->content;
		while (x < game->map->width && str[x] != '\0')
		{
			if (ft_strchr("NSEW10 ", str[x]) == NULL && str[x] != '\0')
				return (ft_fprintf(stderr, "%s: %s: line %d: %s\n",
						EXEC_NAME, game->map_filename_ptr,
						game->tmp_counter + y + 1, "invalid character"),
					EXIT_FAILURE);
			++x;
		}
		++y;
		map_lst = map_lst->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_fill_map(t_list *map_lst, t_map *map)
{
	char	*str;
	size_t	x;
	size_t	y;
	size_t	nb_c_allowed;

	nb_c_allowed = 0;
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
	return (EXIT_SUCCESS);
}

static void	ft_homogenize_map(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->board[x][y] == '1')
			{
				if (y != 0 && y != map->height - 1
					&& map->board[x][y - 1] == 0 && map->board[x][y + 1] == 0)
					map->board[x][y] = '\0';
				if (x != 0 && x != map->width - 1
					&& map->board[x - 1][y] == 0 && map->board[x + 1][y] == 0)
					map->board[x][y] = '\0';
			}
			++x;
		}
		++y;
	}
}
