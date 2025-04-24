/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_define.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:47:25 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 17:57:46 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_DEFINE_H
# define RENDERER_DEFINE_H

// Macros
# define MAP_WIDTH			24
# define MAP_HEIGHT			24
# define SCREEN_WIDTH		1920
# define SCREEN_HEIGHT		1080
# define INFINITE_DISTANCE	1e30
# define MOVE_SPEED			0.0125
# define ROTATE_SPEED		0.015

// Colors
# define BLACK				"\033[0;30m"
# define RED				"\033[0;31m"
# define GREEN				"\033[0;32m"
# define YELLOW				"\033[0;33m"
# define BLUE				"\033[0;34m"
# define PURPLE				"\033[0;35m"
# define CYAN				"\033[0;36m"
# define WHITE				"\033[0;37m"
# define RESET				"\033[0;0m"

// Keycodes
# define KEY_ESC			65307
# define KEY_W				122
# define KEY_A				113
# define KEY_S				115
# define KEY_D				100

#endif