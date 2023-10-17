/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:50:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/17 12:37:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_list	*ft_extract_map_segment(t_list *file);
static t_list	*ft_extract_info_segment(t_list *file);

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
	map = ft_extract_map_segment(file);
	info = ft_extract_info_segment(file);
	if (ft_set_info(info, game) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE;
	if (exit_status == EXIT_SUCCESS && ft_set_board(map, game) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE; // clean board (?)
	ft_lstclear(&map, &free);
	ft_lstclear(&info, &free);
	return (exit_status);
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

static t_list	*ft_extract_map_segment(t_list *file)
{
	char	*line;
	t_list	*prev;

	prev = NULL;
	while (file != NULL)
	{
		line = (char *) file->content;
		while (line && ft_isspace(*line) == 1)
			++line;
		if (*line == '0' || *line == '1')
		{
			file = prev->next;
			prev->next = NULL;
			break ;
		}
		prev = file;
		file = file->next;
	}
	return (file);
}

static t_list	*ft_extract_info_segment(t_list *file)
{
	t_list	*cpy;
	char	*content;
	char	*tmp;

	cpy = file;
	while (cpy != NULL)
	{
		tmp = cpy->content;
		content = ft_strtrim(tmp, " \t\n");
		free(tmp);
		cpy->content = content;
		cpy = cpy->next;
	}
	return (file);
}
