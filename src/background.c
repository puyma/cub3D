/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:05:24 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/06 20:19:32 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	background(t_imgdata *img, t_game *game)
{
	static int		range_x[2] = {0, 0};
	static int		range_y[2] = {0, 0};

	range_x[START] = 0;
	range_x[END] = game->win_width;
	range_y[START] = 0;
	range_y[END] = game->win_height / 2;
	ft_draw_quadrangle_coordinates(img, range_x, range_y, game->c_color.argb);
	range_y[START] = range_y[END];
	range_y[END] = game->win_height;
	ft_draw_quadrangle_coordinates(img, range_x, range_y, game->f_color.argb);
}
