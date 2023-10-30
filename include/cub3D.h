/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:06:12 by mpuig-ma          #+#    #+#             */
<<<<<<< HEAD:src/cub3D.h
/*   Updated: 2023/10/24 02:53:35 by jsebasti         ###   ########.fr       */
=======
/*   Updated: 2023/10/28 11:26:25 by mpuig-ma         ###   ########.fr       */
>>>>>>> puyma-minimap:include/cub3D.h
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
<<<<<<< HEAD:src/cub3D.h

# define VERSION		"0.1-alpha"
# define WIN_NAME		"Cub3D"
# define EXEC_NAME		"error\ncub3D"
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

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	unsigned char	alpha;
	int				argb;
}	t_color;

typedef struct s_imgdata
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	char	*path_to_image_file;
}	t_imgdata;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	int		**board;
}	t_map;

typedef struct s_player
{
	float	locx;
	float	locy;
	float	dirx;
	float	diry;
	float	angle;
	float	planex;
	float	planey;
	int		player;
	int		row;
	int		col;
}	t_player;

typedef struct s_ray
{
	float	camera;
	float	dirx;
	float	diry;
	int		mapx;
	int		mapy;
	float	perpwalldist;
	int		deltadistx;
	int		deltadisty;
	int		sidedistx;
	int		sidedisty;
	int		stepx;
	int		stepy;
	int		side;
	int		colission;
}	t_ray;

typedef struct s_render
{
	t_ray		ray;
	int			x;
	t_player	player;
}	t_render;

typedef struct s_game
{
	//					mlx pointers
	void		*mlx;
	void		*mlx_window;
	//					map && map details
	t_map		*map;
	t_player	player;
	size_t		win_width;
	size_t		win_height;
	//					img(s) - #N_IMAGES
	t_imgdata	i_north;
	t_imgdata	i_south;
	t_imgdata	i_west;
	t_imgdata	i_east;
	t_imgdata	i_floor;
	int			i_load_cueue[N_IMAGES];
	t_imgdata	img_array[N_IMAGES];
	t_imgdata	img;
	//			color(s)
	t_color		p_color;
	t_color		f_color;
	//			temporal data storage
	size_t		tmp_counter;
	char		*map_filename_ptr;
}	t_game;

//						map stuff
t_list	*ft_read_file(char *filename);
int		ft_load_map(t_list *file, t_game *game);
int		ft_set_board(t_list *map_lst, t_game *game);
int		ft_set_info(t_list *map_lst, t_game *game);

//		game/events/graphic stuff
int		ft_start_game(t_game *game);
int		ft_load_events(t_game *game);
int		ft_load_textures(t_game *game);
int		ft_keycode(int keycode, t_game *game);
int		ft_destroy(t_game *game);

//		draw things
int		ft_draw(t_game *game, t_render *render, int height, int texture_x);
int		ft_draw_map(t_game *game);

//		array utils
size_t	ft_arrlen(char **array);
//		color utils
int		ft_set_rgb_color(char **color_values, t_color *color);

//		string utils
int		ft_endswith(char *filename, char *ext);
void	ft_replace_isspace(unsigned int position, char *str);
void	ft_replace_ispunct(unsigned int p, char *str);

//		list utils
size_t	ft_lstwidth(t_list *list);
size_t	ft_lstheight(t_list *list);

void	ft_clean(t_game *game);

//		Render
int		init_render_vars(t_player *player, t_ray *ray, int x);
int		find_dist_to_edge(t_player *player, t_ray *ray);
int		find_colission(t_game *game, t_ray *ray);
float	get_dist(t_player *player, t_ray *ray);
int		get_x_coord(t_player *player, t_ray *ray);
void	setup_n(t_player *player);
void	setup_s(t_player *player);
void	setup_w(t_player *player);
void	setup_e(t_player *player);
int		ft_set_up_player(t_player *player, char coord);
void	ft_set_textures(t_game *game);
=======
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
>>>>>>> puyma-minimap:include/cub3D.h

#endif /* cub3D.h */
