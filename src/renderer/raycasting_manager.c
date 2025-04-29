/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:36:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 02:25:10 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to manage the raycasting
void	cub_raycasting_manager(t_game *game, t_rays *rays, t_player *player)
{
	rays->angle = cub_fixang(player->angle + FOV / 4);
	rays->index = -1;
	while (++rays->index < FOV)
	{
		rays->tex_index_v = 0;
		rays->tex_index_h = 0;
		cub_rays_cast_vertical(rays, player);
		cub_rays_detect_vertical(rays, player, &rays->dist, &game->map);
		cub_rays_cast_horizontal(rays, player);
		cub_rays_detect_horizontal(rays, player, &rays->dist, &game->map);
		cub_rays_setup_draw(game, rays, player);
		cub_rays_draw(game, rays, player);
		rays->angle = cub_fixang(rays->angle - RAYS_SPACING);
	}
}

// Function to cast rays on vertical lines
void	cub_rays_cast_vertical(t_rays *rays, t_player *player)
{
	rays->dof = 0;
	rays->tangent = tan(cub_degtorad(rays->angle));
	if (cos(cub_degtorad(rays->angle)) > 0.001)
	{
		rays->pos.x = (((int)player->pos.x >> 6) << 6) + 64;
		rays->pos.y = (player->pos.x - rays->pos.x) * rays->tangent
			+ player->pos.y;
		rays->offset.x = 64;
		rays->offset.y = -rays->offset.x * rays->tangent;
	}
	else if (cos(cub_degtorad(rays->angle)) < -0.001)
	{
		rays->pos.x = (((int)player->pos.x >> 6) << 6) - 0.0001;
		rays->pos.y = (player->pos.x - rays->pos.x) * rays->tangent
			+ player->pos.y;
		rays->offset.x = -64;
		rays->offset.y = -rays->offset.x * rays->tangent;
	}
	else
	{
		rays->pos.x = player->pos.x;
		rays->pos.y = player->pos.y;
		rays->dof = 20;
	}
}

// Function to detect if a vertical line was hit
void	cub_rays_detect_vertical(t_rays *rays, t_player *player,
			t_distance *dist, t_map *map)
{
	dist->dist_v = 1000000;
	dist->pos_v.x = rays->pos.x;
	dist->pos_v.y = rays->pos.y;
	while (rays->dof < 20)
	{
		rays->map.x = (int)(rays->pos.x) >> 6;
		rays->map.y = (int)(rays->pos.y) >> 6;
		rays->mp = rays->map.y * map->width + rays->map.x;
		if (rays->mp > 0 && rays->mp < map->width * map->height
			&& map->map[rays->mp] > '0')
		{
			dist->pos_v.x = rays->pos.x;
			dist->pos_v.y = rays->pos.y;
			dist->dist_v = cub_calc_dist(player->pos, dist->pos_v, rays->angle);
			rays->dof = 20;
			rays->tex_index_v = map->map[rays->mp];
		}
		else
		{
			rays->pos.x += rays->offset.x;
			rays->pos.y += rays->offset.y;
			rays->dof++;
		}
	}
}

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
