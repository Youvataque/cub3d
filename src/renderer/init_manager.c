/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 13:05:12 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to init all
void	cub_init_manager(t_game *game, t_cubval *cubval)
{
	ft_memset((void *)game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->map = cub_init_map(cubval->map_str, cubval->max_xy, &game->player);
	game->twn = cub_create_textures(cubval->path_n, (32 * 32) * 3);
	game->tws = cub_create_textures(cubval->path_s, (32 * 32) * 3);
	game->twe = cub_create_textures(cubval->path_e, (32 * 32) * 3);
	game->tww = cub_create_textures(cubval->path_w, (32 * 32) * 3);
	game->tex_door = cub_create_textures(DOOR, (32 * 32) * 3);
	game->tex_sky_layers[0] = cub_create_textures(SKY_BACKGROUND, SKY_SIZE);
	game->tex_sky_layers[1] = cub_create_textures(SKY_MOON, SKY_SIZE);
	game->tex_sky_layers[2] = cub_create_textures(SKY_CLOUDS, SKY_SIZE);
	game->tex_sky = cub_join_textures(game->tex_sky_layers, SKY_SIZE,
			SKY_LAYERS);
	game->tex_screens_all[0] = cub_create_textures(SCREEN_START, SCREEN_TEX_SIZE);
	game->tex_screens_all[1] = cub_create_textures(SCREEN_LOSE, SCREEN_TEX_SIZE);
	game->tex_screens_all[2] = cub_create_textures(SCREEN_WIN, SCREEN_TEX_SIZE);
	game->tex_screens = cub_join_textures(game->tex_screens_all, SCREEN_TEX_SIZE, 3);
	game->status = 1;
	game->timer = 0;
	game->fps.fps = 0;
	game->screen.fade = 0;
	game->fps.frame = cub_get_time_ms();
	game->color_floor = cub_init_colors(cubval->f);
	game->color_ceiling = cub_init_colors(cubval->c);
}
