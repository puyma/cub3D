/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:33:58 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/19 19:48:05 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_mlx_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int *) dst) = color;
}

/** WIP: use an already (always de same) t_imgdata to write to **/

void	ft_fill_background(t_game *game)
{
	t_imgdata	img;
	size_t		x;
	size_t		y;

	img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (y < (game->win_height / 2))
				ft_mlx_pixel_put(&img, x++, y, game->c_color.argb);
			else
				ft_mlx_pixel_put(&img, x++, y, game->f_color.argb);
		}
		++y;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, img.img, 0, 0);
	free(img.img);
}

int	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (EXIT_FAILURE);
	if (ft_load_textures(game) == EXIT_FAILURE)
		return (mlx_destroy_font(game->mlx), EXIT_FAILURE);
	game->mlx_window = mlx_new_window(game->mlx,
			game->win_width, game->win_height, EXEC_NAME);
	ft_fill_background(game);
	mlx_hook(game->mlx_window, ON_DESTROY, 0, &ft_destroy, (void *) game);
	mlx_hook(game->mlx_window, ON_KEYDOWN, 0, &ft_keycode, (void *) game);
	mlx_hook(game->mlx_window, ON_MOUSEMOVE, 0, &ft_mouse, (void *) game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
