/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:25:44 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/31 11:03:47 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	posX = 12;
double	posY = 12;
double	dirX = -1;
double	dirY = 0;
double	planeX = 0;
double	planeY = 0.66;

double	time = 0;
double	oldTime = 0;

void	ft_verLine(t_game *game, int x, int drawStart, int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y <= drawEnd)
	{
		ft_mlx_pixel_put(&game->i_main_frame, x, y, color);
		++y;
	}
}

void	ft_raycast_loop(t_game *game, t_imgdata *img)
{
	size_t	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		double cameraX = 2 * x / (double) WIN_WIDTH - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY + cameraX;

		int	mapX = (int) posX;
		int	mapY = (int) posY;

		double	sideDistX;
		double	sideDistY;

		double	deltaDistX = (rayDirX == 0) ? 1e30 : abs((int) (1 / rayDirX));
		double	deltaDistY = (rayDirY == 0) ? 1e30 : abs((int) (1 / rayDirY));
		double	perpWallDist;

		int	stepX;
		int	stepY;

		int	hit = 0;
		int	side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) *deltaDistY;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		// DDA
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (game->map->board[mapX][mapY] != '0')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int	lineHeight = (int) (WIN_HEIGHT / perpWallDist);

		int	drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;

		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		t_color color;
		color.argb = 0xFF171717;
		if (game->map->board[mapX][mapY] == '1')
			color.argb = 0x387959;
		ft_verLine(game, x, drawStart, drawEnd, color.argb);

		++x;
	}
	(void) game;
	(void) img;
}
