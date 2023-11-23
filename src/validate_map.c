/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 17:31:15 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	validate_line(char *str);
static int	validate_line_content(char *line);
static int	validate_characters(char *line);

// WIP:
// check no characters outside of map "block"
//
// WIP:
// remove empty lines at the end of the file

int	validate_map(t_map *map, t_player *player)
{
	t_list	*map_lst;
	int		lst_size;

	map_lst = map->map_segment;
	lst_size = ft_lstwidth(map_lst);
	if (lst_size < 3 || ft_lstheight(map_lst) < 3)
		return (EXIT_FAILURE);
	while (map_lst != NULL)
	{
		if (validate_line(map_lst->content))
			return (EXIT_FAILURE);
		map_lst = map_lst->next;
	}
	if (check_player(map->map_segment) || check_player_edge(map, player)
		|| validate_walls(map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_line(char *str)
{
	if (validate_characters(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (validate_line_content(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_line_content(char *line)
{
	char	*start;
	char	*end;

	start = ft_strchr(line, '1');
	end = ft_strrchr(line, '1');
	if (start == NULL)
		return (EXIT_FAILURE);
	while (start != end)
	{
		++start;
		if (*start != '0' && *start != '1' && *start != ' '
			&& ft_strchr("NSEW", *start) == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
 * validate_characters
 * check map characters
 *
 */

int	validate_characters(char *line)
{
	while (*line != '\0')
	{
		if (*line != '1' && *line != '0')
		{
			if (ft_strchr("NSEW", *line) == NULL
				&& !ft_isspace(*line))
				return (EXIT_FAILURE);
		}
		++line;
	}
	return (EXIT_SUCCESS);
}
