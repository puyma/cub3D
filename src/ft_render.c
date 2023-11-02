/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/02 17:35:28 by jsebasti         ###   ########.fr       */
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

#define START	0
#define END		1

// this is more like range than coordinates

void	ft_draw_quadrangle_coordinates(t_imgdata *i, int coord_x[2],
		int coord_y[2], int color)
{
	int	x;
	int	y;

	y = coord_y[START];
	while (y < coord_y[END])
	{
		x = coord_x[START];
		while (x < coord_x[END])
			ft_mlx_pixel_put(i, x++, y, color);
		++y;
	}
}

void	ft_add_background(t_imgdata *img, t_game *game)
{
	static int		range_x[2];
	static int		range_y[2];

	range_x[START] = 0;
	range_x[END] = game->win_width;
	range_y[START] = 0;
	range_y[END] = game->win_height / 2;
	ft_draw_quadrangle_coordinates(img, range_x, range_y, game->c_color.argb);
	range_y[START] = range_y[END];
	range_y[END] = game->win_height;
	ft_draw_quadrangle_coordinates(img, range_x, range_y, game->f_color.argb);
}

void	ft_add_minimap(t_imgdata *img, t_game *game)
{
	static int	x[2];
	static int	y[2];

	(void) game;
	x[START] = PIX_SIZE / 4;
	y[START] = x[START];
	x[END] = PIX_SIZE * 4;
	y[END] = PIX_SIZE * 3;
	ft_draw_quadrangle_coordinates(img, x, y, MINIMAP_COLOR);
}

void	ft_add_handheld(t_imgdata *img, t_game *game)
{
	(void) img;
	(void) game;
}

int	ft_render(t_game *game)
{
	t_imgdata	*i;

	i = &game->i_main_frame;
	ft_add_background(i, game);
	//ft_add_handheld(&game->i_main_frame, game);
	ft_raycast_loop(game, &game->player, &game->ray, i);
	ft_add_minimap(&game->i_main_frame, game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, i->img, 0, 0);
	return (EXIT_SUCCESS);
}
