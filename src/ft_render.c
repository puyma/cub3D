/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/24 11:17:07 by mpuig-ma         ###   ########.fr       */
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
	t_imgdata	*img = &game->i_main_frame;
	size_t		x;
	size_t		y;

	img->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->address = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	y = 0;
	while (y < game->win_height)
	{
		x = 0;
		while (x < game->win_width)
		{
			if (y < (game->win_height / 2))
				ft_mlx_pixel_put(img, x++, y, game->c_color.argb);
			else
				ft_mlx_pixel_put(img, x++, y, game->f_color.argb);
		}
		++y;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, img->img, 0, 0);
	free(img->img);
}

int	ft_render(t_game *game)
{
	t_imgdata	*img;

	img = &game->i_main_frame;
	ft_fill_background(game);
	// write to window
	(void) game;
	//mlx_put_image_to_window(game->mlx, game->mlx_window, img->img, 0, 0);
	write(STDOUT_FILENO, "w\n", 2);
	return (EXIT_SUCCESS);
}
