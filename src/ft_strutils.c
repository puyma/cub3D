/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:29:53 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/09 15:54:42 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_replace_isspace(unsigned int p, char *str)
{
	if (ft_isspace(*str) != 0)
		*str = ' ';
	(void) p;
}

void	ft_replace_ispunct(unsigned int p, char *str)
{
	if (ft_ispunct(*str) != 0)
		*str = ' ';
	(void) p;
}