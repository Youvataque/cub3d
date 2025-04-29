/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:08 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/29 02:38:09 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "cub.h"

void	cub_init_manager(t_game *game, t_cubval *cubval);
t_map	cub_init_map(char *source, t_point max, t_player *player);
t_rgb	cub_init_colors(char *source);
int		*cub_create_textures(const char *file, int size);
void	cub_init_player_position(int pos, int width, char orientation,
			t_player *player);
	// pixel_manager.c
void	cub_draw_pixel(t_img_data *img, int x, int y, int color);
void	cub_draw_point(t_img_data *img, t_pos pos, int size, int color);
void	cub_draw_line(t_img_data *img, t_pos start, t_pos end, int color);
void	cub_draw_thick_line(t_img_data *img, t_segment *segment, int size,
			int color);
void	cub_draw_square(t_img_data *img, t_pos pos, int size, int color);
	// raycasting_manager.c
void	cub_raycasting_manager(t_game *game, t_rays *rays, t_player *player);
void	cub_rays_cast_vertical(t_rays *rays, t_player *player);
void	cub_rays_detect_vertical(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map);
void	cub_rays_cast_horizontal(t_rays *rays, t_player *player);
void	cub_rays_detect_horizontal(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map);
	// raycasting_manager_2.c
void	cub_rays_setup_draw(t_game *game, t_rays *rays, t_player *player);
void	cub_rays_setup_draw_v(t_game *game, t_rays *rays);
void	cub_rays_setup_draw_h(t_game *game, t_rays *rays);
void	cub_rays_draw(t_game *game, t_rays *rays, t_player *player);
	// raycasting_manager_walls.c
void	cub_rays_draw_walls(t_img_data *img, t_rays *rays, t_walls *walls,
			int *texture);
	// raycasting_manager_joists.c
void	cub_rays_draw_joists(t_game *game, t_rays *rays, t_joists *joists);
void	cub_rays_draw_floors_rgb(t_img_data *img, t_rays *rays, t_rgb color);
void	cub_rays_draw_ceilings_rgb(t_img_data *img, t_rays *rays, t_rgb color);
void	cub_rays_setup_joists(t_rays *rays, t_player *player, t_joists *joists);
	// raycasting_manager_joists_tex.c
void	cub_rays_draw_floors_tex(t_game *game, t_rays *rays, t_joists *joists,
			int *texture);
void	cub_rays_draw_ceilings_tex(t_game *game, t_rays *rays, t_joists *joists,
			int *texture);
	// rendering_manager.c
int		cub_rendering_manager(t_game *game);
void	cub_render_player2d(t_game *game, int size, int color);
void	cub_render_map2d(t_img_data *img, t_map *map, int color);
void	cub_render_texture2d(t_img_data *img, int *texture);
void	cub_render_sky2d(t_img_data *img, t_sky *sky, t_player *player, int *texture);
	// interaction_manager.c
void	cub_interaction_manager(t_game *game);
void	cub_movement_update(t_keys *keys, t_player *player, double speed,
			t_map *map);
int		cub_handle_key_press(int key, t_game *game);
int		cub_handle_key_release(int key, t_game *game);
int		cub_handle_cross(t_game *game);
	// movement_manager.c
void	cub_movement_manager(t_player *player, int move, double speed,
			t_map *map);
void	cub_move_forward(t_player *player, double speed, t_map *map);
void	cub_move_backward(t_player *player, double speed, t_map *map);
void	cub_rotate_right(t_player *player, double speed);
void	cub_rotate_left(t_player *player, double speed);
	// movement_manager_2.c
void	cub_move_right(t_player *player, double speed, t_map *map);
void	cub_move_left(t_player *player, double speed, t_map *map);
	// action_manager.c
void	cub_action_manager(int action, t_player *player, t_map *map);
void	cub_action_open_door(t_player *player, t_map *map);
	// time_manager.c
int		cub_get_time_ms(void);
	// calculation_manager.c
double	cub_degtorad(double degree);
double	cub_fixang(double angle);
double	cub_calc_dist(t_pos a, t_pos b, double angle);
int		cub_convert_glrgb(double red, double green, double blue, int mode);

#endif