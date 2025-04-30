/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:08 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/30 19:01:17 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "renderer_typedef.h"
# include "renderer_define.h"
# include "../cub.h"

// Functions
	// init_manager.c
void	cub_init_manager(t_game *game, t_cubval *cubval);
void	cub_print_map(t_map *map);
	// init_manager_graphics.c
int		*cub_create_textures(const char *file, int size);
int		*cub_join_textures(int **textures, int size, int nbr);
t_rgb	cub_init_colors(char *source);
	// init_manager_mapping.c
t_map	cub_init_map(char *source, t_point max, t_player *player, t_sprite *sprite);
void	cub_init_player_position(int pos, int width, char orientation,
			t_player *player);
void	cub_init_sprites(int pos, int width, char type, t_sprite *sprite);
	// pixel_manager.c
void	cub_draw_pixel(t_img_data *img, int x, int y, int color);
void	cub_draw_point(t_img_data *img, t_pos pos, int size, int color);
void	cub_draw_line(t_img_data *img, t_pos start, t_pos end, int color);
void	cub_draw_thick_line(t_img_data *img, t_segment *segment, int size,
			int color);
void	cub_draw_square(t_img_data *img, t_pos pos, int size, int color);
void 	cub_draw_filled_square(t_img_data *img, t_pos pos, int size, int color);
	// raycasting_manager.c
void	cub_raycasting_manager(t_game *game, t_rays *rays, t_player *player);
void	cub_rays_setup_draw(t_game *game, t_rays *rays, t_player *player);
void	cub_rays_draw(t_game *game, t_rays *rays);
void	cub_rays_draw_joists(t_game *game, t_rays *rays, t_joists *joists);
void	cub_rays_setup_joists(t_rays *rays, t_player *player, t_joists *joists);
	// raycasting_manager_vertical.c
void	cub_rays_cast_vertical(t_rays *rays, t_player *player);
void	cub_rays_detect_vertical(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map);
void	cub_rays_setup_draw_v(t_game *game, t_rays *rays);
	// raycasting_manager_horizontal.c
void	cub_rays_cast_horizontal(t_rays *rays, t_player *player);
void	cub_rays_detect_horizontal(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map);
void	cub_rays_setup_draw_h(t_game *game, t_rays *rays);
	// raycasting_manager_floors.c
void	cub_rays_draw_floors_rgb(t_img_data *img, t_rays *rays, t_rgb color);
void	cub_rays_draw_floors_tex(t_game *game, t_rays *rays, t_joists *joists,
			int *texture);
	// raycasting_manager_ceilings.c
void	cub_rays_draw_ceilings_rgb(t_img_data *img, t_rays *rays, t_rgb color);
void	cub_rays_draw_ceilings_tex(t_game *game, t_rays *rays, t_joists *joists,
			int *texture);
	// raycasting_manager_walls.c
void	cub_rays_draw_walls(t_img_data *img, t_rays *rays, t_walls *walls,
			int *texture);
	// rendering_manager.c
int		cub_rendering_manager(t_game *game);
void	cub_render_screens(t_game *game, t_screen *screen, int *texture, int status);
	// rendering_manager_2d.c
void	cub_render_player2d(t_game *game, t_pos center, int radius, int color);
void	cub_render_map2d(t_game *game, t_map *map, t_map *map_const, int color);
void	cub_draw_circle_outline(t_img_data *img, t_pos center, int radius, int color);
void	cub_render_texture2d(t_img_data *img, int *texture);
void	cub_render_sky2d(t_img_data *img, t_sky *sky, t_player *player,
			int *texture);
void	cub_render_sky2d_layers(t_img_data *img, t_sky *sky, t_pos pos,
			int *texture);
	// rendering_manager_sprites.c
void	cub_render_sprites(t_game *game, t_sprite *sprite, t_player *player);
	// interaction_manager.c
void	cub_interaction_manager(t_game *game);
void	cub_movement_update(t_keys *keys, t_player *player, float speed,
			t_map *map);
int		cub_handle_key_press(int key, t_game *game);
int		cub_handle_key_release(int key, t_game *game);
int		cub_handle_cross(t_game *game);
	// movement_manager.c
void	cub_movement_manager(t_player *player, int move, float speed,
			t_map *map);
void	cub_move_forward(t_player *player, float speed, t_map *map);
void	cub_move_backward(t_player *player, float speed, t_map *map);
void	cub_move_right(t_player *player, float speed, t_map *map);
void	cub_move_left(t_player *player, float speed, t_map *map);
	// rotation_manager.c
void	cub_rotate_right(t_player *player, float speed);
void	cub_rotate_left(t_player *player, float speed);
	// action_manager.c
void	cub_action_manager(int action, t_player *player, t_map *map);
void	cub_action_open_door(t_player *player, t_map *map);
	// time_manager.c
int		cub_get_time_ms(void);
	// calculation_manager.c
float	cub_degtorad(float degree);
float	cub_fixang(float angle);
float	cub_calc_dist(t_pos a, t_pos b, float angle);
int		cub_convert_glrgb(float red, float green, float blue, int mode);

#endif