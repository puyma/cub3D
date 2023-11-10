/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:05:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/07 14:29:15 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	background(t_imgdata *img, t_game *game)
{
	static t_quadrangle	quad;

	quad.range_x[START] = 0;
	quad.range_x[END] = game->win_width;
	quad.range_y[START] = 0;
	quad.range_y[END] = game->win_height / 2;
	draw_quadrangle(img, &quad, game->c_color.argb);
	quad.range_y[START] = quad.range_y[END];
	quad.range_y[END] = game->win_height;
	draw_quadrangle(img, &quad, game->f_color.argb);
}
