/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/07 13:05:11 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse(int x, int y, t_game *game)
{
	static int			counter = 12;
	const static double	half_width = WIN_WIDTH / 2;
	static double		old = 0;
	double				current;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (mlx_mouse_show(), EXIT_SUCCESS);
	x -= WIN_WIDTH / 2;
	y -= WIN_HEIGHT / 2;
	(void) game;
	(void) old;
	(void) current;
	(void) half_width;
	(void) counter;
	return (EXIT_SUCCESS);
}

	/*
	printf("old: %f\n", old);
	current = x / half_width;
	printf("current: %f\n", current);
	if (--counter == 0)
	{
		old = current;
		counter = 12;
	}
	printf("diff: %f\n", current - old);
	printf("cosc: %f\n", cos(current));
	printf("sinc: %f\n", sin(current));
	printf("%f %f\n", game->player.dir.x, game->player.dir.y);
	double angle = acos(current - old);
	game->player.dir.x = cos(angle) - sin(angle);
	game->player.dir.y = cos(angle) + sin(angle);
	*/
