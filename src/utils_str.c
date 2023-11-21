/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:29:53 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/21 21:34:06 by mpuig-ma         ###   ########.fr       */
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
	if (*str == ',')
		*str = ' ';
	(void) p;
}

/*
** DESCRIPTION
** The ft_endswith() function tests if a filename terminates
** in a given sequence of characters.
**
** RETURN VALUES
** Returns EXIT_SUCCESS or EXIT_FAILURE, accordingly.
*/

int	ft_endswith(char *filename, char *ext)
{
	size_t	path_length;
	size_t	ext_len;

	path_length = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (ft_strncmp((filename + path_length - ext_len), ext, ext_len) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_isspace_str(char *str)
{
	if (str == NULL)
		return (EXIT_FAILURE);
	while (str && *str != '\0')
	{
		if (ft_isspace(*str) == 0)
			return (EXIT_FAILURE);
		++str;
	}
	return (EXIT_SUCCESS);
}

int	ft_strischar(char *str, int c)
{
	while (str && *str != '\0')
	{
		if (*str != c)
			return (EXIT_FAILURE);
		++str;
	}
	return (EXIT_SUCCESS);
}
