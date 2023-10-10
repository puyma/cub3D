/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/10 10:33:40 by mpuig-ma         ###   ########.fr       */
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
//# define WIN_WIDTH	1440
//# define WIN_HEIGHT	1080

# define C_EMPTY_SPACE	'0'
# define C_WALL			'1'
# define C_COLLECTIBLE	'C'
# define C_EXIT			'E'
# define C_PLAYER		'P'
# define C_ENEMY		'N'
# define C_ALLOWED		"NSEWFP"

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
# define ON_DESTROY		17

# define PRINT_LIST(list) while (list != NULL) \
{ ft_printf("%s\n", (char *) list->content); list = list->next; }

# define PRINT_MAP(map) size_t x, y; y = 0; while (y < map->height) \
{ x = 0; while (x < map->width) \
	{ ft_printf("%d\t", map->board[x][y]); ++x; } ft_printf("\n"); ++y; }

# define PRINT_ARRAY(arr) int i = 0; while (arr && arr[i] != NULL) \
{ ft_printf("%s\n", arr[i]); ++i; } ft_printf("\n");

typedef struct s_color
{
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
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

typedef struct s_game
{
	//					mlx pointers
	void				*mlx;
	void				*mlx_window;
	//					map && map details
	t_map				*map;
	size_t				width;	// change to win_width
	size_t				height;	// change to win_height
	//					img(s)
	t_imgdata			i_north;
	t_imgdata			i_south;
	t_imgdata			i_west;
	t_imgdata			i_east;
	t_imgdata			i_floor;
	//					color(s)
	t_color				p_color;
	t_color				f_color;
	//					temporal data storage
	size_t				tmp_counter;
	char				*map_filename_ptr;
}						t_game;

//						map stuff
t_list					*ft_read_file(int fd);
int						ft_load_map(t_list *file, t_game *game);
int						ft_set_map(t_list *map_lst, t_game *game);
int						ft_set_info(t_list *map_lst, t_game *game);

//						game/events/graphic stuff
int						ft_load_game(t_game *game);
int						ft_load_events(t_game *game);
int						ft_load_textures(t_game *game);
int						ft_keycode(int keycode, t_game *game);
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

#endif /* cub3D.h */
