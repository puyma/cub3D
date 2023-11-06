/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:50:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/06 13:54:40 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void		ft_set_player(t_game *game);
static void		ft_set_view_direction(t_player *player, char c);

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

int	ft_load_map(t_list *file, t_game *game)
{
	int		exit_status;
	t_list	*map;
	t_list	*info;

	exit_status = EXIT_SUCCESS;
	game->tmp_info_cardinal_points[0] = 0;
	game->tmp_info_cardinal_points[1] = 0;
	game->tmp_info_cardinal_points[2] = 0;
	game->tmp_info_cardinal_points[3] = 0;
	game->tmp_info_colors = 0;
	map = ft_extract_map_segment(file);
	info = ft_extract_info_segment(file);
	if (ft_set_info(info, game) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE;
	if (exit_status == EXIT_SUCCESS && ft_set_board(map, game) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE;
	ft_lstclear(&map, &free);
	ft_lstclear(&info, &free);
	if (exit_status == EXIT_FAILURE)
		ft_clean(game);
	else
		ft_set_player(game);
	return (exit_status);
}

static void	ft_set_player(t_game *game)
{
	int	x;
	int	y;

	PRINT_INFO(game)
	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (ft_strchr("NSEW", game->map->board[x][y]) != NULL
					&& game->map->board[x][y] != '\0')
			{
				game->player.pos.x = x + 0.5;
				game->player.pos.y = y + 0.5;
				game->player.dir.x = 0;
				game->player.dir.y = 0;
				(void) ft_set_view_direction;
				//ft_set_view_direction(&game->player, game->map->board[x][y]);
				return ;
			}
			++x;
		}
		++y;
	}
}

static void	ft_set_view_direction(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir.x = -1;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else if (c == 'S')
	{
		player->dir.x = 1;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
	else if (c == 'W')
	{
		player->dir.y = -1;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else
	{
		player->dir.y = 1;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
}
