/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:15:26 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/16 18:28:39 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_allowed(char **allowed, char *str);
static int	check_repeated(char **allowed, t_list *info_lst);
static int	validate_colors(char **cc, t_list *info_lst);
static int	validate_images(char **ii, t_list *info_lst);

int	validate_info(t_map *map)
{
	const char	*cc[] = {"F ", "C ", NULL};
	const char	*ii[] = {"NO ", "SO ", "EA ", "WE ", NULL};
	t_list		*tmp;

	tmp = map->info_segment;
	while (tmp != NULL)
	{
		ft_striteri(tmp->content, &ft_replace_isspace);
		if (is_allowed((char **) cc, tmp->content) == EXIT_FAILURE
			&& is_allowed((char **) ii, tmp->content) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	if (check_repeated((char **) cc, map->info_segment)
		|| check_repeated((char **) ii, map->info_segment))
		return (EXIT_FAILURE);
	if (validate_colors((char **) cc, map->info_segment))
		return (EXIT_FAILURE);
	if (validate_images((char **) ii, map->info_segment))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	is_allowed(char **allowed, char *str)
{
	while (*allowed != NULL)
	{
		if (*str == '#' || *str == '\0'
			|| ft_strncmp(*allowed, str, ft_strlen(*allowed)) == 0)
			return (EXIT_SUCCESS);
		++allowed;
	}
	return (EXIT_FAILURE);
}

//check theres one line for each NO SO EA WE F C
static int	check_repeated(char **values, t_list *src_list)
{
	t_list	*lst;
	char	*str;
	int		counter;

	while (*values != NULL)
	{
		lst = src_list;
		counter = 0;
		while (lst != NULL)
		{
			str = lst->content;
			if (ft_strncmp(*values, str, ft_strlen(*values)) == 0)
				++counter;
			lst = lst->next;
		}
		if (counter != 1)
			return (EXIT_FAILURE);
		++values;
	}
	return (EXIT_SUCCESS);
}

/* 
 * call check_rgb_color for each color
 *
 */

static int	validate_colors(char **cc, t_list *src_list)
{
	t_list	*lst;

	while (*cc != NULL)
	{
		lst = src_list;
		while (lst != NULL)
		{
			if (ft_strncmp(*cc, lst->content, ft_strlen(*cc)) == 0)
			{
				ft_striteri(lst->content, &ft_replace_ispunct);
				if (check_rgb_color(lst->content) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			lst = lst->next;
		}
		++cc;
	}
	return (EXIT_SUCCESS);
}

/* 
 * resolve image path here
 *
 */

static int	validate_images(char **ii, t_list *src_list)
{
	t_list	*lst;

	while (*ii != NULL)
	{
		lst = src_list;
		while (lst != NULL)
		{
			if (ft_strncmp(*ii, lst->content, ft_strlen(*ii)) == 0)
			{
				if (check_texture(lst->content) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			lst = lst->next;
		}
		++ii;
	}
	return (EXIT_SUCCESS);
}
