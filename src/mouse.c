/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/03 14:45:33 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse(int x, int y, t_game *game)
{
	int	sum;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (mlx_mouse_show(), EXIT_SUCCESS);
	//mlx_mouse_hide();
	printf("mouse %d, %d\n", x, y);
	x -= WIN_WIDTH / 2;
	y -= WIN_HEIGHT / 2;
	sum = abs(x) + abs(y);
	if (sum != 0)
	{
		printf("scalated %d %d\n", x, y);
		printf("actual direction is: %f %f\n", game->player.dir.x, game->player.dir.y);
		printf("direction will be %f %f\n", (double) x / sum, (double) y / sum);
		//game->player.dir.x = x / sum;
		//game->player.dir.y = y / sum;
	}
	(void) game;
	return (EXIT_SUCCESS);
}
