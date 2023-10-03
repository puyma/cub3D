/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/03 12:14:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_init_main(int argc, char **argv);
static int	ft_init_data(t_data *data, char **argv);

int	main(int argc, char **argv)
{
	t_data data;

	if (ft_init_main(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
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
		return (ft_printf("%s: %s\n", EXEC_NAME, VERSION), EXIT_SUCCESS);
	// check for file name length
	if (*argv[1] == '\0' || ft_strlen(argv[1]) >= _POSIX_PATH_MAX)
		return (ft_fprintf(stderr, "%s: %s\n",
					EXEC_NAME, "file name too long"), EXIT_FAILURE);
	// check for file name's extension
	if (ft_endswith(argv[1], MAP_EXT) == EXIT_FAILURE)
		return(ft_fprintf(stderr, "%s: %s\n",
					EXEC_NAME, "invalid file name extension"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_init_data(t_data *data, char **argv)
{
	(void) data;
	(void) argv;
	return (EXIT_SUCCESS);
}
