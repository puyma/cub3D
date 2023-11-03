/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:17:25 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/01 16:14:49 by mpuig-ma         ###   ########.fr       */
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
	char				*image_file;
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
}						t_vector;

typedef struct s_player
{
	t_vector			position;
	t_vector			direction;
}						t_player;

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
	int					tmp_counter;
	int					tmp_info_cardinal_points[N_IMAGES];
	int					tmp_info_colors;
	char				*map_filename_ptr;
}						t_game;
