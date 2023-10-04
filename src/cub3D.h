/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/04 12:05:51 by mpuig-ma         ###   ########.fr       */
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

# define C_EMPTY_SPACE	'0'
# define C_WALL			'1'
# define C_COLLECTIBLE	'C'
# define C_EXIT			'E'
# define C_PLAYER		'P'
# define C_ENEMY		'N'
# define C_ALLOWED		"01NSEW"

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
# define KEY_0			29
# define KEY_1			18
# define KEY_C			8
# define KEY_E			14
# define KEY_P			35
# define KEY_N			45

# define PRINT_LIST(list) while (list != NULL) \
{ ft_printf("%s\n", (char *) list->content); list = list->next; }

typedef struct s_imgdata
{
	void				*img;
	char				*address;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_imgdata;

typedef struct s_map
{
	size_t				width;
	size_t				height;
	int					**board;
}						t_map;

typedef struct s_data
{
	//					mlx pointers
	void				*mlx;
	void				*mlx_window;
	//					map && map details
	t_map				*map;
	size_t				width;
	size_t				height;
	//					img pointers (to each texture)
	t_imgdata			*i_north;
	t_imgdata			*i_south;
	t_imgdata			*i_west;
	t_imgdata			*i_east;
	t_imgdata			*i_floor;
}						t_data;

//						map stuff
t_list					*ft_read_file(int fd);
int						ft_load_map(t_list *file, t_data *data);

//						string utils
int						ft_endswith(char *filename, char *ext);

#endif /* cub3D.h */
