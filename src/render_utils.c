/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:39:38 by jsebasti          #+#    #+#             */
/*   Updated: 2023/10/24 02:51:55 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	setup_n(t_player *player)
{
	player->dirx = -1;
	player->diry = 0;
	player->planex = 0;
	player->planey = 0.66;
}

void	setup_s(t_player *player)
{
	player->dirx = 1;
	player->diry = 0;
	player->planex = 0;
	player->planey = -0.66;
}

void	setup_w(t_player *player)
{
	player->dirx = 0;
	player->diry = -1;
	player->planex = -0.66;
	player->planey = 0;
}

void	setup_e(t_player *player)
{
	player->dirx = 0;
	player->diry = 1;
	player->planex = 0.66;
	player->planey = 0;
}

int	ft_set_up_player(t_player *player, char coord)
{
	player->locx = player->row + 0.5;
	player->locy = player->col + 0.5;
	player->player = 1;
	if (coord == 'N')
		setup_n(player);
	else if (coord == 'S')
		setup_s(player);
	else if (coord == 'E')
		setup_e(player);
	else if (coord == 'W')
		setup_w(player);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
