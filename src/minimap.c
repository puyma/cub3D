/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:04:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/07 13:42:54 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	minimap_background(t_imgdata *img, t_game *game);
static void	minimap_player(t_imgdata *img, t_game *game);

void	minimap(t_imgdata *img, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)\
		{
			if (game->map->board[x][y] == '1')
				draw_minimap(game, x, y, img, 0x00000000);
			else if (ft_strchr("NSEW", game->map->board[x][y]) != NULL
				&& game->map->board[x][y] != '\0')
				draw_minimap(game, x, y, img, 0x00FF0000);
			else
				draw_minimap(game, x, y, img, MINIMAP_COLOR);
			x++;
		}
		y++;
	}
}

static void	minimap_background(t_imgdata *img, t_game *game)
{
	static int	x[2] = {0, 0};
	static int	y[2] = {0, 0};

	(void) game;
	x[START] = PIX_SIZE / 3;
	y[START] = x[START];
	x[END] = PIX_SIZE * 3;
	y[END] = PIX_SIZE * 3;
	ft_draw_quadrangle_coordinates(img, x, y, MINIMAP_COLOR);
}

static void	minimap_player(t_imgdata *img, t_game *game)
{
	static int	x[2] = {0, 0};
	static int	y[2] = {0, 0};

	x[START] = game->player.pos.x;
	x[START] *= PIX_SIZE / 3;
	x[START] -= PIX_SIZE / 2;
	y[START] = game->player.pos.y;
	y[START] *= PIX_SIZE / 3;
	y[START] -= 2;
	x[END] = 4;
	y[END] = 4;
	ft_draw_quadrangle_coordinates(img, x, y, 0x00FF0000);
	(void) game;
}
