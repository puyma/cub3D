/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 01:53:11 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


double moveSpeed;
double rotSpeed;

int	ft_keycode(int k, t_game *game)
{
	moveSpeed = 0.25;
	rotSpeed = 0.25;
	printf("%f, %f\n", game->player.position.x, game->player.position.y);
	if (k == KEY_ESC)
		return (ft_destroy(game), EXIT_SUCCESS);
	if (k == KEY_W || k == KEY_UP)
	{
		if (game->map->board[(int) (game->player.position.x + game->player.direction.x * moveSpeed)][(int) game->player.position.y] != 0)
			game->player.position.x += game->player.direction.x * moveSpeed;
		if (game->map->board[(int) game->player.position.x][(int) (game->player.position.y + game->player.direction.y * moveSpeed)] != 0)
			game->player.position.y += game->player.direction.y * moveSpeed;
	}
	else if (k == KEY_S || k == KEY_DOWN)
	{
      if (game->map->board[(int) (game->player.position.x - game->player.direction.x * moveSpeed)][(int) game->player.position.y] != 0)
		  game->player.position.x -= game->player.direction.x * moveSpeed;
      if (game->map->board[(int) game->player.position.x][(int) (game->player.position.y - game->player.direction.y * moveSpeed)] != 0)
		  game->player.position.y -= game->player.direction.y * moveSpeed;
	}
	else if (k == KEY_A || k == KEY_LEFT)
	{
      double oldDirX = game->player.direction.x;
      game->player.direction.x = game->player.direction.x * cos(rotSpeed) - game->player.direction.y * sin(rotSpeed);
      game->player.direction.y = oldDirX * sin(rotSpeed) + game->player.direction.y * cos(rotSpeed);
      double oldPlaneX = game->player.plane.x;
      game->player.plane.x = game->player.plane.x * cos(rotSpeed) - game->player.plane.y * sin(rotSpeed);
      game->player.plane.y = oldPlaneX * sin(rotSpeed) + game->player.plane.y * cos(rotSpeed);
	}
	else if (k == KEY_D || k == KEY_RIGHT)
	{
      double oldDirX = game->player.direction.x;
      game->player.direction.x = game->player.direction.x * cos(-rotSpeed) - game->player.direction.y * sin(-rotSpeed);
      game->player.direction.y = oldDirX * sin(-rotSpeed) + game->player.direction.y * cos(-rotSpeed);
      double oldPlaneX = game->player.plane.x;
      game->player.plane.x = game->player.plane.x * cos(-rotSpeed) - game->player.plane.y * sin(-rotSpeed);
      game->player.plane.y = oldPlaneX * sin(-rotSpeed) + game->player.plane.y * cos(-rotSpeed);
	}
	printf("dir: %f, %f\n", game->player.direction.x, game->player.direction.y);
	return (EXIT_SUCCESS);
}
