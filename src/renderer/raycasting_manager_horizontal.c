/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager_horizontal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:08:15 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 08:19:45 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to cast rays on horizontal lines
void	cub_rays_cast_horizontal(t_rays *rays, t_player *player)
{
	rays->dof = 0;
	rays->tangent = 1.0 / tan(cub_degtorad(rays->angle));
	if (sin(cub_degtorad(rays->angle)) > 0.001)
	{
		rays->pos.y = (((int)player->pos.y >> 6) << 6) - 0.0001;
		rays->pos.x = (player->pos.y - rays->pos.y) * rays->tangent
			+ player->pos.x;
		rays->offset.y = -64;
		rays->offset.x = -rays->offset.y * rays->tangent;
	}
	else if (sin(cub_degtorad(rays->angle)) < -0.001)
	{
		rays->pos.y = (((int)player->pos.y >> 6) << 6) + 64;
		rays->pos.x = (player->pos.y - rays->pos.y) * rays->tangent
			+ player->pos.x;
		rays->offset.y = 64;
		rays->offset.x = -rays->offset.y * rays->tangent;
	}
	else
	{
		rays->pos.x = player->pos.x;
		rays->pos.y = player->pos.y;
		rays->dof = 20;
	}
}

// Function to detect horizontal lines
void	cub_rays_detect_horizontal(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map)
{
	dist->dist_h = 1000000;
	dist->pos_h.x = rays->pos.x;
	dist->pos_h.y = rays->pos.y;
	while (rays->dof < 20)
	{
		rays->map.x = (int)(rays->pos.x) >> 6;
		rays->map.y = (int)(rays->pos.y) >> 6;
		rays->mp = rays->map.y * map->width + rays->map.x;
		if (rays->mp > 0 && rays->mp < map->width * map->height
			&& map->map[rays->mp] > '0')
		{
			dist->pos_h.x = rays->pos.x;
			dist->pos_h.y = rays->pos.y;
			dist->dist_h = cub_calc_dist(player->pos, dist->pos_h, rays->angle);
			rays->dof = 20;
			rays->tex_index_h = map->map[rays->mp];
		}
		else
		{
			rays->pos.x += rays->offset.x;
			rays->pos.y += rays->offset.y;
			rays->dof++;
		}
	}
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
