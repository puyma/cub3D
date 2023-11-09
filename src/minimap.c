/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:04:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/09 16:39:40 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	minimap_background(t_imgdata *img, t_game *game);
static void	minimap_fill_board(t_imgdata *img, t_game *game);
static void	minimap_content(t_imgdata *img, t_game *game);

void	minimap(t_imgdata *img, t_game *game)
{
	static int	x[2] = {0, 0};
	static int	y[2] = {0, 0};

	x[START] = PIX_SIZE / 3;
	y[START] = x[START];
	x[END] = PIX_SIZE * 3;
	y[END] = PIX_SIZE * 3;
	minimap_background(img, game);
	minimap_fill_board(img, game);
	minimap_content(img, game);
}

static void	minimap_background(t_imgdata *img, t_game *game)
{
	static int	x[2] = {0, 0};
	static int	y[2] = {0, 0};

	(void) game;
	x[START] = PIX_SIZE / 3;
	y[START] = x[START];
	x[END] = PIX_SIZE * 4;
	y[END] = PIX_SIZE * 3;
	ft_draw_quadrangle_coordinates(img, x, y, MINIMAP_COLOR);
}

static void	minimap_fill_board(t_imgdata *img, t_game *game)
{
	game->minimap.board[0][0] = '1';
	game->minimap.board[0][1] = '1';
	game->minimap.board[0][2] = '1';
	
	game->minimap.board[1][0] = '0';
	game->minimap.board[1][1] = '1';
	game->minimap.board[1][2] = '0';
	
	game->minimap.board[2][0] = '1';
	game->minimap.board[2][1] = '0';
	game->minimap.board[2][2] = '1';
	
	game->minimap.board[3][0] = 'P';
	game->minimap.board[3][1] = '1';
	game->minimap.board[3][2] = '1';

	(void) img;
}

#define SQUARE_SIZE 16
static void	minimap_content(t_imgdata *img, t_game *game)
{
	int xstart = PIX_SIZE / 3;
	int ystart = xstart;
	int	x;
	int	y;

	(void) xstart;
	(void) ystart;
	printf("xstart %d, ystart %d\n", xstart, ystart);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 3)
		{
		int start[2] = {(x * SQUARE_SIZE) + xstart,
			(x * SQUARE_SIZE) + SQUARE_SIZE + xstart};
		int end[2] = {(y * SQUARE_SIZE) + ystart,
			(y * SQUARE_SIZE) + SQUARE_SIZE + ystart};
		if (game->minimap.board[x][y] == '1')
			ft_draw_quadrangle_coordinates(img, start, end, 0x2222CC);
		else if (game->minimap.board[x][y] == 'P')
			ft_draw_quadrangle_coordinates(img, start, end, 0xFF0000);
			++y;
		}
		++x;
	}

	(void) img;
	(void) game;
}
