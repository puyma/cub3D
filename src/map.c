/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:50:47 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/03 16:56:06 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_print_map(t_list *list);

t_list	*ft_read_map(int fd)
{
	t_list	*list;
	char	*line;
	char	*trimmed;

	list = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	trimmed = ft_strtrim(line, "\n");
	list = ft_lstnew((void *) trimmed);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, "\n");
		ft_lstadd_back(&list, ft_lstnew((void *) trimmed));
		free(line);
		line = get_next_line(fd);
	}
	return (list);
}

int	ft_load_map(t_list *map, t_data *data)
{
	(void) map;
	(void) data;
	return (EXIT_SUCCESS);
}

void	ft_print_map(t_list *list)
{
	while (list != NULL)
	{
		ft_printf("%s\n", (char *) list->content);
		list = list->next;
	}
}
