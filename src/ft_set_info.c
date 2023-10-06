/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:00:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/06 18:35:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_set_info_values(char *line, t_game *game);

int	ft_set_info(t_list *info, t_game *game)
{
	char	*line;

	while (info != NULL)
	{
		line = info->content;
		if (ft_strchr(C_ALLOWED, *line) == NULL && *line != '#' && *line != 0)
			return (ft_fprintf(stderr, "SHIT MAP\n"), EXIT_FAILURE);
		else if (ft_strchr(C_ALLOWED, *line) != NULL && *line != '\0'
			&& ft_set_info_values(line, game) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		info = info->next;
	}
	return (EXIT_SUCCESS);
}

size_t	ft_arrlen(char **arr)
{
	size_t	len;

	len = 0;
	while (arr && arr[len])
		++len;
	return (len);
}

static int	ft_set_info_values(char *line, t_game *game)
{
	char	**values;

	ft_striteri(line, &ft_replace_isspace);
	values = ft_split(line, 040);
	
	PRINT_ARRAY(values);
	if (ft_strcmp("NO", values[0]) == 0)
		ft_printf("will set NO with: %s\n", values[1]);
	else if (ft_strcmp("EA", values[0]) == 0)
		ft_printf("will set EA: %s\n", values[1]);
	else if (ft_strcmp("WE", values[0]) == 0)
		ft_printf("will set WE: %s\n", values[1]);
	else if (ft_strcmp("SO", values[0]) == 0)
		ft_printf("will set SO: %s\n", values[1]);
	else
		ft_printf("other: %s\n", values[0]);

	(void) game;
	exit(0);
	return (EXIT_SUCCESS);
}
