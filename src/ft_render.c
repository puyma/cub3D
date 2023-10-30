/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:32:18 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/24 02:17:59 by jsebasti         ###   ########.fr       */
=======
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:37:20 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/25 17:29:54 by mpuig-ma         ###   ########.fr       */
>>>>>>> puyma-minimap
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
int	get_x_coord(t_player *player, t_ray *ray)
{
	float	xcoord;

	if (ray->side == 0)
		xcoord = player->locy + ray->perpwalldist * ray->diry;
	else
		xcoord = player->locx + ray->perpwalldist * ray->dirx;
	return ((int)(xcoord * 64));
}

float	get_dist(t_player *player, t_ray *ray)
{
	if (ray->side == 0)
		return ((ray->mapx - player->locx + (1 - ray->stepx) / 2) / ray->dirx);
	else
		return ((ray->mapy - player->locy + (1 - ray->stepy) / 2) / ray->diry);
}

int	find_colission(t_game *game, t_ray *ray)
{
	while (ray->colission == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (game->map->board[ray->mapx][ray->mapy] == C_WALL)
			ray->colission = 1;
	}
	return (EXIT_SUCCESS);
}

int	find_dist_to_edge(t_player *player, t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (player->locx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - player->locx) * ray->deltadistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (player->locy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - player->locy) * ray->deltadisty;
	}
	return (EXIT_SUCCESS);
}

int	init_render_vars(t_player *player, t_ray *ray, int x)
{
	ray->camera = 2 * x / (float)WIN_WIDTH - 1;
	ray->dirx = player->dirx + player->planex * ray->camera;
	ray->diry = player->diry + player->planey * ray->camera;
	ray->mapx = player->locx;
	ray->mapy = player->locy;
	ray->deltadistx = fabs(1 / ray->dirx);
	ray->deltadisty = fabs(1 / ray->diry);
	ray->colission = 0;
=======
void	ft_mlx_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*dst;

	dst = img->address + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*((unsigned int *) dst) = color;
}

/** WIP: use an already (always de same) t_imgdata to write to **/

#define START	0
#define END		1

// this is more like range than coordinates

void	ft_draw_quadrangle_coordinates(t_imgdata *i, size_t coord_x[2],
		size_t coord_y[2], int color)
{
	size_t	x;
	size_t	y;

	y = coord_y[START];
	while (y < coord_y[END])
	{
		x = coord_x[START];
		while (x < coord_x[END])
			ft_mlx_pixel_put(i, x++, y, color);
		++y;
	}
}

void	ft_add_background(t_imgdata *img, t_game *game)
{
	static size_t		range_x[2];
	static size_t		range_y[2];

	range_x[START] = 0;
	range_x[END] = game->win_width;
	range_y[START] = 0;
	range_y[END] = game->win_height / 2;
	ft_draw_quadrangle_coordinates(img, range_x, range_y, game->c_color.argb);
	range_y[START] = range_y[END];
	range_y[END] = game->win_height;
	ft_draw_quadrangle_coordinates(img, range_x, range_y, game->f_color.argb);
}

void	ft_add_minimap(t_imgdata *img, t_game *game)
{
	static size_t	x[2];
	static size_t	y[2];

	(void) game;
	x[START] = PIX_SIZE / 4;
	y[START] = x[START];
	x[END] = PIX_SIZE * 4;
	y[END] = PIX_SIZE * 3;
	ft_draw_quadrangle_coordinates(img, x, y, MINIMAP_COLOR);
}

void	ft_add_handheld(t_imgdata *img, t_game *game)
{
	(void) img;
	(void) game;
}

int	ft_render(t_game *game)
{
	t_imgdata	*i;

	i = &game->i_main_frame;
	i->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	i->address = mlx_get_data_addr(i->img, &(i->bits_per_pixel),
			&(i->line_length), &(i->endian));
	ft_add_background(i, game);
	ft_add_minimap(&game->i_main_frame, game);
	ft_add_handheld(&game->i_main_frame, game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, i->img, 0, 0);
	free(i->img);
>>>>>>> puyma-minimap
	return (EXIT_SUCCESS);
}
