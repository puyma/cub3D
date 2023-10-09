/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:00:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/09 16:04:33 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_set_info_values(char *line, t_game *game);
static int	ft_set_info_value_path(char **value, t_game *game);
static int	ft_set_info_value_color(char **values, t_game *game);

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
		{
			ft_fprintf(stderr, "Error (to be managed(message-wise))\n");
			return (EXIT_FAILURE);
		}
		info = info->next;
	}
	return (EXIT_SUCCESS);
}

static int	ft_set_info_values(char *line, t_game *game)
{
	int		exit_status;
	char	**values;

	exit_status = EXIT_SUCCESS;
	ft_striteri(line, &ft_replace_isspace);
	ft_striteri(line, &ft_replace_ispunct);
	values = ft_split(line, 040);
	if (ft_strcmp("NO", values[0]) == 0
		|| ft_strcmp("EA", values[0]) == 0
		|| ft_strcmp("WE", values[0]) == 0
		|| ft_strcmp("SO", values[0]) == 0)
		exit_status = ft_set_info_value_path(values, game);
	else if (ft_strcmp("F", values[0]) == 0 || ft_strcmp("P", values[0]) == 0)
		exit_status = ft_set_info_value_color(values, game);
	else
		ft_fprintf(stderr, "other: %s\n", values[0]);
	ft_free_arr(values);
	return (exit_status);
}

static int	ft_set_info_value_path(char **values, t_game *game)
{
	if (values == NULL || values[0] == NULL
		|| values[1] == NULL || values[2] != NULL)
		return (ft_fprintf(stderr, "Invalid value\n"), EXIT_FAILURE);
	if (ft_strcmp("NO", values[0]) == 0)
		game->i_north.path_to_image_file = ft_strdup(values[1]);
	else if (ft_strcmp("SO", values[0]) == 0)
		game->i_south.path_to_image_file = ft_strdup(values[1]);
	else if (ft_strcmp("WE", values[0]) == 0)
		game->i_west.path_to_image_file = ft_strdup(values[1]);
	else if (ft_strcmp("EA", values[0]) == 0)
		game->i_east.path_to_image_file = ft_strdup(values[1]);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_set_info_value_color(char **values, t_game *game)
{
	char	**color_values;

	color_values = values + 1;
	if (color_values == NULL || ft_arrlen(color_values) != 3)
		return (ft_fprintf(stderr, "1\n"), EXIT_FAILURE);
	if (ft_strcmp("F", values[0]) == 0
		&& ft_set_rgb_color(color_values, &game->f_color) == EXIT_FAILURE)
		return (ft_fprintf(stderr, "2\n"), EXIT_FAILURE);
	else if (ft_strcmp("P", values[0]) == 0
		&& ft_set_rgb_color(color_values, &game->p_color) == EXIT_FAILURE)
		return (ft_fprintf(stderr, "3\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
