/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:04:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/06 16:14:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	minimap_background(t_imgdata *img, t_game *game);
static void	minimap_player(t_imgdata *img, t_game *game);

void	minimap(t_imgdata *img, t_game *game)
{
	static int	x[2];
	static int	y[2];

	//printf("player is at: %f %f\n", game->player.pos.x, game->player.pos.y);

	x[START] = PIX_SIZE / 3;
	y[START] = x[START];
	x[END] = PIX_SIZE * 3;
	y[END] = PIX_SIZE * 3;
	minimap_background(img, game);
	minimap_player(img, game);
}

static void	minimap_background(t_imgdata *img, t_game *game)
{
	static int	x[2];
	static int	y[2];

	(void) game;
	x[START] = PIX_SIZE / 3;
	y[START] = x[START];
	x[END] = PIX_SIZE * 3;
	y[END] = PIX_SIZE * 3;
	ft_draw_quadrangle_coordinates(img, x, y, MINIMAP_COLOR);
}

static void	minimap_player(t_imgdata *img, t_game *game)
{
	int	x[2];
	int	y[2];

	x[START] = game->player.pos.x;
	x[START] *= PIX_SIZE / 3;
	x[START] -= PIX_SIZE / 2;
	y[START] = game->player.pos.y;
	y[START] *= PIX_SIZE / 3;
	x[START] -= 2;
	y[START] -= 2;
	x[END] = 4;
	y[END] = 4;
	ft_draw_quadrangle_coordinates(img, x, y, 0x00FF0000);
	(void) game;
}
