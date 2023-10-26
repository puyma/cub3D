/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:51 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/26 17:56:02 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* WIP
** (work in progres)
** https://permadi.com/1996/05/ray-casting-tutorial-7
*/

/* We assume ALPHA is 60 degrees
 * based on permadi's example... */

#define ALPHA 60

/* 64 from PIX_SIZE / GRID_SIZE 
 * defined in cub3D.h */

/* Temporal 'vector'-like struct
 * as we have not gotten to a consensus yet. */

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

/* ft_round_down will eventually be moved to
 * mathutils.c */

double	ft_round_down(double n)
{
	if (n > 0)
		n = round(n) - 1;
	else
		n = round(n);
	return (n);
}

/* WIP: testing ray's behaviour */

void	ft_rays(t_game *game)
{
	t_vector	player;
	t_vector	point_a;
	t_vector	point_b;
	t_vector	point_c;
	t_vector	point_d;
	double		init_angle;
	double		angle_increment;
	double		view_angle;
	double		i;
	double		Ya;
	double		Xa;

	player.x = (1.5 * 64);
	player.y = (3.5 * 64);
	init_angle = 60.0;
	angle_increment = init_angle / WIN_WIDTH;
	view_angle = 60;
	i = view_angle - (init_angle / 2);

	// 1. Find coordinate A

	printf("player: %f, %f\n", player.x, player.y);
	if ((view_angle - 180) > 0)
	// if ray faces down
	{
		point_a.y = (ft_round_down(player.y / 64) * 64) + 64;
	}
	else
	// else, ray faces up
	{
		point_a.y = (ft_round_down(player.y / 64) * 64) - 1;
		// -1 cause it start from 0 (0-63,...)
	}

	printf("A.y: %f\n", point_a.y);
	
	point_a.x = player.x + (player.y - point_a.y) / tan(ALPHA * (M_PI / 180));
	printf("A.x: %f\n", point_a.x);
	
	printf("A: %d, %d\n", (int) point_a.x / 64, (int) point_a.y / 64);
	
	if (game->map->board[(int) point_a.x / 64][(int) point_a.y / 64] == '1')
		printf("there is a wall in %d, %d\n",
			(int) point_a.x / 64, (int) point_a.y / 64);

	// 2. Find Ya

	if ((view_angle - 180) > 0)
	// if ray faces down
	{
		// GRID_SIZE (alias or rename macro PIX_SIZE)
		Ya = PIX_SIZE;
	}
	else
	// if ray faces up
	{
		Ya = -PIX_SIZE;
	}
	printf("Ya: %f\n", trunc(Ya));

	// 3. Find Xa

	Xa = 64 / tan(60 * (M_PI / 180));
	printf("Xa: %f\n", trunc(Xa));

	// 4. Find coordinate C

	point_c.x = trunc(point_a.x) + trunc(Xa);
	point_c.y = trunc(point_a.y) + trunc(Ya);
	printf("C: %d, %d\n", (int) point_c.x, (int) point_c.y);

	/*
	 * (C programmer's note: Remember we always round down,
	 * this is especially true since
	 * you can use right shift by 8 to divide by 64) !?!?!.
	 */

	// 5. Check coordinate ? "no wall" : extend to D
	
	if (game->map->board[(int) point_c.x / 64][(int) point_c.y / 64] != '1')
	{
		printf("no wall\n");
	}

	// Angle iteration (Field Of View; FOV)

	while (i < view_angle + 30) // i < (view_angle + (init_angle / 2))
	{
		//printf("angle: %f\n", i);
		i += angle_increment;
	}
	(void) point_a;
	(void) point_b;
	(void) point_c;
	(void) point_d;
	(void) game;
	exit(0);
}