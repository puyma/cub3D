/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:12:37 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/03 20:28:24 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		ft_lstheight(t_list *list)
{
	int		len;

	len = 0;
	while (list != NULL)
	{
		++len;
		list = list->next;
	}
	return (len);
}

int		ft_lstwidth(t_list *list)
{
	int		len;
	int		line_len;
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
