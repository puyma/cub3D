/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:17:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/31 17:14:24 by jsebasti         ###   ########.fr       */
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
	int				width;
	int				height;
	int					**board;
}						t_map;

typedef struct s_vector
{
	double				x;
	double				y;
}						t_vector;

typedef struct s_ray
{
	double				camera_x;
	s_vector			ray_dir;
	s_vector			delta_dist;
	
}						t_ray;

typedef struct s_player
{
	t_vector			position;
	t_vector			direction;
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
	int					i_load_cueue[N_IMAGES];
	size_t				tmp_counter;
	char				*map_filename_ptr;
}						t_game;
