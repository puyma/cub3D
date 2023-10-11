/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/11 15:04:48 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_game	game;

	if (ft_check_args(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game.map_filename_ptr = argv[1];
	if (ft_load_game(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE + 1);
	if (ft_start_game(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE + 2);
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
