/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_segments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:17:21 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 17:18:06 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

t_list	*ft_extract_info_segment(t_list *file)
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
