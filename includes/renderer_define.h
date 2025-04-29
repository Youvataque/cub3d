/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:09:41 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/28 19:28:52 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_DEFINE_H
# define RENDERER_DEFINE_H

// Macros
# ifndef M_PI
#  define M_PI					3.14159265358979323846
# endif

# define DR						0.01745329 // one degree to radian
# define FOV					120

# define MAP_BLOCK				24

# define SCREEN_WIDTH			960


# define SCREEN_HEIGHT			640

# define SCALING                640
# define RAYS_SPACING           0.5

// Colors
# define BLACK					"\033[0;30m"
# define RED					"\033[0;31m"
# define GREEN					"\033[0;32m"
# define YELLOW					"\033[0;33m"
# define BLUE					"\033[0;34m"
# define PURPLE					"\033[0;35m"
# define CYAN					"\033[0;36m"
# define WHITE					"\033[0;37m"
# define RESET					"\033[0;0m"

// Graphics Colors
# define RGB_BLACK				0x000000

# define RGB_WHITE				0xFFFFFF
# define RGB_GHOST_WHITE		0xF8F8FF



# define RGB_RED				0xFF0000
# define RGB_CRIMSON			0x990000

# define RGB_GREEN				0x00FF00

# define RGB_BLUE				0x0000FF

# define RGB_YELLOW				0xFF0000

# define RGB_CYAN				0x00FFFF

# define RGB_MAGENTA			0xFF00FF

# define RGB_VERY_DARK_GRAY 	0x0A0A0A
# define RGB_GRAY				0x808080
# define RGB_VERY_LIGHT_GRAY	0xE5E5E5
# define RGB_LIGHT_GRAY			0xCCCCCC

# define RGB_ORANGE				0xFFA500

# define RGB_PINK				0xFFC0CB

# define RGB_PURPLE				0x800080


// Keycodes
# define KEY_ESC				65307
# define KEY_W					122
    // 42
// # define KEY_W					119
# define KEY_ARROW_LEFT			65361
# define KEY_S					115
# define KEY_ARROW_RIGHT		65363
# define KEY_E					101

// Textures
# define CHECKERBOARD			"./textures/Checkerboard.ppm"
# define BRICK					"./textures/Brick.ppm"
# define WINDOW					"./textures/Window.ppm"
# define DOOR					"./textures/Door.ppm"

# define WALL                   "./textures/Wall.ppm"
# define SKY                    "./textures/Sky.ppm"

// Maps
# define WALLS					"./maps/map1/walls"
# define FLOORS					"./maps/map1/floors"
# define CEILINGS				"./maps/map1/ceilings"

#endif