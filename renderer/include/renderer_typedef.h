/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_typedef.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:47:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 00:33:29 by nifromon         ###   ########.fr       */
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
	// Map positions
typedef	struct s_map_pos
{
	int		mapX;
	int		mapY;
}			t_map_pos;
	// Directions
typedef struct s_vector
{
	double	vectorX;
	double	vectorY;
}			t_vector;
	// Camera plane
typedef struct s_cam_plane
{
	double	planeX;
	double	planeY;
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
	double	camX;
	double	camY;
}			t_camera;
	// Distance
typedef struct s_distance
{
	double	distX;
	double	distY;
}			t_distance;
	// Step
typedef	struct s_step
{
	int		stepX;
	int		stepY;
}			t_step;
	// Image data
typedef struct s_img_data
{
	void	*ptr_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img_data;
	// Global rendering
typedef	struct s_render
{
	t_pos		init_pos;
	t_vector	init_gaze;
	t_cam_plane	cam_plane;
	t_frame		frame;
	t_camera	camera;
	t_vector	ray_vector;
	t_map_pos	map_pos;
	t_distance	side;
	t_distance	delta;
	t_step		step;
	t_img_data	img;
	int			perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	int			*world[MAP_WIDTH][MAP_HEIGHT];
	double		fps;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_render;


#endif

