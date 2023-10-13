/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:50:46 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/13 11:38:46 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_load_texture(t_imgdata *imgdata, t_game *game);
static char	*ft_resolve_texture_path(char *value);

int	ft_load_textures(t_game *game)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	game->tmp_counter = 0;
	while (game->tmp_counter < N_IMAGES && exit_status == EXIT_SUCCESS)
	{
		if (game->i_load_cueue[game->tmp_counter] == 'N')
			exit_status = ft_load_texture(&(game->i_north), game);
		else if (game->i_load_cueue[game->tmp_counter] == 'S')
			exit_status = ft_load_texture(&(game->i_south), game);
		else if (game->i_load_cueue[game->tmp_counter] == 'W')
			exit_status = ft_load_texture(&(game->i_west), game);
		else if (game->i_load_cueue[game->tmp_counter] == 'E')
			exit_status = ft_load_texture(&(game->i_east), game);
		++(game->tmp_counter);
	}
	return (exit_status);
}

static int	ft_load_texture(t_imgdata *img, t_game *game)
{
	char	*path;

	path = ft_resolve_texture_path(img->path_to_image_file);
	if (path == NULL)
		return (EXIT_FAILURE);
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (img->img == NULL)
	{
		ft_fprintf(stderr, "%s: %s: %s\n", EXEC_NAME,
			img->path_to_image_file, strerror(errno));
		return (free(path), EXIT_FAILURE);
	}
	img->address = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	return (free(path), EXIT_SUCCESS);
}

static char	*ft_resolve_texture_path(char *value)
{
	char	*str;
	size_t	dst_len;

	dst_len = 0;
	if (ft_strchr(value, '/') != NULL)
		str = ft_strdup(value);
	else
	{
		dst_len = ft_strlen(IMG_PREFIX) + ft_strlen(value) + ft_strlen(".xpm");
		++dst_len;
		str = (char *) ft_calloc(dst_len, sizeof(char));
		ft_strlcpy(str, IMG_PREFIX, dst_len);
		ft_strlcat(str, value, dst_len);
		if (ft_endswith(value, ".xpm") == EXIT_FAILURE)
			ft_strlcat(str, ".xpm", dst_len);
	}
	return (str);
}
