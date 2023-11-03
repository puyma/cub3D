/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:17:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/02 18:57:29 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int					width;
	int					height;
	int					**board;
}						t_map;

typedef struct s_vector
{
	double				x;
	double				y;
	int					intx;
	int					inty;
}						t_vector;

typedef struct s_ray
{
	double				camera_x;
	double				perp_wall_dist;
	int					hit;
	int					side;
	int					x;
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

//						mlx pointers
//						map && map details
//						img(s) - #N_IMAGES
//						color(s)
//						temporal data storage

typedef struct s_game
{
	void				*mlx;
	void				*mlx_window;
	size_t				win_width;
	size_t				win_height;
	t_map				*map;
	t_player			player;
	t_color				f_color;
	t_color				c_color;
	t_imgdata			i_main_frame;
	t_imgdata			i_north;
	t_imgdata			i_south;
	t_imgdata			i_west;
	t_imgdata			i_east;
	t_imgdata			i_floor;
	t_ray				ray;
	int					i_load_cueue[N_IMAGES];
	size_t				tmp_counter;
	char				*map_filename_ptr;
}						t_game;
