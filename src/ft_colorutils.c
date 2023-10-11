/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:05:05 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/10 10:44:08 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_set_single_color(char *str_value, unsigned char *color);

int	ft_set_rgb_color(char **color_values, t_color *color)
{
	if (ft_arrlen(color_values) != 3)
		return (EXIT_FAILURE);
	if (ft_set_single_color(color_values[0], &color->red) == EXIT_FAILURE
		|| ft_set_single_color(color_values[1], &color->green) == EXIT_FAILURE
		|| ft_set_single_color(color_values[2], &color->blue) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_set_single_color(char *str_value, unsigned char *color)
{
	char	*tmp;
	int		int_value;

	tmp = str_value;
	while (tmp && *tmp)
	{
		if (ft_isdigit(*tmp) == 0)
			return (EXIT_FAILURE);
		++tmp;
	}
	int_value = ft_atoi(str_value);
	if (int_value >= 0 && int_value <= 255)
		*color = (unsigned char) int_value;
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
