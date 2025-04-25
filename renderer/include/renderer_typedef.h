/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_typedef.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:47:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 17:33:51 by nifromon         ###   ########.fr       */
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
	ROTATE_LEFT
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
}			t_rays;

typedef struct s_game
{
	void		*mlx; // Pointer to mlx connection to server
	void		*win; // Pointer to window connection
	t_player	player; // player
	t_img_data	img; // image
	t_keys		keys; // keys
	t_rays		rays;
	char		*map; // Map
}				t_game;

#endif
