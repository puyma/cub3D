 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:16:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/10/30 20:32:51 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define VERSION		"0.1-alpha"
# define EXEC_NAME		"cub3D"
# define MAP_EXT		".cub"

# define NORTH			"north.xpm"
# define SOUTH			"south.xpm"
# define WEST			"west.xpm"
# define EAST			"east.xpm"
# define FLOOR			"floor.xpm"
# define CEILING		"ceiling.xpm"

# define PIX_SIZE		64
# define GRID_SIZE		PIX_SIZE
# define WIN_WIDTH		800
# define WIN_HEIGHT		600
# define WIN_NAME		"cub3D"

// Field Of View

# define FOV			60

# define N_IMAGES		4
# define IMG_PREFIX		"src/assets/"

# define C_EMPTY_SPACE	'0'
# define C_WALL			'1'
# define C_COLLECTIBLE	'C'
# define C_EXIT			'E'
# define C_PLAYER		'P'
# define C_ENEMY		'N'
# define C_ALLOWED		"NSEWFC"

// Key codes (MLX)

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

// Event codes (MLX)

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEMOVE	6
# define ON_DESTROY		17

// Minimap settings

# define MINIMAP_COLOR	0x00c6c6c6
