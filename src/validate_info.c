/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/16 12:48:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_allowed(char **allowed, char *str);
static int	is_repeated(char **allowed, t_list *info_lst);

int	validate_info(t_map *map)
{
	const char	*allowed[] = {"NO ", "SO ", "EA ", "WE ", "F ", "C ", NULL};
	char		*str;
	t_list		*lst_cpy;
	t_list		*info_lst;

	info_lst = map->info_segment;
	lst_cpy = info_lst;
	while (info_lst != NULL)
	{
		str = info_lst->content;
		ft_striteri(str, &ft_replace_isspace);
		if (str != NULL && *str != '#' && *str != '\0' && ft_isspace(*str) == 0
			&& is_allowed((char **) allowed, str) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		info_lst = info_lst->next;
	}
	if (is_repeated((char **) allowed, lst_cpy) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	is_allowed(char **allowed, char *str)
{
	while (*allowed != NULL)
	{
		if (ft_strncmp(*allowed, str, ft_strlen(*allowed)) == 0)
			return (EXIT_SUCCESS);
		++allowed;
	}
	return (EXIT_FAILURE);
}

static int	is_repeated(char **allowed, t_list *info_lst)
{
	int		counter;
	t_list	*lst;

	while (*allowed != NULL)
	{
		counter = 0;
		lst = info_lst;
		while (lst != NULL)
		{
			if (ft_strncmp(*allowed, lst->content, ft_strlen(*allowed)) == 0)
				++counter;
			lst = lst->next;
		}
		if (counter > 1)
			return (EXIT_FAILURE);
		++allowed;
	}
	return (EXIT_SUCCESS);
}
