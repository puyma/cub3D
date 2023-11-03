/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:04:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/03 12:58:37 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	minimap(t_imgdata *img, t_game *game)
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
