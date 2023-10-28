/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:17:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/28 12:03:53 by mpuig-ma         ###   ########.fr       */
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
	size_t				width;
	size_t				height;
	int					**board;
}						t_map;

typedef struct s_vector
{
	double				x;
	double				y;
}						t_vector;

typedef struct s_player
{
	t_vector			position;
	double				direction;
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
