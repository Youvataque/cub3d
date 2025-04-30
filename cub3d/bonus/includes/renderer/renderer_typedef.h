/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_typedef.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:57:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/30 19:00:16 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_TYPEDEF_H
# define RENDERER_TYPEDEF_H

# include "renderer_define.h"
# include "../cub.h"

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

typedef struct s_screen
{
	int		sx;
	int		sy;
	int		offset;
	int		pixel;
	int		fade;
	t_rgb	rgb;
}			t_screen;

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
	int			exit;
	int			exit_dir;
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

typedef struct s_minimap
{
	t_map	map;
	t_pos	pos_map;
	t_pos	pos_screen;
	t_pos	center;
	t_point	dir;
	float	mp;
	int		radius;
	int		within_radius;
}			t_minimap;

typedef struct s_point_xyz
{
	int	x;
	int	y;
	int	z;
}		t_point_xyz;

typedef struct s_pos_xyz
{
	float	x;
	float	y;
	float	z;
}			t_pos_xyz;

typedef struct s_sprite
{
	int			type;
	int 		status;
	int			map;
	t_point_xyz	pos;
	t_pos_xyz	screen;
	float		cosinus;
	float		sinus;
	float		a;
	float		b;
	int			depth[FOV];
}				t_sprite;

typedef struct s_game
{
	void		*mlx; // Pointer to mlx connection to server
	void		*win; // Pointer to window connection
	int			*tex_sky;
	int			*tex_sky_layers[3];
	int			*tex_screens_all[3];
	int			*tex_screens;
	int			status;
	int			timer;
	int			*twn;
	int			*tws;
	int			*twe;
	int			*tww;
	int			*tex_door;
	int			*tex_leave;
	int			*tex_leave_wall;
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
	t_screen	screen;
	t_map		map;
	t_map		map_const;
	t_sprite	sprite;
}				t_game;

#endif