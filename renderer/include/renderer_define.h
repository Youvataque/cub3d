/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:47:25 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 06:03:30 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_DEFINE_H
# define RENDERER_DEFINE_H

// Macros
# ifndef M_PI
#  define M_PI					3.14159265358979323846
# endif

# define DR						0.01745329 // one degree to radian
# define FOV					60

# define MAP_WIDTH				8
# define MAP_HEIGHT				8
# define MAP_BLOCK				64

# define SCREEN_WIDTH			1280
# define SCREEN_HEIGHT			640

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

# define RGB_BROWN				0xA52A2A

// Keycodes
# define KEY_ESC				65307
# define KEY_W					122
# define KEY_A					113
# define KEY_S					115
# define KEY_D					100
# define KEY_E					101

// Textures
# define CHECKBOARD				"./textures/Checkboard"
# define BRICK					"./textures/Brick"
# define WINDOW					"./textures/Window"
# define DOOR					"./textures/Door"

// Maps
# define WALLS					"./maps/map1/walls"
# define FLOORS					"./maps/map1/floors"
# define CEILINGS				"./maps/map1/ceilings"

#endif