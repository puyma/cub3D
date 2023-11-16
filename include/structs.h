/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:17:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/16 17:35:40 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macros.h"

typedef struct s_color
{
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
	unsigned char		alpha;
	int					argb;
}						t_color;

typedef struct s_vector
{
	double				x;
	double				y;
	int					intx;
	int					inty;
}						t_vector;

typedef struct s_imgdata
{
	void				*img;
	char				*address;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
	char				image_file[_POSIX_PATH_MAX];
}						t_imgdata;

typedef struct s_map
{
	int					width;
	int					height;
	int					**board;
	char				*filename;
	t_list				*info_segment;
	t_list				*map_segment;
}						t_map;

typedef struct s_ray
{
	double				camera_x;
	double				perp_wall_dist;
	int					hit;
	int					side;
	int					x;
	double				wall_x;
	t_vector			step;
	t_vector			dir;
	t_vector			delta_dist;
	t_vector			side_dist;
	t_vector			map;
}						t_ray;

typedef struct s_player
{
	int					hit;
	t_vector			pos;
	t_vector			dir;
	t_vector			plane;
	double				move_speed;
	double				rot_speed;
}						t_player;

typedef struct s_key
{
	int					up_w;
	int					down_s;
	int					left_a;
	int					right_d;
	int					sprint;
	int					mouse;
	int					pause;
}						t_key;

typedef struct s_quadrangle
{
	int					range_x[2];
	int					range_y[2];
}						t_quadrangle;

typedef struct s_game
{
	void				*mlx;
	void				*mlx_window;
	int					win_width;
	int					win_height;
	int					line_height;
	t_map				map;
	t_player			player;
	t_color				f_color;
	t_color				c_color;
	t_imgdata			i_main_frame;
	t_imgdata			i_north;
	t_imgdata			i_south;
	t_imgdata			i_west;
	t_imgdata			i_east;
	t_ray				ray;
	t_key				key;
	int					i_load_cueue[N_IMAGES];
}						t_game;
