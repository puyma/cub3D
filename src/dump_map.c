/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:26:11 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 17:28:47 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_player(t_map *map, t_player *player);
static void	set_view_direction(t_player *player, char c);

int	dump_map(t_map *map, t_game *game)
{
	int	i;

	map->width = ft_lstwidth(map->map_segment);
	map->height = ft_lstheight(map->map_segment);
	map->board = (int **)ft_calloc(map->height, sizeof(int *));
	if (map->board == NULL)
		return (1);
	i = 0;
	while (i < map->height)
		map->board[i++] = ft_calloc(map->width, sizeof(int));
	fill_map(map->map_segment, map);
	set_player(map, &game->player);
	return (0);
}

void	fill_map(t_list *map_lst, t_map *map)
{
	char	*str;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (map_lst != NULL)
	{
		i = map->width;
		x = 0;
		str = map_lst->content;
		while (--i >= 0 && str[x] != '\0')
		{
			if (ft_strchr("NSEW10", str[x]) != NULL)
				map->board[y][x] = str[x];
			++x;
		}
		++y;
		map_lst = map_lst->next;
	}
}

/*
** The map must be composed of only 6 possible characters:
**  0 for an empty space,
**  1 for a wall,
**  and N,S,E or W for the player’s start position and spawning orientation.
**
** Except for the map content, each type of element can be separated by one
** or more empty line(s).
**
** Except for the map content which always has to be the last, each type of
** element can be set in any order in the file.
**
** Except for the map, each type of information from an element can be
** separated by one or more space(s).
*/

static void	set_player(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (ft_strchr("NSEW", map->board[y][x]) != NULL
				&& map->board[y][x] != 0)
			{
				player->pos.x = x + 0.5;
				player->pos.y = y + 0.5;
				player->dir.x = 0;
				player->dir.y = 0;
				set_view_direction(player, map->board[y][x]);
				return ;
			}
			++x;
		}
		++y;
	}
}

static void	set_view_direction(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir.y = -1;
		player->plane.y = 0;
		player->plane.x = -0.66;
	}
	else if (c == 'S')
	{
		player->dir.y = 1;
		player->plane.y = 0;
		player->plane.x = 0.66;
	}
	else if (c == 'W')
	{
		player->dir.x = -1;
		player->plane.y = -0.66;
		player->plane.x = 0;
	}
	else
	{
		player->dir.x = 1;
		player->plane.y = 0.66;
		player->plane.x = 0;
	}
}
