/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/30 20:29:41 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>		// open
# include <unistd.h>	// close, read, write
# include <sys/types.h>	// write
# include <sys/uio.h>	// write
# include <stdio.h>		// printf, perror
# include <string.h>	// strerror
# include <stdlib.h>	// malloc, free, exit, EXIT_*
# include <sys/errno.h>	// errno
# include <math.h>		// all funcs. of the math library // -lm
# include <limits.h>	// _POSIX_PATH_MAX, PATH_MAX

# include "mlx.h"		// all the graphic related shit
# include "libft.h"

# include "_debug.h"
# include "macros.h"
# include "structs.h"

//						map stuff
t_list					*ft_read_file(char *filename);
int						ft_load_map(t_list *file, t_game *game);
int						ft_set_board(t_list *map_lst, t_game *game);
int						ft_set_info(t_list *map_lst, t_game *game);
int						ft_check_map(t_map *map);

//						game/events/graphic stuff
int						ft_render(t_game *game);
int						ft_start_game(t_game *game);
int						ft_load_events(t_game *game);
int						ft_load_textures(t_game *game);
int						ft_keycode(int keycode, t_game *game);
int						ft_mouse(int x, int y, void *game);
int						ft_destroy(t_game *game);
void					ft_rays(t_game *game);

//						array utils
size_t					ft_arrlen(char **array);

//						color utils
int						ft_set_rgb_color(char **color_values, t_color *color);

//						string utils
int						ft_endswith(char *filename, char *ext);
void					ft_replace_isspace(unsigned int position, char *str);
void					ft_replace_ispunct(unsigned int p, char *str);

//						list utils
size_t					ft_lstwidth(t_list *list);
size_t					ft_lstheight(t_list *list);

//						math utils
double					ft_round_down(double n);

void					ft_clean(t_game *game);

#endif /* cub3D.h */