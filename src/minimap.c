/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:04:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/09 16:46:37 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	minimap_background(t_imgdata *img);
static void	minimap_player(t_imgdata *img);

int	minimap_init(t_game *game)
{
	(void) game;
	return (EXIT_SUCCESS);
}

void	minimap(t_imgdata *img, t_game *game)
{
	(void) game;
	minimap_background(img);
	minimap_player(img);
}

static void	minimap_background(t_imgdata *img)
{
	static t_quadrangle	quad;

	quad.range_x[START] = MINIMAP_TRANS_X;
	quad.range_y[START] = MINIMAP_TRANS_Y;
	quad.range_x[END] = quad.range_x[START] + (MINIMAP_WIDTH * MINIMAP_SQUARE);
	quad.range_y[END] = quad.range_y[START] + (MINIMAP_HEIGHT * MINIMAP_SQUARE);
	draw_quadrangle(img, &quad, MINIMAP_COLOR);
}

static void	minimap_player(t_imgdata *img)
{
	static t_quadrangle	quad;

	quad.range_x[START] = (MINIMAP_WIDTH * MINIMAP_SQUARE) / 2;
	quad.range_x[START] += MINIMAP_TRANS_X - 2;
	quad.range_y[START] = (MINIMAP_HEIGHT * MINIMAP_SQUARE) / 2;
	quad.range_y[START] += MINIMAP_TRANS_Y - 2;
	quad.range_x[END] = quad.range_x[START] + 4;
	quad.range_y[END] = quad.range_y[START] + 4;
	draw_quadrangle(img, &quad, 0xFF0000);
}
