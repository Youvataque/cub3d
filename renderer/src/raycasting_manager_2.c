/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:38:44 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 11:17:33 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to set the scene in 3d
void	cub_rays_setup_draw(t_game *game, t_rays *rays, t_player *player)
{
	rays->shade = 1;
	if (rays->dist.dist_v < rays->dist.dist_h)
		cub_rays_setup_draw_v(game, rays);
	else if (rays->dist.dist_h < rays->dist.dist_v)
		cub_rays_setup_draw_h(game, rays);
	rays->fish_eye = cub_fixang(player->angle - rays->angle);
	rays->dist.dist_t *= cos(cub_degtorad(rays->fish_eye));
	rays->line_height = (MAP_BLOCK * 320) / rays->dist.dist_t;
	game->walls.offset = 0;
	game->walls.step = 32.0 / (double)rays->line_height;
	if (rays->line_height > 320)
	{
		game->walls.offset = (rays->line_height - 320) / 2.0;
		rays->line_height = 320;
	}
	rays->line_offset = 160 - (rays->line_height >> 1);
	rays->draw.x = rays->index * 8 + 530;
	rays->draw.y = rays->line_offset;
}

// Function to setup drawing on vertical
void	cub_rays_setup_draw_v(t_game *game, t_rays *rays)
{
	rays->dist.dist_t = rays->dist.dist_v;
	rays->pos.x = rays->dist.pos_v.x;
	rays->pos.y = rays->dist.pos_v.y;
	rays->color = cub_convert_glrgb(0, 0.6, 0, 0);
	game->walls.tx = (int)(rays->pos.y / 2) % 32;
	if (rays->angle > 90 && rays->angle < 270)
		game->walls.tx = 31 - game->walls.tx;
	rays->tex_index = rays->tex_index_v;
	rays->shade = 0.5;
}

// Functions to setup drawing on horizontal
void	cub_rays_setup_draw_h(t_game *game, t_rays *rays)
{
	rays->dist.dist_t = rays->dist.dist_h;
	rays->color = cub_convert_glrgb(0, 0.8, 0, 0);
	game->walls.tx = (int)(rays->pos.x / 2) % 32;
	if (rays->angle > 180)
		game->walls.tx = 31 - game->walls.tx;
	rays->tex_index = rays->tex_index_h;
}
// Function to draw the scene
void	cub_rays_draw(t_game *game, t_rays *rays, t_player *player)
{
	cub_draw_line(&game->img, player->pos, rays->pos, rays->color);
	cub_rays_draw_walls(&game->img, rays, &game->walls, game->all_textures);
	cub_rays_draw_joists(game, rays, &game->joists, game->all_textures);
}
