/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/23 15:41:08 by mpuig-ma         ###   ########.fr       */
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
# include <math.h>		// all funcs. of the math library
# include <limits.h>	// _POSIX_PATH_MAX

# include "mlx.h"		// all the graphic related shit
# include "libft.h"

# include "macros.h"
# include "structs.h"

//						map stuff
int						parse_map(t_game *game, t_map *map, char *filename);
int						validate_map(t_map *map, t_player *player);
int						validate_info(t_map *map);
int						validate_walls(t_map *map);
void					dump_info(t_map *map, t_game *game);
int						dump_map(t_map *map, t_game *game);
void					fill_map(t_list *map_lst, t_map *map);
void					fill_map_zero(t_list *map_lst, t_map *map);
int						check_player(t_list *map_lst);
int						check_player_edge(t_map *map, t_player *player);

//						graphic stuff
int						load_window(t_game *game);
int						load_textures(t_game *game);
int						ft_render(t_game *game);
void					raycast_loop(t_game *game, t_player *pl, t_ray *r);
void					ft_mlx_pixel_put(t_imgdata *i, int x, int y, int color);
void					ft_ver_line(t_game *game, int start, int finish,
							int color);
void					background(t_imgdata *img, t_game *game);
void					ft_textures_size(t_game *game, t_player *pl, t_ray *r);
void					draw_quadrangle(t_imgdata *img, t_quadrangle *quad,
							int color);
int						check_texture(char *str);

//						events stuff
int						ft_keyup(int k, t_game *game);
int						ft_keydown(int k, t_game *game);
int						ft_mouse(int x, int y, t_game *game);
int						ft_destroy(t_game *game);
void					ft_moves(t_game *game);
void					ft_right(t_player *pl);
void					ft_left(t_player *pl);

//						array utils
int						ft_arrlen(char **array);

//						color utils
void					ft_set_rgb_color(char **color_values, t_color *color);
unsigned int			get_texture_color(t_game *game, int tex_x, int tex_y);
int						check_rgb_color(char *str);

//						file utils
t_list					*read_file(char *filename);

//						list utils
int						ft_lstwidth(t_list *list);
int						ft_lstheight(t_list *list);
int						ft_isspace_str(char *str);
void					ft_lstclear_last(t_list *list);

//						string utils
int						ft_endswith(char *filename, char *ext);
void					ft_replace_isspace(unsigned int position, char *str);
void					ft_replace_ispunct(unsigned int p, char *str);
int						ft_strischar(char *str, int c);

//
void					clean(t_game *game);

#endif /* cub3D.h */
