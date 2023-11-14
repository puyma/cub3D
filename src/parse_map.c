/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:12:42 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/14 17:20:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "_debug.h"

int				validate_map(t_list *map_lst);
int				validate_info(t_list *info_lst);
int				dump_info(t_list *info_lst, t_game *game);
int				dump_map(t_list *map_lst, t_map *map, t_game *game);
static t_list	*ft_extract_map_segment(t_list *file);
static t_list	*ft_extract_info_segment(t_list *file);

int	parse_map(t_game *game, t_map *map, char *filename)
{
	t_list	*file;
	t_list	*map_segment;
	t_list	*info_segment;

	map->filename = filename;
	file = read_file(map->filename);
	if (file == NULL)
		return (EXIT_FAILURE);
	map_segment = ft_extract_map_segment(file);
	info_segment = ft_extract_info_segment(file);
	if (validate_info(info_segment) == EXIT_FAILURE
		|| validate_map(map_segment) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	dump_info(info_segment, game);
	dump_map(map_segment, map, game);
	ft_lstclear(&map_segment, &free);
	ft_lstclear(&info_segment, &free);
	return (EXIT_SUCCESS);
}

/* DESCRIPTION
** Both ft_extract_segment() functions will return a pointer to the first node 
** of the map segment. It will also point the last node (->next) to NULL.
**
** Each segment, then, will have to be freed individually!
*/

// prev should not be NULL, map should not start directly with '0' or '1'
// for this -> check that more than one line

t_list	*ft_extract_map_segment(t_list *file)
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