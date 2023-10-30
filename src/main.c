/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:24 by mpuig-ma          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/18 16:09:58 by jsebasti         ###   ########.fr       */
=======
/*   Updated: 2023/10/17 17:51:33 by mpuig-ma         ###   ########.fr       */
>>>>>>> puyma-minimap
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int		ft_check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_game	game;
	t_list	*file;

	if (ft_check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game.mlx = NULL;
	game.mlx_window = NULL;
	game.win_width = WIN_WIDTH;
	game.win_height = WIN_HEIGHT;
	game.map = NULL;
	game.map_filename_ptr = argv[1];
	game.i_north.path_to_image_file = NULL;
	game.i_south.path_to_image_file = NULL;
	game.i_west.path_to_image_file = NULL;
	game.i_east.path_to_image_file = NULL;
	file = ft_read_file(game.map_filename_ptr);
	if (file == NULL)
		return (EXIT_FAILURE + 1);
	if (ft_load_map(file, &game) == EXIT_FAILURE)
		return (ft_clean(&game), EXIT_FAILURE + 2);
	if (ft_start_game(&game) == EXIT_FAILURE)
		return (ft_clean(&game), EXIT_FAILURE + 3);
	return (ft_clean(&game), EXIT_SUCCESS);
}

static int	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		ft_printf("%s: %s\n", EXEC_NAME, VERSION);
		exit(EXIT_SUCCESS);
	}
	if (*argv[1] == '\0' || ft_strlen(argv[1]) >= _POSIX_PATH_MAX)
	{
		ft_fprintf(stderr, "%s: %s\n", EXEC_NAME, "File name too long");
		return (EXIT_FAILURE);
	}
	if (ft_endswith(argv[1], MAP_EXT) == EXIT_FAILURE)
	{
		ft_fprintf(stderr, "%s: %s\n", EXEC_NAME, "Invalid file extension");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_clean(t_game *game)
{
	size_t	counter;

	if (game->i_north.path_to_image_file != NULL)
		free(game->i_north.path_to_image_file);
	if (game->i_south.path_to_image_file != NULL)
		free(game->i_south.path_to_image_file);
	if (game->i_west.path_to_image_file != NULL)
		free(game->i_west.path_to_image_file);
	if (game->i_east.path_to_image_file != NULL)
		free(game->i_east.path_to_image_file);
	if (game->mlx != NULL)
		free(game->mlx);
	if (game->mlx_window != NULL)
		mlx_destroy_window(game->mlx, game->mlx_window);
	if (game->map != NULL)
	{
		counter = game->map->width;
		while (counter-- > 0)
			free(game->map->board[counter]);
		free(game->map->board);
		free(game->map);
	}
}
