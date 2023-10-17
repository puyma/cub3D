/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:00:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/17 14:04:08 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_set_info_value_path(char *values, t_game *game);
static int	ft_set_info_value_color(char *values, t_game *game);

int	ft_set_info(t_list *info, t_game *game)
{
	char	*ln;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	game->tmp_counter = 0;
	while (exit_status == EXIT_SUCCESS && info != NULL && ++(game->tmp_counter))
	{
		ln = (char *) info->content;
		ft_striteri(ln, &ft_replace_isspace);
		if (ft_strncmp("NO ", ln, 3) == 0 || ft_strncmp("SO ", ln, 3) == 0
			|| ft_strncmp("EA ", ln, 3) == 0 || ft_strncmp("WE ", ln, 3) == 0)
			exit_status = ft_set_info_value_path(ln, game);
		else if (ft_strncmp("F ", ln, 2) == 0 || ft_strncmp("C ", ln, 2) == 0)
			exit_status = ft_set_info_value_color(ln, game);
		else if (*ln != '#' && *ln != '\0')
			exit_status = EXIT_FAILURE;
		info = info->next;
	}
	if (exit_status == EXIT_FAILURE)
		return (ft_fprintf(stderr, "%s: %s: line %d: %s\n", EXEC_NAME,
				game->map_filename_ptr, game->tmp_counter, "invalid value"),
			EXIT_FAILURE);
	return (exit_status);
}

static int	ft_set_info_value_path(char *s, t_game *game)
{
	static int	i = 0;
	char		**values;

	values = ft_split(s, 040);
	if (values == NULL)
		return (EXIT_FAILURE);
	if (ft_arrlen(values) != 2)
		return (ft_free_arr(values), EXIT_FAILURE);
	if (ft_strcmp("NO", values[0]) == 0)
		game->i_north.path_to_image_file = ft_strdup(values[1]);
	else if (ft_strcmp("SO", values[0]) == 0)
		game->i_south.path_to_image_file = ft_strdup(values[1]);
	else if (ft_strcmp("WE", values[0]) == 0)
		game->i_west.path_to_image_file = ft_strdup(values[1]);
	else if (ft_strcmp("EA", values[0]) == 0)
		game->i_east.path_to_image_file = ft_strdup(values[1]);
	game->i_load_cueue[i] = *(values[0]);
	++i;
	return (ft_free_arr(values), EXIT_SUCCESS);
}

static int	ft_set_info_value_color(char *s, t_game *game)
{
	int		exit_status;
	char	**values;
	char	**color_values;

	exit_status = EXIT_SUCCESS;
	ft_striteri(s, &ft_replace_ispunct);
	values = ft_split(s, 040);
	if (values == NULL)
		return (EXIT_FAILURE);
	if (ft_arrlen(values) != 4)
		return (ft_free_arr(values), EXIT_FAILURE);
	color_values = values + 1;
	if (color_values == NULL || ft_arrlen(color_values) != 3)
		return (ft_free_arr(values), EXIT_FAILURE);
	if (ft_strcmp("F", values[0]) == 0
		&& ft_set_rgb_color(color_values, &game->f_color) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE;
	else if (ft_strcmp("C", values[0]) == 0
		&& ft_set_rgb_color(color_values, &game->p_color) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE;
	return (ft_free_arr(values), exit_status);
}
