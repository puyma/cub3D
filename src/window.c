/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:17:06 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/14 13:24:00 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_window(t_game *game)
{
	t_imgdata	*img;

	img = &game->i_main_frame;
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (EXIT_FAILURE);
	game->mlx_window = mlx_new_window(game->mlx,
			game->win_width, game->win_height, EXEC_NAME);
	img->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	img->address = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	mlx_hook(game->mlx_window, ON_DESTROY, 0, &ft_destroy, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, 0, &ft_keydown, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYUP, 0, &ft_keyup, (void *) game);
	mlx_hook(game->mlx_window, ON_MOUSEMOVE, 0, &ft_mouse, (void *) game);
	mlx_loop_hook(game->mlx, &ft_render, (void *) game);
	mlx_mouse_hide();
	mlx_do_key_autorepeaton(game->mlx);
	return (EXIT_SUCCESS);
}
