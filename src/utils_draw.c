/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/07 19:52:32 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_mlx_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int *) dst) = color;
}

/** WIP: use an already (always de same) t_imgdata to write to **/

void	ft_draw_quadrangle_coordinates(t_imgdata *i, int coord_x[2],
		int coord_y[2], int color)
{
	static int	x;
	static int	y;

	y = coord_y[START];
	while (y < coord_y[END])
	{
		x = coord_x[START];
		while (x < coord_x[END])
			ft_mlx_pixel_put(i, x++, y, color);
		++y;
	}
}

void	ft_ver_line(t_game *game, int start, int finish, int color)
{
	while (start <= finish)
	{
		ft_mlx_pixel_put(&game->i_main_frame, game->ray.x, start, color);
		++start;
	}
}

void	ft_draw_textures(t_ray *r, int start, int finish,
			t_game *game, double wall_x)
{
	t_vector	tex;
	static char	*color = NULL;

	tex.intx = (int) (wall_x * (double) PIX_SIZE);
	tex.y = ((double) PIX_SIZE) / game->line_height;
	tex.x = (start - game->win_height / 2 + game->line_height / 2) * tex.y;
	if (r->side == 0 && r->dir.x > 0)
		tex.intx = PIX_SIZE - tex.intx - 1;
	if (r->side == 1 && r->dir.y < 0)
		tex.intx = PIX_SIZE - tex.intx - 1;
	while (start < finish)
	{
		tex.inty = (int)tex.x & (PIX_SIZE - 1);
		tex.x += tex.y;
		color = \
			game->i_north.address + (tex.inty * game->i_north.line_length \
				+ tex.intx * (game->i_north.bits_per_pixel / 8));
		ft_mlx_pixel_put(&game->i_main_frame,
				game->ray.x, start, *((unsigned int *) color));
		start++;
	}
}
