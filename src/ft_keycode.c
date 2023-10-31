/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/31 11:39:17 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

extern double posX, posY, dirX, dirY, planeX, planeY;
double moveSpeed;
double rotSpeed;

int	ft_keycode(int k, t_game *game)
{
	moveSpeed = 0.25;
	rotSpeed = 0.25;
	if (k == KEY_ESC)
		return (ft_destroy(game), EXIT_SUCCESS);
	if (k == KEY_A || k == KEY_LEFT)
	{
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
	else if (k == KEY_S || k == KEY_DOWN)
	{
      if(game->map->board[(int) (posX - dirX * moveSpeed)][(int) posY])
		  posX -= dirX * moveSpeed;
      if(game->map->board[(int) posX][(int) (posY - dirY * moveSpeed)])
		  posY -= dirY * moveSpeed;
	}
	else if (k == KEY_D || k == KEY_RIGHT)
	{
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	else if (k == KEY_W || k == KEY_UP)
	{
		if (game->map->board[(int) (posX + dirX * moveSpeed)][(int) posY])
			posX += dirX * moveSpeed;
		if (game->map->board[(int) posX][(int) (posY + dirY * moveSpeed)])
			posY += dirY * moveSpeed;
	}
	else if (k == KEY_PAUSE)
		ft_printf("should toggle pause (%x)\n", k);
	return (EXIT_SUCCESS);
}
