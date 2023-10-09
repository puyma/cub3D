/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:40:00 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/04 15:57:08 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
** DESCRIPTION
** The function ft_read_file(int) reads each line from 
** a file descriptor and stores it in a t_list.
**
** RETURN VALUE
** Returns a pointer to the allocated t_list. 
*/

t_list	*ft_read_file(int fd)
{
	t_list	*list;
	char	*line;
	char	*trimmed;

	list = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		if (list == NULL)
			list = ft_lstnew((void *) trimmed);
		else
			ft_lstadd_back(&list, ft_lstnew((void *) trimmed));
		free(line);
		line = get_next_line(fd);
	}
	return (list);
}
