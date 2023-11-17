/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/17 12:16:18 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	validate_line(char *str, int position, int size);
static int	validate_line_content(char *line, int position, int lst_size);
static int	validate_characters(char *line);
static int	check_player(t_list *map_lst);

// WIP:
// check no characters outside of map "block"
//
// WIP:
// remove empty lines at the end of the file

int	validate_map(t_map *map)
{
	t_list	*map_lst;
	int		position;
	int		lst_size;

	printf("validate_map\n");
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
	if (check_player(map->map_segment))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	validate_line(char *str, int position, int lst_size)
{
	printf("validate_line\n");
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

	printf("validate_line_content\n");
	start = ft_strchr(line, '1');
	end = ft_strrchr(line, '1');
	if (start == NULL)
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
	printf("validate_characters\n");
	while (*line != '\0')
	{
		if (*line != '1' && *line != '0')
		{
			if (ft_strchr("NSEW ", *line) == NULL)
				return (EXIT_FAILURE);
		}
		++line;
	}
	return (EXIT_SUCCESS);
}

//check theres only one player (at least)
static int	check_player(t_list *map_lst)
{
	char	*str;
	int		counter;

	counter = 0;
	while (map_lst != NULL)
	{
		str = map_lst->content;
		while (*str != '\0')
		{
			if (ft_strchr("NSEW", *str) != NULL)
				++counter;
			++str;
		}
		map_lst = map_lst->next;
	}
	if (counter != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
