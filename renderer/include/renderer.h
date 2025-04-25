/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:52:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 17:36:36 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <fcntl.h>
# include <math.h>

// Includes
	// MLX
# include "../../mlx/mlx.h"
# include "../../mlx/mlx_int.h"
	// LIBFT
# include "../../libft/headers/get_next_line_H/get_next_line.h"
# include "../../libft/headers/libft_H/libft.h"
	// OTHERS
# include "renderer_define.h"
# include "renderer_typedef.h"

// Functions
	// main.c

	// init_manager.c
void	cub_init_manager(t_game *game);
char	*cub_create_map(void);
	// pixel_manager.c
void	cub_draw_pixel(t_img_data *img, int x, int y, int color);
void	cub_draw_line(t_img_data *img, t_pos start, t_pos end, int color);
void	cub_draw_square(t_img_data *img, t_pos pos, int size, int color);
	// raycasting_manager.c
void	cub_raycasting_manager(t_game *game, t_rays *rays, t_player *player);
void	cub_rays_cast_vertical(t_rays *rays, t_player *player);
void	cub_rays_detect_vertical(t_rays *rays, t_player *player,
			t_distance *dist, char *map);
void	cub_rays_cast_horizontal(t_rays *rays, t_player *player);
void	cub_rays_detect_horizontal(t_rays *rays, t_player *player,
			t_distance *dist, char *map);
	// rendering_manager.c
int		cub_rendering_manager(t_game *game);
void	cub_render_scene3d(t_img_data *img, t_rays *rays, t_player *player,
			int color);
void	cub_render_player2d(t_img_data *img, t_player *player, int size,
			int color);
void	cub_render_map2d(t_img_data *img, char *map, int block_size, int color);
	// interaction_manager.c
void	cub_interaction_manager(t_game *game);
void	cub_movement_update(t_keys *keys, t_player *player);
int		cub_handle_key_press(int key, t_game *game);
int		cub_handle_key_release(int key, t_game *game);
int		cub_handle_cross(t_game *game);
	// movement_manager.c
void	cub_movement_manager(t_player *player, int move);
void	cub_move_forward(t_player *player);
void	cub_move_backward(t_player *player);
void	cub_rotate_right(t_player *player);
void	cub_rotate_left(t_player *player);
	// time_manager.c
int		cub_get_time_ms(void);
	// calculation_manager.c
double	cub_degree_to_radian(int degree);
int		cub_fix_angle(int angle);
double	cub_calc_dist(t_pos a, t_pos b, double angle);

#endif