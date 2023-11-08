/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/08 15:48:53 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
t_list					*read_file(char *filename);
t_list					*ft_extract_map_segment(t_list *file);
t_list					*ft_extract_info_segment(t_list *file);
int						ft_load_map(t_list *file, t_game *game);
int						ft_set_board(t_list *map_lst, t_game *game);
int						ft_set_info(t_list *map_lst, t_game *game);
int						ft_check_map(t_map *map);

//						game/events/graphic stuff
int						ft_render(t_game *game);
int						ft_load_events(t_game *game);
int						ft_load_textures(t_game *game);
int						ft_keyup(int k, t_game *game);
int						ft_keydown(int k, t_game *game);
int						ft_mouse(int x, int y, t_game *game);
int						ft_destroy(t_game *game);
void					raycast_loop(t_game *game, t_player *pl,
							t_ray *r, t_imgdata *img);
void					ft_mlx_pixel_put(t_imgdata *i, int x, int y, int color);
void					ft_ver_line(t_game *game, int start,
							int finish, int color);
void					ft_draw_quadrangle_coordinates(t_imgdata *i,
							int coord_x[2], int coord_y[2], int color);
void					ft_draw_quadrangle_coordinates_minimap(t_imgdata *i,
							int coord_x[2], int coord_y[2],
							int color, t_map *map);
void					background(t_imgdata *img, t_game *game);
void					minimap(t_imgdata *img, t_game *game);
int						ft_resize_win(t_game *game);
void					ft_textures_size(t_game *game, t_player *pl, t_ray *r);
void					ft_moves(t_game *game);
void 					ft_right(t_player *pl);
void 					ft_left(t_player *pl);

//						array utils
int						ft_arrlen(char **array);

//						color utils
int						ft_set_rgb_color(char **color_values, t_color *color);
unsigned int			get_texture_color(t_game *game, int tex_x, int tex_y);

//						string utils
int						ft_endswith(char *filename, char *ext);
void					ft_replace_isspace(unsigned int position, char *str);
void					ft_replace_ispunct(unsigned int p, char *str);

//						list utils
int						ft_lstwidth(t_list *list);
int						ft_lstheight(t_list *list);

//						math utils
double					ft_round_down(double n);

void					ft_clean(t_game *game);

#endif /* cub3D.h */
