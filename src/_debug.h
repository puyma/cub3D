/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _debug.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:43:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/13 10:43:32 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define ENDL ft_printf("\n");

# define PRINT_LIST(list) \
t_list *rlist = list; \
while (rlist != NULL) \
{ \
	ft_printf("%s\n", (char *) rlist->content); \
	rlist = rlist->next; \
}

# define PRINT_MAP(map) \
size_t rx, ry; ry = 0; \
char c; \
while (ry < map->height) \
{ \
	rx = 0; \
	while (rx < map->width) \
	{ \
		c = map->board[rx][ry]; \
		if (c == 0) { c += 48; } \
		ft_printf("%c ", c); \
		++rx; \
	} \
	ENDL\
	++ry; \
}

# define PRINT_ARRAY(arr) \
int ri = 0; \
while (arr && arr[ri] != NULL) \
{ \
	ft_printf("%s", arr[ri]); ENDL \
	++ri; \
} \
ENDL

# define PRINT_INFO(game) \
ft_printf("-- game info --"); ENDL \
ft_printf("mlx: %p", &game->mlx); ENDL \
ft_printf("mlx_window: %p", &game->mlx_window); ENDL \
ft_printf("window width: %u", game->win_width); ENDL \
ft_printf("window height: %u", game->win_height); ENDL \
ft_printf("map width: %u", game->map->width); ENDL \
ft_printf("map height: %u", game->map->height); ENDL \
ft_printf("f color: %p", game->f_color.ARGB); ENDL \
ft_printf("p color: %p", game->p_color.ARGB); ENDL \
ENDL

