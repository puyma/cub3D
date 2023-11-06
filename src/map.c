/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:50:47 by mpuig-ma          #+#    #+#             */
<<<<<<< HEAD:src/ft_load_map.c
/*   Updated: 2023/11/03 20:18:25 by jsebasti         ###   ########.fr       */
=======
/*   Updated: 2023/11/03 11:54:45 by mpuig-ma         ###   ########.fr       */
>>>>>>> origin/main:src/map.c
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
	t_list	*map;
	t_list	*info;

<<<<<<< HEAD:src/ft_load_map.c
=======
	exit_status = EXIT_SUCCESS;
	game->tmp_info_cardinal_points[0] = 0;
	game->tmp_info_cardinal_points[1] = 0;
	game->tmp_info_cardinal_points[2] = 0;
	game->tmp_info_cardinal_points[3] = 0;
	game->tmp_info_colors = 0;
>>>>>>> origin/main:src/map.c
	map = ft_extract_map_segment(file);
	if (!map)
		return (EXIT_FAILURE);
	info = ft_extract_info_segment(file);
	if (!info)
		return (EXIT_FAILURE);
	if (ft_set_info(info, game) == EXIT_FAILURE)
	{
		ft_lstclear(&map, &free);
		ft_lstclear(&info, &free);
		return (EXIT_FAILURE);
	}
	if (ft_set_board(map, game) == EXIT_FAILURE)
	{
		ft_lstclear(&map, &free);
		ft_lstclear(&info, &free);
		return (EXIT_FAILURE);
	}
	ft_lstclear(&map, &free);
	ft_lstclear(&info, &free);
<<<<<<< HEAD:src/ft_load_map.c
	ft_set_player(game);
	return (EXIT_SUCCESS);
}

/*
** DESCRIPTION
** Both ft_extract_segment() functions will return a pointer to the first node 
** of the map segment. It will also point the last node (->next) to NULL.
**
** Each segment, then, will have to be freed individually!
*/

// prev should not be NULL, map should not start directly with '0' or '1'
// for this -> check that more than one line

static t_list	*ft_extract_map_segment(t_list *file_content)
{
	char	*line;
	t_list	*prev;

	prev = NULL;
	while (file_content != NULL)
	{
		line = (char *) file_content->content;
		while (line && ft_isspace(*line) == 1)
			++line;
		if (*line == '0' || *line == '1')
		{
			file_content = prev->next;
			prev->next = NULL;
			break ;
		}
		prev = file_content;
		file_content = file_content->next;
	}
	return (file_content);
}

static t_list	*ft_extract_info_segment(t_list *file_content)
{
	t_list	*tmp_list;
	char	*content;
	char	*tmp;

	tmp_list = file_content;
	while (tmp_list != NULL)
	{
		tmp = tmp_list->content;
		content = ft_strtrim(tmp, " \t\n");
		free(tmp);
		tmp_list->content = content;
		tmp_list = tmp_list->next;
	}
	return (file_content);
}

=======
	if (exit_status == EXIT_FAILURE)
		ft_clean(game);
	else
		ft_set_player(game);
	return (exit_status);
}

>>>>>>> origin/main:src/map.c
static void	ft_set_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (ft_strchr("NSEW", game->map->board[x][y]) != NULL)
			{
				game->player.pos.x = x + 0.5;
				game->player.pos.y = y + 0.5;
				game->player.dir.x = 0;
				game->player.dir.y = 0;
				ft_set_view_direction(&game->player, game->map->board[x][y]);
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
