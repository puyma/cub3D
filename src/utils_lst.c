/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:12:37 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/05 16:12:46 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_lstheight(t_list *list)
{
	size_t	len;

	len = 0;
	while (list != NULL)
	{
		++len;
		list = list->next;
	}
	return (len);
}

size_t	ft_lstwidth(t_list *list)
{
	size_t	len;
	size_t	line_len;
	char	*line;

	len = 0;
	while (list != NULL)
	{
		line = (char *) list->content;
		line_len = ft_strlen(line);
		if (len < line_len)
			len = line_len;
		list = list->next;
	}
	return (len);
}
