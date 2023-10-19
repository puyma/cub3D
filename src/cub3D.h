/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/19 15:12:22 by mpuig-ma         ###   ########.fr       */
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

# define VERSION		"0.1-alpha"
# define EXEC_NAME		"cub3D"
# define MAP_EXT		".cub"

# define NORTH			"north.xpm"
# define SOUTH			"south.xpm"
# define WEST			"west.xpm"
# define EAST			"east.xpm"
# define FLOOR			"floor.xpm"
# define CEILING		"ceiling.xpm"

# define PIX_SIZE		32
# define WIN_WIDTH		800
# define WIN_HEIGHT		600

# define N_IMAGES		4
# define IMG_PREFIX		"src/assets/"

# define C_EMPTY_SPACE	'0'
# define C_WALL			'1'
# define C_COLLECTIBLE	'C'
# define C_EXIT			'E'
# define C_PLAYER		'P'
# define C_ENEMY		'N'
# define C_ALLOWED		"NSEWFC"

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_ESC		53
# define KEY_PAUSE		35

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEMOVE	6
# define ON_DESTROY		17

typedef struct s_color
{
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
	unsigned char		alpha;
	int					argb;
}						t_color;

typedef struct s_imgdata
{
	void				*img;
	char				*address;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
	char				*path_to_image_file;
}						t_imgdata;

typedef struct s_map
{
	size_t				width;
	size_t				height;
	int					**board;
}						t_map;

//						mlx pointers
//						map && map details
//						img(s) - #N_IMAGES
//						color(s)
//						temporal data storage
typedef struct s_game
{
	void				*mlx;
	void				*mlx_window;
	t_map				*map;
	size_t				win_width;
	size_t				win_height;
	t_imgdata			i_north;
	t_imgdata			i_south;
	t_imgdata			i_west;
	t_imgdata			i_east;
	t_imgdata			i_floor;
	int					i_load_cueue[N_IMAGES];
	t_color				f_color;
	t_color				c_color;
	size_t				tmp_counter;
	char				*map_filename_ptr;
}						t_game;

//						map stuff
t_list					*ft_read_file(char *filename);
int						ft_load_map(t_list *file, t_game *game);
int						ft_set_board(t_list *map_lst, t_game *game);
int						ft_set_info(t_list *map_lst, t_game *game);
int						ft_check_map(t_map *map);

//						game/events/graphic stuff
int						ft_start_game(t_game *game);
int						ft_load_events(t_game *game);
int						ft_load_textures(t_game *game);
int						ft_keycode(int keycode, t_game *game);
int						ft_mouse(int x, int y, void *game);
int						ft_destroy(t_game *game);

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

void					ft_clean(t_game *game);

#endif /* cub3D.h */
