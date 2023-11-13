/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:16:10 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/13 10:27:31 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

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
# define GRID_SIZE		64
# define WIN_WIDTH		1080
# define WIN_HEIGHT		720
# define WIN_NAME		"cub3D"
// Field Of View

# define N_IMAGES		4
# define IMG_PREFIX		"src/assets/"

# define C_EMPTY_SPACE	'0'
# define C_WALL			'1'
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
# define KEY_PAUSE		49
# define KEY_SHIFT		257

// Event codes (MLX)

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEMOVE	6
# define ON_DESTROY		17
# define ON_RESIZE		9

# define MINIMAP_COLOR		0xC6C6C6
# define MINIMAP_WIDTH		16
# define MINIMAP_HEIGHT		12
# define MINIMAP_TRANS_X	21
# define MINIMAP_TRANS_Y	21
# define MINIMAP_SQUARE		16

# define START			0
# define END			1

#endif /* macros.h */
