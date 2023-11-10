/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:25:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/10 12:25:39 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_quadrangle(t_imgdata *img, t_quadrangle *quad, int color)
{
	static int	x;
	static int	y;

	y = quad->range_y[START];
	while (y < quad->range_y[END])
	{
		x = quad->range_x[START];
		while (x < quad->range_x[END])
			ft_mlx_pixel_put(img, x++, y, color);
		++y;
	}
}

void	ft_draw_quadrangle_coordinates(t_imgdata *i, int coord_x[2],
		int coord_y[2], int color)
{
	static int	x;
	static int	y;

	y = coord_y[START];
	while (y < coord_y[END])
	{
		x = coord_x[START];
		while (x < coord_x[END])
			ft_mlx_pixel_put(i, x++, y, color);
		++y;
	}
}
