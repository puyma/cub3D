/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:50:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/04 18:41:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//static void		ft_set_map_detail(char *line, t_data *data);

/*
** The map must be composed of only 6 possible characters: 
**  0 for an empty space, 
**  1 for a wall, 
**  and N,S,E or W for the player’s start position 
**  and spawning orientation.
**
** Except for the map content, each type of element 
** can be separated by one or more empty line(s).
**
** Except for the map content which always has to be the last, 
** each type of element can be set in any order in the file.
**
** Except for the map, each type of information from an element 
** can be separated by one or more space(s).
*/

// prev should not be NULL, map should not start directly with '0' or '1'

int	ft_load_map(t_list *file, t_data *data)
{
	size_t	line_num;
	char	*line;
	t_list	*prev;

	line_num = 1;
	prev = NULL;
	while (file != NULL)
	{
		line = file->content;
		++line_num;
		if (*line == '0' || *line == '1')
		{
			file = prev->next;
			prev->next = NULL;
			break ;
		}
		//if (func() == EXIT_FAILURE)
		//	return (EXIT_FAILURE);
		prev = file;
		file = file->next;
	}
	(void) data;
	return (EXIT_SUCCESS);
}

/*
int	ft_load_map(t_list *file, t_data *data)
{
	size_t	line_num;
	char	*line;

	line_num = 1;
	file = ft_load_map_details(file, data, &line_num);
	if (file == NULL)
		return (EXIT_FAILURE);
	while (file != NULL)
	{
		line = file->content;
		if (ft_strchr(C_ALLOWED, *line) == NULL && *line != '#' && ft_isspace(*line) == 0)
			return (ft_fprintf(stderr, "%s: %s\n",
					EXEC_NAME, "Invalid map"), EXIT_FAILURE);
		else
		{
			data->map
			ft_printf("%u. OK (map): %s\n", line_num, line);
		}
		++line_num;
		file = file->next;
	}
	return (EXIT_SUCCESS);
}
*/

/*
** DESCRIPTION
** Loads map info into t_data.
**
** RETURN VALUE
** Returns pointer to where map (board) starts.
*/
