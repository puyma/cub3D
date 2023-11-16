/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:05:05 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/16 17:03:05 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_set_single_color(char *str_value, unsigned char *color);

void	ft_set_rgb_color(char **color_values, t_color *color)
{
	ft_set_single_color(color_values[0], &color->red);
	ft_set_single_color(color_values[1], &color->green);
	ft_set_single_color(color_values[2], &color->blue);
	color->argb = (*(int *)(unsigned char [4]){color->blue, color->green,
			color->red, 0});
}

static void	ft_set_single_color(char *str_value, unsigned char *color)
{
	int		int_value;

	int_value = ft_atoi(str_value);
	if (int_value >= 0 && int_value <= 255)
		*color = (unsigned char) int_value;
}

int	check_rgb_color(char *str)
{
	char	**color_values;
	char	**cpy;
	char	*tmp;
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	color_values = ft_split(str, 040);
	cpy = color_values;
	if (color_values == NULL || ft_arrlen(++color_values) != 3)
		exit_status = EXIT_FAILURE;
	while (exit_status == EXIT_SUCCESS && *color_values != NULL)
	{
		tmp = *color_values;
		while (*tmp != '\0')
		{
			if (ft_isdigit(*tmp++) == 0)
				exit_status = EXIT_FAILURE;
		}
		if (exit_status == EXIT_SUCCESS && ft_atoi(*color_values) > 255)
			exit_status = EXIT_FAILURE;
		++color_values;
	}
	ft_free_arr(cpy);
	return (exit_status);
}
