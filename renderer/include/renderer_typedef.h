/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_typedef.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:47:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/23 14:40:37 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_TYPEDEF_H
# define RENDERER_TYPEDEF_H

// Structures
	// Positions
typedef struct s_pos
{
	double	posX;
	double	posY;
}			t_pos;
	// Directions
typedef struct s_direction
{
	double	directionX;
	double	directionY;
}			t_direction;
	// Camera plane
typedef struct s_cam_plane
{
	double	cam_planeX;
	double	cam_planeY;
}			t_cam_plane;
	// Frame
typedef struct s_frame
{
	double	new;
	double	old;
}			t_frame;
	// Camera
typedef struct s_camera
{
	double	cameraX;
	double	cameraY;
}			t_camera;
	// Distance
typedef struct s_distance
{
	double	distanceX;
	double	distanceY;
}			t_distance;
	// Step
typedef	struct s_step
{
	double	stepX;
	double	stepY;
}			t_step;
	// Global rendering
typedef	struct s_render
{
	t_pos		spawn_pos;
	t_direction	spawn_dir;
	t_cam_plane	cam_plane;
	t_frame		frame;
	t_camera	camera;
	t_direction	ray_dir;
	t_pos		map_pos;
	t_distance	side;
	t_distance	delta;
	t_step		step;
}				t_render;




#endif

