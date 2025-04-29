/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:06 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/29 07:46:42 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub.h"

/* structure des coordonées */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/* structure des infos en sortie de .cub */
typedef struct s_cubval
{
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_e;
	char	*f;
	char	*c;
	char	**map;
	char	*map_str;
	t_point	spawn;
	t_point	max_xy;
}	t_cubval;

/* -------------------- renderer.h ------------------------------------------*/

typedef enum e_movement
{
	MOVE_FORWARD,
	MOVE_BACKWARD,
	MOVE_RIGHT,
	MOVE_LEFT,
	ROTATE_RIGHT,
	ROTATE_LEFT,
	OPEN_DOOR
}	t_movement;

// Structures
typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;

typedef struct s_player
{
	t_pos	pos; // Player position
	float	angle; // View angle
	t_pos	delta; // Delta
}			t_player;

typedef struct s_img_data
{
	void	*ptr; // Pointer to image
	char	*addr; // Image
	int		bpp; // Bits per pixel
	int		line_len; // line lenght
	int		endian; // endian
}			t_img_data;

typedef struct s_distance
{
	float	dist_v;
	t_pos	pos_v;
	float	dist_h;
	t_pos	pos_h;
	float	dist_t;
}			t_distance;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	arrow_left;
	int	arrow_right;
}		t_keys;

typedef struct s_walls
{
	float	ty;
	float	tx;
	float	offset;
	float	step;
	int		pixel;
	t_rgb	rgb;
}			t_walls;

typedef struct s_joists
{
	float	dy;
	float	ty;
	float	tx;
	float	offset;
	float	step;
	float	deg;
	float	fix;
	int		pixel;
	t_rgb	rgb;
}			t_joists;

typedef struct s_sky
{
	int		sx;
	int		sy;
	int		offset;
	int		pixel;
	t_rgb	rgb;
}			t_sky;

typedef struct s_rays
{
	int			index;
	t_pos		map;
	int			mp;
	int			dof;
	t_pos		pos;
	float		angle;
	t_pos		offset;
	float		tangent;
	int			fish_eye;
	t_distance	dist;
	t_pos		draw;
	int			draw_index;
	int			line_height;
	int			line_offset;
	int			tex_index;
	int			tex_index_v;
	int			tex_index_h;
	int			color;
	float		shade;
}				t_rays;

typedef struct s_segment
{
	t_pos	start;
	t_pos	end;
}			t_segment;


typedef struct s_fps
{
	float	frame;
	float	old_frame;
	float	fps;
}			t_fps;

typedef struct s_collision
{
	int	xo;
	int	yo;
	int	ipx;
	int	ipy;
	int	ipx_plus_xo;
	int	ipy_plus_yo;
	int	ipx_minus_xo;
	int	ipy_minus_yo;
}		t_collision;

typedef struct s_map
{
	int		width;
	int		height;
	char	*map;
}			t_map;

typedef struct s_game
{
	void		*mlx; // Pointer to mlx connection to server
	void		*win; // Pointer to window connection
	int			*tex_sky;
	int			*tex_sky_layers[3];
	int			*tex_wall_north;
	int			*tex_wall_south;
	int			*tex_wall_east;
	int			*tex_wall_west;
	int			*tex_door;
	t_rgb		color_floor;
	t_rgb		color_ceiling;
	t_player	player; // player
	t_img_data	img; // image
	t_keys		keys; // keys
	t_rays		rays;
	t_fps		fps;
	t_walls		walls;
	t_joists	joists;
	t_sky		sky;
	t_map		map;
}				t_game;

#endif