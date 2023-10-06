/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:51:33 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/06 18:24:04 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_keycode(int k, t_game *game)
{
	if (k == KEY_ESC)
		return (ft_destroy(game), EXIT_SUCCESS);
	if (k == KEY_A || k == KEY_S || k == KEY_D || k == KEY_W
		|| k == KEY_LEFT || k == KEY_DOWN || k == KEY_RIGHT || k == KEY_UP)
		ft_printf("key: %d\n", k);
	else if (k == KEY_PAUSE)
		ft_printf("should toggle pause (%x)\n", k);
	return (EXIT_SUCCESS);
}
