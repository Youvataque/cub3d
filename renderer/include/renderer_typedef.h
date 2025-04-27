/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_typedef.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:47:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 12:19:24 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_TYPEDEF_H
# define RENDERER_TYPEDEF_H

// Enums
typedef enum e_movement
{
	MOVE_FORWARD,
	MOVE_BACKWARD,
	ROTATE_RIGHT,
	ROTATE_LEFT,
	OPEN_DOOR
}	t_movement;

// Structures
typedef struct s_pos
{
	double	x;
	double	y;
}			t_pos;

typedef struct s_player
{
	t_pos	pos; // Player position
	double	angle; // View angle
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
	double	dist_v;
	t_pos	pos_v;
	double	dist_h;
	t_pos	pos_h;
	double	dist_t;
}			t_distance;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
}		t_keys;

typedef struct s_walls
{
	double	ty;
	double	tx;
	double	offset;
	double	step;
}			t_walls;

typedef struct s_joists
{
	double	dy;
	double	ty;
	double	tx;
	double	offset;
	double	step;
	double	deg;
	double	fix;
}			t_joists;

typedef struct s_rays
{
	int			index;
	t_pos		map;
	int			mp;
	int			dof;
	t_pos		pos;
	double		angle;
	t_pos		offset;
	double		tangent;
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
	double		shade;
}				t_rays;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;

typedef struct s_segment
{
	t_pos	start;
	t_pos	end;
}			t_segment;


typedef struct s_fps
{
	double	frame;
	double	old_frame;
	double	fps;
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

typedef struct s_game
{
	void		*mlx; // Pointer to mlx connection to server
	void		*win; // Pointer to window connection
	int			*all_textures;
	int			**textures;
	t_player	player; // player
	t_img_data	img; // image
	t_keys		keys; // keys
	t_rays		rays;
	t_fps		fps;
	t_walls		walls;
	t_joists	joists;
	char		*map_walls; // Map of walls
	char		*map_floors; // Map of floors
	char		*map_ceilings; // Map of Ceilings
}				t_game;

#endif
