/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/14 17:14:49 by mpuig-ma         ###   ########.fr       */
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

//						graphic stuff
int						ft_render(t_game *game);
int						load_textures(t_game *game);
void					raycast_loop(t_game *game, t_player *pl, t_ray *r);
void					ft_mlx_pixel_put(t_imgdata *i, int x, int y, int color);
void					ft_ver_line(t_game *game, int start,
							int finish, int color);
void					background(t_imgdata *img, t_game *game);
void					ft_textures_size(t_game *game, t_player *pl, t_ray *r);
void					draw_quadrangle(t_imgdata *img,
							t_quadrangle *quad, int color);

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
int						ft_set_rgb_color(char **color_values, t_color *color);
unsigned int			get_texture_color(t_game *game, int tex_x, int tex_y);

//						file utils
t_list					*read_file(char *filename);

//						list utils
int						ft_lstwidth(t_list *list);
int						ft_lstheight(t_list *list);

//						string utils
int						ft_endswith(char *filename, char *ext);
void					ft_replace_isspace(unsigned int position, char *str);
void					ft_replace_ispunct(unsigned int p, char *str);

//
void					ft_clean(t_game *game);

#endif /* cub3D.h */
