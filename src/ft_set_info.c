/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:00:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/13 09:35:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_set_info_value_path(char *values, t_game *game);
static int	ft_set_info_value_color(char *values, t_game *game);
static int	ft_fill_map(t_list *map_lst, t_map *map);

int	ft_set_info(t_list *info, t_game *game)
{
	char	*ln;
	size_t	i;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	i = 0;
	while (info != NULL && exit_status == EXIT_SUCCESS && ++i)
	{
		ln = (char *) info->content;
		ft_striteri(ln, &ft_replace_isspace);
		if (ft_strncmp("NO ", ln, 3) == 0 || ft_strncmp("SO ", ln, 3) == 0
			|| ft_strncmp("EA ", ln, 3) == 0 || ft_strncmp("WE ", ln, 3) == 0)
			exit_status = ft_set_info_value_path(ln, game);
		else if (ft_strncmp("F ", ln, 2) == 0 || ft_strncmp("P ", ln, 2) == 0)
			exit_status = ft_set_info_value_color(ln, game);
		else if (*ln != '#' && *ln != '\0')
			exit_status = EXIT_FAILURE;
		info = info->next;
	}
	if (exit_status == EXIT_FAILURE)
		return (ft_fprintf(stderr, "%s: %s: line %d: %s\n", EXEC_NAME,
				game->map_filename_ptr, i, "invalid value e"), EXIT_FAILURE);
	return (exit_status);
}

static int	ft_set_info_value_path(char *s, t_game *game)
{
	static int	i = 0;
	char		**values;

	values = ft_split(s, 040);
	if (ft_arrlen(values) != 2)
		return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}

static int	ft_set_info_value_color(char *s, t_game *game)
{
	int		exit_status;
	char	**values;
	char	**color_values;

	exit_status = EXIT_SUCCESS;
	ft_striteri(s, &ft_replace_ispunct);
	values = ft_split(s, 040);
	if (ft_arrlen(values) != 4)
		return (EXIT_FAILURE);
	color_values = values + 1;
	if (color_values == NULL || ft_arrlen(color_values) != 3)
		exit_status = EXIT_FAILURE;
	if (ft_strcmp("F", values[0]) == 0
		&& ft_set_rgb_color(color_values, &game->f_color) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE;
	else if (ft_strcmp("P", values[0]) == 0
		&& ft_set_rgb_color(color_values, &game->p_color) == EXIT_FAILURE)
		exit_status = EXIT_FAILURE;
	return (exit_status);
}

int	ft_set_board(t_list *map_lst, t_game *game)
{
	size_t	i;

	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL)
		return (EXIT_FAILURE);
	game->map->width = ft_lstwidth(map_lst);
	game->map->height = ft_lstheight(map_lst);
	game->map->board = (int **) ft_calloc(game->map->width, sizeof(int *));
	if (game->map->board == NULL)
		return (free(game->map), EXIT_FAILURE);
	i = 0;
	while (i < game->map->width)
		game->map->board[i++] = ft_calloc(game->map->height, sizeof(int));
	if (ft_fill_map(map_lst, game->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_fill_map(t_list *map_lst, t_map *map)
{
	char	*str;
	size_t	x;
	size_t	y;

	y = 0;
	while (map_lst != NULL)
	{
		x = 0;
		str = map_lst->content;
		while (x < map->width && str[x] != '\0')
		{
			if (ft_strchr(C_ALLOWED, str[x]) != NULL || str[x] == '1')
				map->board[x][y] = str[x];
			++x;
		}
		++y;
		map_lst = map_lst->next;
	}
	return (EXIT_SUCCESS);
}
