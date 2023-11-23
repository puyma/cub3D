/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:12:42 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 16:25:44 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int		read_map(t_map *map);
static void		remove_empty_lines(t_map *map);
static t_list	*extract_map_segment(t_list *file);
static t_list	*extract_info_segment(t_list *file);

int	parse_map(t_game *game, t_map *map, char *filename)
{
	map->filename = filename;
	if (read_map(map) || validate_info(map)
		|| dump_map(map, game) || validate_map(map, &game->player))
	{
		ft_fprintf(stderr, "Error\n");
		ft_fprintf(stderr, "%s: %s: invalid map\n", EXEC_NAME, filename);
		return (EXIT_FAILURE);
	}
	dump_info(map, game);
	return (EXIT_SUCCESS);
}

static int	read_map(t_map *map)
{
	t_list	*file;

	file = read_file(map->filename);
	if (file == NULL)
		return (EXIT_FAILURE);
	map->map_segment = extract_map_segment(file);
	if (map->map_segment == NULL)
	{
		ft_lstclear(&file, &free);
		return (EXIT_FAILURE);
	}
	map->info_segment = extract_info_segment(file);
	if (map->info_segment == NULL || map->map_segment == map->info_segment)
		return (EXIT_FAILURE);
	remove_empty_lines(map);
	return (EXIT_SUCCESS);
}

static void	remove_empty_lines(t_map *map)
{
	t_list	*last;

	last = ft_lstlast(map->map_segment);
	while (last != NULL)
	{
		if (*((char *) last->content) == '\0'
			|| ft_isspace_str(last->content) == EXIT_SUCCESS)
			ft_lstclear_last(map->map_segment);
		else
			break ;
		last = ft_lstlast(map->map_segment);
	}
}

/* 
 * Both extract_segment() functions will return a pointer to the first node 
 * of the map segment. It will also point the last node (->next) to NULL.
 *
 * Each segment, then, will have to be freed individually!
 *
 */

static t_list	*extract_map_segment(t_list *file)
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
			if (prev != NULL)
			{
				file = prev->next;
				prev->next = NULL;
			}
			break ;
		}
		prev = file;
		file = file->next;
	}
	return (file);
}

static t_list	*extract_info_segment(t_list *file)
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
