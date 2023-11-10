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

void	draw_circle(t_imgdata *img, t_quadrangle *quad, int color)
{
	(void) img;
	(void) quad;
	(void) color;
}
