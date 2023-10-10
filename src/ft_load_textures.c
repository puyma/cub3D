/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:50:46 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/10 10:33:19 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_load_textures(t_game *game)
{
	ft_printf("no: %s\n", game->i_north.path_to_image_file);
	ft_printf("so: %s\n", game->i_south.path_to_image_file);
	ft_printf("we: %s\n", game->i_west.path_to_image_file);
	ft_printf("ea: %s\n", game->i_east.path_to_image_file);
	return (EXIT_SUCCESS);
}
