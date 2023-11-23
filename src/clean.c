/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:36:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 16:03:51 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_images(t_game *game);

void	clean(t_game *game)
{
	int	iterator;

	if (game->map.map_segment != NULL
		&& game->map.map_segment != game->map.info_segment)
		ft_lstclear(&game->map.map_segment, &free);
	if (game->map.info_segment != NULL)
		ft_lstclear(&game->map.info_segment, &free);
	if (game->map.board != NULL)
	{
		iterator = 0;
		while (iterator < game->map.height)
			free(game->map.board[iterator++]);
		free(game->map.board);
	}
	if (game->mlx != NULL)
	{
		mlx_destroy_font(game->mlx);
		free(game->mlx);
	}
	if (game->mlx_window != NULL)
		free(game->mlx_window);
	free_images(game);
}

void	free_images(t_game *game)
{
	if (game->i_north.img != NULL)
		free(game->i_north.img);
	if (game->i_south.img != NULL)
		free(game->i_south.img);
	if (game->i_east.img != NULL)
		free(game->i_east.img);
	if (game->i_west.img != NULL)
		free(game->i_west.img);
	if (game->i_main_frame.img != NULL)
		free(game->i_main_frame.img);
}
