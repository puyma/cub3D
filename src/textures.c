/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:50:46 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/15 15:27:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	load_texture(t_imgdata *imgdata, t_game *game);
static char	*ft_resolve_texture_path(char *value);
void		ft_free_loaded_images(t_game *game, size_t iterator);

int	load_textures(t_game *game)
{
	if (load_texture(&(game->i_north), game))
		return (EXIT_FAILURE);
	if (load_texture(&(game->i_south), game))
		return (EXIT_FAILURE);
	if (load_texture(&(game->i_west), game))
		return (EXIT_FAILURE);
	if (load_texture(&(game->i_east), game))
		return (EXIT_FAILURE);
	//ft_free_loaded_images(game, game->tmp_counter - 1);
	return (EXIT_SUCCESS);
}

static int	load_texture(t_imgdata *img, t_game *game)
{
	char	*path;

	path = ft_resolve_texture_path(img->image_file);
	if (path == NULL)
		return (EXIT_FAILURE);
	img->img = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (img->img == NULL)
	{
		ft_fprintf(stderr, "%s: %s: %s\n", EXEC_NAME, path, strerror(errno));
		return (free(path), EXIT_FAILURE);
	}
	img->address = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (img->width != PIX_SIZE && img->height != PIX_SIZE)
	{
		ft_fprintf(stderr, "%s: %s: invalid image size\n", EXEC_NAME, path);
		return (free(path), EXIT_FAILURE);
	}
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

void	ft_free_loaded_images(t_game *game, size_t iterator)
{
	while (iterator-- > 0)
	{
		if (game->i_load_cueue[iterator] == 'N')
			mlx_destroy_image(game->mlx, game->i_north.img);
		else if (game->i_load_cueue[iterator] == 'S')
			mlx_destroy_image(game->mlx, game->i_south.img);
		else if (game->i_load_cueue[iterator] == 'W')
			mlx_destroy_image(game->mlx, game->i_west.img);
		else if (game->i_load_cueue[iterator] == 'E')
			mlx_destroy_image(game->mlx, game->i_east.img);
	}
}
