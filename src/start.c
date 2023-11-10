/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:12:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/09 16:56:56 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	load_game(t_game *game);
static int	start_game(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || *argv[1] == '\0')
		return (EXIT_FAILURE);
	else if (ft_strcmp(argv[1], "-v") == 0)
		return (ft_printf("%s: %s\n", EXEC_NAME, VERSION), EXIT_SUCCESS);
	if (ft_strlen(argv[1]) >= _POSIX_PATH_MAX)
		return (ft_fprintf(stderr, "%s: %s\n", EXEC_NAME,
				strerror(ENAMETOOLONG)), EXIT_FAILURE + 1);
	if (ft_endswith(argv[1], MAP_EXT) == EXIT_FAILURE)
		return (ft_fprintf(stderr, "%s: %s\n", EXEC_NAME,
				"Invalid file extension"), EXIT_FAILURE + 2);
	game.mlx = NULL;
	game.mlx_window = NULL;
	game.map = NULL;
	game.key.up_w = 0;
	game.key.down_s = 0;
	game.key.left_a = 0;
	game.key.right_d = 0;
	game.key.sprint = 0;
	game.map_filename_ptr = argv[1];
	if (load_game(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE + 3);
	return (start_game(&game));
}

static int	load_game(t_game *game)
{
	t_list	*file;

	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->i_north.image_file = NULL;
	game->i_south.image_file = NULL;
	game->i_west.image_file = NULL;
	game->i_east.image_file = NULL;
	file = read_file(game->map_filename_ptr);
	if (file == NULL && errno == 0)
		return (ft_fprintf(stderr, "%s: %s: File is empty\n", EXEC_NAME,
				game->map_filename_ptr), EXIT_FAILURE);
	else if (file == NULL && errno != 0)
		return (ft_fprintf(stderr, "%s: %s: %s\n", EXEC_NAME,
				game->map_filename_ptr, strerror(errno)), EXIT_FAILURE);
	else if (ft_load_map(file, game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	start_game(t_game *game)
{
	t_imgdata	*img;

	img = &game->i_main_frame;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (EXIT_FAILURE);
	else if (ft_load_textures(game) == EXIT_FAILURE)
		return (mlx_destroy_font(game->mlx), EXIT_FAILURE);
	game->mlx_window = mlx_new_window(game->mlx,
			game->win_width, game->win_height, EXEC_NAME);
	mlx_hook(game->mlx_window, ON_DESTROY, 0, &ft_destroy, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, 0, &ft_keydown, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYUP, 0, &ft_keyup, (void *) game);
	mlx_hook(game->mlx_window, ON_MOUSEMOVE, 0, &ft_mouse, (void *) game);
	mlx_hook(game->mlx_window, ON_RESIZE, 0, &ft_resize_win, (void *)game);
	img->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	img->address = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	mlx_loop_hook(game->mlx, &ft_render, (void *) game);
	mlx_mouse_hide();
	mlx_do_key_autorepeaton(game->mlx);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
