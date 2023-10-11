/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/11 09:44:10 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_init_main(int argc, char **argv);
static int	ft_init_t_game(t_game *game, char **argv);

int	main(int argc, char **argv)
{
	t_game	game;

	game.map_filename_ptr = argv[1];
	if (ft_init_main(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_init_t_game(&game, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_load_game(&game) == EXIT_FAILURE)
	{
		ft_fprintf(stderr, "Error ft_load_game()\n");
		return (ft_clean(&game), EXIT_FAILURE);
	}
	printf("here\n");
	ft_clean(&game);
	return (EXIT_SUCCESS);
}

static int	ft_init_main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		ft_printf("%s: %s\n", EXEC_NAME, VERSION);
		exit(EXIT_SUCCESS);
	}
	if (*argv[1] == '\0' || ft_strlen(argv[1]) >= _POSIX_PATH_MAX)
		return (ft_fprintf(stderr, "%s: %s\n",
				EXEC_NAME, "File name too long"), EXIT_FAILURE);
	if (ft_endswith(argv[1], MAP_EXT) == EXIT_FAILURE)
		return (ft_fprintf(stderr, "%s: %s\n",
				EXEC_NAME, "Invalid file name extension"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_init_t_game(t_game *game, char **argv)
{
	int		fd;
	t_list	*file;

	game->i_load_cueue = NULL;
	game->mlx = NULL;
	game->mlx_window = NULL;
	game->map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_fprintf(stderr, "%s: %s: %s\n",
				EXEC_NAME, argv[1], strerror(errno)), EXIT_FAILURE);
	file = ft_read_file(fd);
	if (file == NULL)
		return (EXIT_FAILURE);
	if (ft_load_map(file, game) == EXIT_FAILURE)
		return (ft_clean_map(game->map), EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}
