d/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:33:58 by mpuig-ma          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/24 02:47:12 by jsebasti         ###   ########.fr       */
=======
/*   Updated: 2023/10/26 17:27:45 by mpuig-ma         ###   ########.fr       */
>>>>>>> puyma-minimap
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
static int	ft_render(t_game *game)
{
	t_render	render;

	render.x = 0;
	render.player = game->player;
	while (render.x < WIN_WIDTH)
	{
		init_render_vars(&render.player, &render.ray, render.x);
		find_dist_to_edge(&render.player, &render.ray);
		find_colission(game, &render.ray);
		render.ray.perpwalldist = get_dist(&render.player, &render.ray);
		ft_draw(game, &render, (int)(WIN_HEIGHT / render.ray.perpwalldist), \
		get_x_coord(&render.player, &render.ray));
		++render.x;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->img.img, 0, 0);
	return (EXIT_SUCCESS);
}
=======
/* This function loads the game's images and graphic stuff.
 * This includes initializing mlx, mlx's events,
 * calling mlx_loop, etc. */
>>>>>>> puyma-minimap

int	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (EXIT_FAILURE);
	if (ft_load_textures(game) == EXIT_FAILURE)
		return (mlx_destroy_font(game->mlx), EXIT_FAILURE);
	game->mlx_window = mlx_new_window(game->mlx,
			game->win_width, game->win_height, WIN_NAME);
	ft_set_textures(game);
	ft_set_up_playe(game->player, )
	mlx_hook(game->mlx_window, ON_DESTROY, 0, &ft_destroy, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, 0, &ft_keycode, (void *) game);
<<<<<<< HEAD
	mlx_mouse_hide();
	mlx_loop_hook(game->mlx, ft_render, game);
=======
	mlx_hook(game->mlx_window, ON_MOUSEMOVE, 0, &ft_mouse, (void *) game);
	mlx_loop_hook(game->mlx, &ft_render, (void *) game);
	PRINT_MAP(game->map)
	ft_rays(game);
>>>>>>> puyma-minimap
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
