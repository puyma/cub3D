/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/03 16:55:35 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_init_main(int argc, char **argv);
static int	ft_init_data(t_data *data, char **argv);

int	main(int argc, char **argv)
{
	t_data	data;

	// check arguments
	if (ft_init_main(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// load map && data values
	if (ft_init_data(&data, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (errno || EXIT_SUCCESS);
}

static int	ft_init_main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	// print version
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		ft_printf("%s: %s\n", EXEC_NAME, VERSION);
		exit(EXIT_SUCCESS);
	}
	// check for file name length
	if (*argv[1] == '\0' || ft_strlen(argv[1]) >= _POSIX_PATH_MAX)
		return (ft_fprintf(stderr, "%s: %s\n",
				EXEC_NAME, "File name too long"), EXIT_FAILURE);
	// check for file name's extension
	if (ft_endswith(argv[1], MAP_EXT) == EXIT_FAILURE)
		return (ft_fprintf(stderr, "%s: %s\n",
				EXEC_NAME, "Invalid file name extension"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_init_data(t_data *data, char **argv)
{
	int		map_fd;
	t_list	*map;

	// open map
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		return (ft_fprintf(stderr, "%s: %s: %s\n",
				EXEC_NAME, argv[1], strerror(errno)), EXIT_FAILURE);	
	// read map
	map = ft_read_map(map_fd);
	if (map == NULL)
		return (EXIT_FAILURE);
	// load map details
	if (ft_load_map(map, data) == EXIT_FAILURE)
		return (ft_lstclear(&map, &free), EXIT_SUCCESS);
	ft_lstclear(&map, &free);	
	// load data
	return (EXIT_SUCCESS);
}
