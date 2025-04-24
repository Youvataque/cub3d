/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_typedef.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:47:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 16:51:35 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_TYPEDEF_H
# define RENDERER_TYPEDEF_H

// Enums
	// Movement
typedef enum e_movement
{
	MOVE_FORWARD,
	MOVE_BACKWARD,
	ROTATE_RIGHT,
	ROTATE_LEFT
}	t_movement;

// Structures
	// Position on the map (int)
typedef	struct s_pos_int
{
	int	x;
	int	y;
}		t_pos_int;
	// Position on the map (double)
typedef struct s_pos_double
{
	double	x;
	double	y;
}			t_pos_double;
	// Vector
typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;
	// Plane
typedef struct s_plane
{
	double	x;
	double	y;
}			t_plane;
	// Ray
typedef struct s_ray
{
	double		cam_x;
	t_vector	dir;
	t_pos_int	map;
	t_pos_int	step;
	t_vector	side_dist;
	t_vector	delta_dist;
	int			side;
	int			perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
}				t_ray;
	// Camera
typedef struct s_camera
{
	t_pos_double	pos;
	t_vector		dir;
	t_plane			plane;
}					t_camera;
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
	void		*mlx_ptr;
	void		*win_ptr;
	t_camera	cam;
	t_ray		ray;
	t_img_data	img;
	double		frame;
	double		old_frame;
	double		fps;
	int			world[MAP_WIDTH][MAP_HEIGHT];
}				t_render;


#endif

