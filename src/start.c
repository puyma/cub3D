/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 15:36:49 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_arguments(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	check_arguments(argc, argv);
	if (parse_map(&game, &game.map, argv[1]))
		return (clean(&game), EXIT_FAILURE);
	if (load_window(&game) == EXIT_FAILURE
		|| load_textures(&game) == EXIT_FAILURE)
	{
		ft_fprintf(stderr, "%s: %s: error loading window/textures\n",
			EXEC_NAME, argv[1]);
		return (clean(&game), EXIT_FAILURE);
	}
	mlx_loop(game.mlx);
	return (clean(&game), EXIT_SUCCESS);
}

static void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_fprintf(stderr, "Error\nusage: ./%s map_file.cub\n", EXEC_NAME);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		ft_printf("%s: %s\n",
			EXEC_NAME, VERSION);
		exit(EXIT_SUCCESS);
	}
	if (ft_strlen(argv[1]) >= _POSIX_PATH_MAX)
	{
		ft_fprintf(stderr, "Error\n%s: %s\n",
			EXEC_NAME, strerror(ENAMETOOLONG));
		exit(EXIT_FAILURE);
	}
	if (ft_endswith(argv[1], MAP_EXT) == EXIT_FAILURE)
	{
		ft_fprintf(stderr, "Error\n%s: %s\n",
			EXEC_NAME, "Invalid file extension");
		exit(EXIT_FAILURE);
	}
}
