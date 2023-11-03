/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 02:51:18 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse(int x, int y, void *param)
{
	(void)param;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (mlx_mouse_show(), EXIT_SUCCESS);
	mlx_mouse_hide();
	ft_printf("mouse %d, %d\n", x, y);
	return (EXIT_SUCCESS);
}
