/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/15 12:55:12 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_draw_textures(t_ray *r, int start, int finish,
				t_game *game);

void	ft_mlx_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int *) dst) = color;
}

void	ft_ver_line(t_game *game, int start, int finish, int color)
{
	while (start <= finish)
	{
		ft_mlx_pixel_put(&game->i_main_frame, game->ray.x, start, color);
		++start;
	}
}

void	ft_textures_size(t_game *game, t_player *pl, t_ray *r)
{
	static int			start = 0;
	static int			finish = 0;

	game->line_height = (int)(WIN_HEIGHT / r->perp_wall_dist);
	start = -game->line_height / 2 + WIN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	finish = game->line_height / 2 + WIN_HEIGHT / 2;
	if (finish >= WIN_HEIGHT)
		finish = WIN_HEIGHT - 1;
	if (r->side == 0)
		r->wall_x = pl->pos.y + r->perp_wall_dist * r->dir.y;
	else
		r->wall_x = pl->pos.x + r->perp_wall_dist * r->dir.x;
	r->wall_x -= floor((r->wall_x));
	ft_draw_textures(r, start, finish, game);
}

static void	ft_draw_textures(t_ray *r, int start, int finish,
			t_game *game)
{
	t_vector	tex;

	tex.intx = (int)(r->wall_x * (double) PIX_SIZE);
	tex.y = ((double)PIX_SIZE) / game->line_height;
	tex.x = (start - game->win_height / 2 + game->line_height / 2) * tex.y;
	if (r->side == 0 && r->dir.x > 0)
		tex.intx = PIX_SIZE - tex.intx - 1;
	if (r->side == 1 && r->dir.y < 0)
		tex.intx = PIX_SIZE - tex.intx - 1;
	while (start < finish)
	{
		tex.inty = (int)tex.x & (PIX_SIZE - 1);
		tex.x += tex.y;
		ft_mlx_pixel_put(&game->i_main_frame,
			game->ray.x, start, get_texture_color(game, tex.intx, tex.inty));
		start++;
	}
}
