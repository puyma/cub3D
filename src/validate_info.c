/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/14 18:04:28 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "_debug.h"

int	is_allowed(char **allowed, char *str)
{
	while (*allowed != NULL)
	{
		if (ft_strncmp(*allowed, str, ft_strlen(*allowed)) == 0)
			return (EXIT_SUCCESS);
		++allowed;
	}
	return (EXIT_FAILURE);
}

int	one_of_each(char **allowed, t_list *info_lst)
{
	int	counter;

	while (*allowed != NULL)
	{
		counter = 0;
		(void) info_lst;
		// check for repeated
		++allowed;
	}
	return (EXIT_FAILURE);
}

int	validate_info(t_list *info_lst)
{
	const char	*allowed[] = {"NO ", "SO ", "EA ", "WE ", "F ", "C ", NULL};
	char		*str;

	while (info_lst != NULL)
	{
		str = info_lst->content;
		ft_striteri(str, &ft_replace_isspace);
		if (str != NULL && *str != '#' && *str != '\0' && ft_isspace(*str) == 0
			&& is_allowed((char **) allowed, str) == EXIT_FAILURE)
			exit(EXIT_FAILURE + 4);
		info_lst = info_lst->next;
	}
	if (one_of_each((char **) allowed, info_lst) == EXIT_FAILURE)
		exit(EXIT_FAILURE + 5);
	return (EXIT_SUCCESS);
}
