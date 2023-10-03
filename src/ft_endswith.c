/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:07:03 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/03 12:08:39 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The ft_endswith() function tests if a filename terminates
** in a given sequence of characters.
**
** RETURN VALUES
** Returns EXIT_SUCCESS or EXIT_FAILURE, accordingly.
*/

#include "libft.h"

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
