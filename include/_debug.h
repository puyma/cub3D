/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _debug.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:43:28 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 10:48:00 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ENDL ft_printf("\n");

#define PRINT_LIST(list) \
t_list *rlist = list; \
while (rlist != NULL) \
{ \
	ft_printf("%s\n", (char *) rlist->content); \
	rlist = rlist->next; \
}

#define PRINT_MAP(map) \
size_t rx, ry; ry = 0; \
char rc; \
while (ry < map->height) \
{ \
	rx = 0; \
	while (rx < map->width) \
	{ \
		rc = map->board[rx][ry]; \
		if (rc == '0') { ft_printf("%c ", rc); } \
		else if (rc == 0) { ft_printf("  "); } \
		else if (ft_strchr(C_ALLOWED, rc) != NULL) \
		{ ft_printf("%s%c%s ", "\033[1;34m", rc, "\033[0m"); } \
		else { ft_printf("%s%c%s ", "\033[1;32m", rc, "\033[0m"); } \
		++rx; \
	} \
	ENDL\
	++ry; \
}

#define PRINT_MAP_ASCII(map) \
size_t rax, ray; ray = 0; \
int rac; \
while (ray < map->height) \
{ \
	rax = 0; \
	while (rax < map->width) \
	{ \
		rac = map->board[rax][ray]; \
		if (rac < 10) \
			ft_printf("   "); \
		else if (rac == '1') \
			ft_printf("%s%d%s ", "\033[1;32m", rac, "\033[0m"); \
		else if (rac == 'N' || rac == 'S' || rac == 'E' || rac == 'W') \
			ft_printf("%s%d%s ", "\033[1;34m", rac, "\033[0m"); \
		else \
			ft_printf("%d ", rac); \
		++rax; \
	} \
	ENDL\
	++ray; \
}

#define PRINT_MAP_INVERSE(map) \
size_t rrx, rry; rrx = 0; \
char rrc; \
while (rrx < map->width) \
{ \
	rry = 0; \
	while (rry < map->height) \
	{ \
		rrc = map->board[rrx][map->height - 1 - rry]; \
		if (rrc == '0') { ft_printf("%c ", rrc); } \
		else if (rrc == 0) { ft_printf("  "); } \
		else if (ft_strchr(C_ALLOWED, rrc) != NULL) \
		{ ft_printf("%s%c%s ", "\033[1;34m", rrc, "\033[0m"); } \
		else { ft_printf("%s%c%s ", "\033[1;32m", rrc, "\033[0m"); } \
		++rry; \
	} \
	ENDL \
	++rrx; \
}

#define PRINT_ARRAY(arr) \
int ri = 0; \
while (arr && arr[ri] != NULL) \
{ \
	ft_printf("%s", arr[ri]); ENDL \
	++ri; \
} \
ENDL

#define PRINT_INFO(game) \
ft_printf("-- start game info --"); ENDL \
ft_printf("mlx: %p", &game->mlx); ENDL \
ft_printf("mlx_window: %p", &game->mlx_window); ENDL \
ft_printf("window width: %u", game->win_width); ENDL \
ft_printf("window height: %u", game->win_height); ENDL \
ft_printf("map width: %u", game->map->width); ENDL \
ft_printf("map height: %u", game->map->height); ENDL \
ft_printf("f color: %p (%d, %d, %d)", game->f_color.argb, \
		game->f_color.red, game->f_color.green, game->f_color.blue); ENDL \
ft_printf("c color: %p (%d, %d, %d)", game->c_color.argb, \
		game->c_color.red, game->c_color.green, game->c_color.blue); ENDL \
ft_printf("-- end game info --"); ENDL
