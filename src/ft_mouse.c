/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:08:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/19 17:03:27 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse(int x, int y, void *param)
{
	t_game	*game;

	game = param;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (mlx_mouse_show(), EXIT_SUCCESS);
	mlx_mouse_hide();
	ft_printf("mouse %d, %d\n", x, y);
	return (EXIT_SUCCESS);
}
