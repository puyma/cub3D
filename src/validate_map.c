/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/16 13:28:05 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_line(char *str, int position, int size);
int	validate_line_content(char *line, int position, int lst_size);
int	validate_characters(char *line);

//check theres only one player (at least)
//check theres one line for each NO SO EA WE F C

int	validate_map(t_map *map)
{
	t_list	*map_lst;
	int		position;
	int		lst_size;

	map_lst = map->map_segment;
	position = 0;
	lst_size = ft_lstwidth(map_lst);
	if (lst_size < 3 || ft_lstheight(map_lst) < 3)
		return (EXIT_FAILURE);
	while (map_lst != NULL)
	{
		if (validate_line(map_lst->content, position, lst_size))
			return (EXIT_FAILURE);
		++position;
		map_lst = map_lst->next;
	}
	return (EXIT_SUCCESS);
}

int	validate_line(char *str, int position, int lst_size)
{
	if (validate_characters(str) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (validate_line_content(str, position, lst_size) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	(void) position;
	return (EXIT_SUCCESS);
}

int	validate_line_content(char *line, int position, int lst_size)
{
	char	*start;
	char	*end;

	start = ft_strchr(line, '1');
	end = ft_strrchr(line, '1');
	if (start == NULL || start == end)
		return (EXIT_FAILURE);
	while (start != end)
	{
		++start;
		if (*start != '0' && *start != '1'
			&& ft_strchr("NSEW", *start) == NULL)
			return (EXIT_FAILURE);
	}
	(void) position;
	(void) lst_size;
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
		if (*line != '1' && *line != '0'
			&& ft_strchr("NSEW", *line) == NULL)
			return (EXIT_FAILURE);
		++line;
	}
	return (EXIT_SUCCESS);
}
