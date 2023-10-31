/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:51 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/31 09:57:33 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* WIP: testing ray's behaviour 
 * https://permadi.com/1996/05/ray-casting-tutorial-7 */

/* We assume ALPHA is 60 degrees
 * based on permadi's example... */

#define ALPHA		60
#define HORIZONTAL	0
#define VERTICAL	1

double	ft_degrees_2_rad(double angle)
{
	return (angle * (M_PI / 180));
}

// consider if angle is 0: -30 to 30 degrees?

void	ft_y_intersection(t_player *player, t_vector point, int mode)
{
	if (mode == HORIZONTAL)
	{
		point.y = ft_round_down(player->position.y / GRID_SIZE) * GRID_SIZE;
		if ((player->direction - 180) <= 0)
			point.y += - 1;
		else
			point.y += 64;
	}
	else
		point.y = player->position.y
			+ (player->position.x - point.x) * tan(ft_degrees_2_rad(ALPHA));
}

void	ft_x_intersection(t_player *player, t_vector point, int mode)
{
	if (mode == HORIZONTAL)
		point.x = player->position.x
			+ (player->position.y - point.y) * tan(ft_degrees_2_rad(ALPHA));
	else
	{
		point.x = ft_round_down(player->position.x / GRID_SIZE) * GRID_SIZE;
		if (player->direction) // LEFT
			point.x += - 1;
		else // RIGHT
			point.x += + 64;
	}
}

void	ft_rays(t_game *game)
{
	t_vector	point_a;
	t_vector	point_b;
	t_vector	point_c;
	t_vector	point_d;
	double		angle_increment;
	double		i;
	double		Ya;
	double		Xa;

	game->player.direction = 90.0;
	game->player.position.x = (1.5 * GRID_SIZE);
	game->player.position.y = (3.5 * GRID_SIZE);
	printf("player.x: %f\n", game->player.position.x);
	printf("player.y: %f\n", game->player.position.y);
	angle_increment = (double) FOV / WIN_WIDTH;	
	i = game->player.direction - (FOV / 2);
	i = 60.0;
	printf("i: %f\n", i);

	// 1. Find coordinate A

	printf("player: %f, %f\n", game->player.position.x, game->player.position.y);
	if ((game->player.direction - 180) > 0)
	// if ray faces down
	{
		point_a.y = (ft_round_down(game->player.position.y / 64) * 64) + 64;
	}
	else
	// else, ray faces up
	{
		point_a.y = (ft_round_down(game->player.position.y / 64) * 64) - 1;
		// -1 cause it start from 0 (0-63,...)
	}

	printf("A.y: %f\n", point_a.y);
	
	point_a.x = game->player.position.x + (game->player.position.y - point_a.y) / tan(ft_degrees_2_rad(ALPHA));
	printf("A.x: %f\n", point_a.x);
	
	printf("A: %d, %d\n",
			(int) point_a.x / GRID_SIZE, (int) point_a.y / GRID_SIZE);
	
	if (game->map->board[(int) point_a.x / 64][(int) point_a.y / 64] == '1')
		printf("there is a wall in %d, %d\n",
			(int) point_a.x / GRID_SIZE, (int) point_a.y / GRID_SIZE);

	// 2. Find Ya

	if ((game->player.direction - 180) > 0)
	// if ray faces down
	{
		// GRID_SIZE (alias or rename macro PIX_SIZE)
		Ya = GRID_SIZE;
	}
	else
	// if ray faces up
	{
		Ya = -GRID_SIZE;
	}
	printf("Ya: %f\n", trunc(Ya));

	// 3. Find Xa

	Xa = GRID_SIZE / tan(i * (M_PI / 180));
	printf("Xa: %f\n", trunc(Xa));

	// 4. Find coordinate C

	point_c.x = trunc(point_a.x) + trunc(Xa);
	point_c.y = trunc(point_a.y) + trunc(Ya);
	printf("C.x: %f\n", point_c.x);
	printf("C.y: %f\n", point_c.y);
	printf("C: %d, %d\n",
			(int) point_c.x / GRID_SIZE, (int) point_c.y / GRID_SIZE);

	/*
	 * (C programmer's note: Remember we always round down,
	 * this is especially true since
	 * you can use right shift by 8 to divide by 64 (GRID_SIZE)) !?!?!.
	 */

	// 5. Check coordinate ? "no wall" : extend to D
	
	if (game->map->board[(int) point_c.x / GRID_SIZE][(int) point_c.y / GRID_SIZE] != '1')
	{
		printf("no wall\n");
	}

	// Angle iteration (Field Of View; FOV)
	//while (i < game->player.direction + (FOV / 2))
	//{
		//printf("angle: %f\n", i);
	//	i += angle_increment;
	//}
	(void) point_a;
	(void) point_b;
	(void) point_c;
	(void) point_d;
	(void) game;
	//exit(0);
}
