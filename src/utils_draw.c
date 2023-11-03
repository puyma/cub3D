/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/03 12:30:31 by mpuig-ma         ###   ########.fr       */
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

void	ft_ver_line(t_game *game, int start, int finish, int color)
{
	while (start <= finish)
	{
		ft_mlx_pixel_put(&game->i_main_frame, game->ray.x, start, color);
		++start;
	}
}
