/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:50:46 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/10 16:32:14 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_load_texture(t_imgdata *imgdata, t_game *game);

int	ft_load_textures(t_game *game)
{
	game->tmp_counter = 0;
	while (game->tmp_counter < N_IMAGES)
	{
		if (ft_load_texture(game->i_load_cueue[game->tmp_counter],
				game) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		//if (ft_load_texture(&game->i_north, game) == EXIT_FAILURE)
		++(game->tmp_counter);
	}
	return (EXIT_SUCCESS);
}

static int	ft_load_texture(t_imgdata *img, t_game *game)
{
	img->img = mlx_xpm_file_to_image(game->mlx, img->path_to_image_file,
			&img->width, &img->height);
	if (img->img == NULL)
		return (ft_fprintf(stderr, "%s: %s: %s\n", EXEC_NAME,
				img->path_to_image_file, strerror(errno)), EXIT_FAILURE);
	img->address = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	return (EXIT_SUCCESS);
}
