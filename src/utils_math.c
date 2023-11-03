/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:24:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/28 11:24:40 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	ft_round_down(double n)
{
	if (n > 0)
		n = round(n) - 1;
	else
		n = round(n);
	return (n);
}
