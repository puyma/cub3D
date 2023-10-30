/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:40 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/24 02:46:40 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_chose_texture(t_ray *ray)
{
	int	texture;

	if (ray->side == 0 && ray->dirx < 0)
		texture = 0;
	else if (ray->side == 0 && ray->dirx > 0)
		texture = 1;
	else if (ray->side == 1 && ray->diry > 0)
		texture = 2;
	else
		texture = 3;
	return (texture);
}

static int	ft_color_to_int(t_color *color)
{
	return (color->red << 16 | color->green << 8 | color->blue);
}

static void	ft_my_put_pixel(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->address + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_get_pixel(t_imgdata *img, int x, int y)
{
	char	*pixel;

	pixel = img->address + (y * img->width + x * (img->bits_per_pixel) / 8);
	return (*(int *)pixel);
}

void	ft_set_textures(t_game *game)
{
	if (game->i_north.address != NULL)
		game->img_array[0] = game->i_north;
	if (game->i_south.address != NULL)
		game->img_array[1] = game->i_south;
	if (game->i_west.address != NULL)
		game->img_array[0] = game->i_west;
	if (game->i_east.address != NULL)
		game->img_array[3] = game->i_east;
}

int	ft_draw(t_game *game, t_render *render, int height, int tex_x)
{
	int			i;
	float		step;
	float		pos_img;
	t_imgdata	*img;
	t_imgdata	*texture;

	texture = &game->img_array[ft_chose_texture(&render->ray)];
	img = &game->img;
	i = 0;
	step = (float)64 / height;
	if (height >= WIN_HEIGHT)
		pos_img = step * (height - WIN_HEIGHT) / 2;
	else
		pos_img = 0;
	while (i < (WIN_HEIGHT / 2 - height / 2))
		ft_my_put_pixel(img, render->x, i++, ft_color_to_int(&game->p_color));
	while (i < WIN_HEIGHT && (WIN_HEIGHT / 2 + height / 2))
	{
		ft_my_put_pixel(img, render->x, i, ft_get_pixel(texture, tex_x, (int)pos_img));
		pos_img += step;
		i++;
	}
	while (i < WIN_HEIGHT)
		ft_my_put_pixel(img, render->x, i++, ft_color_to_int(&game->f_color));
	return (EXIT_SUCCESS);
}
