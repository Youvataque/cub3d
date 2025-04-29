/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:36:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 23:47:18 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to manage the raycasting
void	cub_raycasting_manager(t_game *game, t_rays *rays, t_player *player)
{
	rays->angle = cub_fixang(player->angle + RAYS_STARTING_ANGLE);
	rays->index = -1;
	while (++rays->index < FOV)
	{
		rays->exit_dir = 0;
		rays->exit = 0;
		rays->tex_index_v = 0;
		rays->tex_index_h = 0;
		cub_rays_cast_vertical(rays, player);
		cub_rays_detect_vertical(rays, player, &rays->dist, &game->map);
		cub_rays_cast_horizontal(rays, player);
		cub_rays_detect_horizontal(rays, player, &rays->dist, &game->map);
		cub_rays_setup_draw(game, rays, player);
		cub_rays_draw(game, rays);
		rays->angle = cub_fixang(rays->angle - RAYS_SPACING);
	}
}

// Function to set the scene in 3d
void	cub_rays_setup_draw(t_game *game, t_rays *rays, t_player *player)
{
	rays->shade = 1;
	cub_rays_setup_draw_h(game, rays);
	if (rays->dist.dist_v < rays->dist.dist_h)
		cub_rays_setup_draw_v(game, rays);
	rays->fish_eye = cub_fixang(player->angle - rays->angle);
	rays->dist.dist_t *= cos(cub_degtorad(rays->fish_eye));
	rays->line_height = (64 * SCALING) / rays->dist.dist_t;
	game->walls.offset = 0;
	game->walls.step = 32.0 / (float)rays->line_height;
	if (rays->line_height > SCALING)
	{
		game->walls.offset = (rays->line_height - SCALING) / 2.0;
		rays->line_height = SCALING;
	}
	rays->line_offset = (SCALING / 2) - (rays->line_height >> 1);
	rays->draw.x = rays->index * 8;
	rays->draw.y = rays->line_offset;
}

// Function to draw the scene
void	cub_rays_draw(t_game *game, t_rays *rays)
{
	cub_rays_draw_joists(game, rays, &game->joists);
	if (rays->tex_index == '1')
	{
		if (rays->dist.dist_h < rays->dist.dist_v)
		{
			if (rays->exit == 1)
				cub_rays_draw_walls(&game->img, rays, &game->walls, game->tex_leave_wall);
			else if (sin(cub_degtorad(cub_fixang(rays->angle))) > 0.001)
				cub_rays_draw_walls(&game->img, rays, &game->walls, game->twn);
			else if (sin(cub_degtorad(cub_fixang(rays->angle))) < -0.001)
				cub_rays_draw_walls(&game->img, rays, &game->walls, game->tws);
		}
		else if (rays->dist.dist_v < rays->dist.dist_h)
		{
			if (rays->exit == 1)
				cub_rays_draw_walls(&game->img, rays, &game->walls, game->tex_leave_wall);
			if (cos(cub_degtorad(cub_fixang(rays->angle))) > 0.001)
				cub_rays_draw_walls(&game->img, rays, &game->walls, game->tww);
			else if (cos(cub_degtorad(cub_fixang(rays->angle))) < -0.001)
				cub_rays_draw_walls(&game->img, rays, &game->walls, game->twe);
		}
	}
	else if (rays->tex_index == 'D')
		cub_rays_draw_walls(&game->img, rays, &game->walls, game->tex_door);
}

// Function to render the floors and ceilins
void	cub_rays_draw_joists(t_game *game, t_rays *rays, t_joists *joists)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		rays->draw_index = (rays->line_offset + rays->line_height) - 1;
		while (++rays->draw_index < SCALING)
		{
			cub_rays_setup_joists(rays, &game->player, joists);
			if (game->map.map[(int)(joists->ty / 32.0) * game->map.width
					+ (int)(joists->tx / 32.0)] == 'L')
				cub_rays_draw_floors_tex(game, rays, joists, game->tex_leave);
			else 
				cub_rays_draw_floors_rgb(&game->img, rays, game->color_floor);
			//cub_rays_draw_ceilings_rgb(&game->img, rays, game->color_ceiling);
			joists->ty += joists->step;
		}
		rays->draw.x++;
	}
}

// Function to setup the drawing of floors and ceilins
void	cub_rays_setup_joists(t_rays *rays, t_player *player, t_joists *joists)
{
	joists->dy = rays->draw_index - (SCALING / 2.0);
	joists->deg = cub_degtorad(rays->angle);
	joists->fix = cos(cub_degtorad(cub_fixang(player->angle - rays->angle)));
	joists->tx = player->pos.x / 2 + cos(joists->deg) * 158 * 2 * 32
		/ joists->dy / joists->fix;
	joists->ty = player->pos.y / 2 - sin(joists->deg) * 158 * 2 * 32
		/ joists->dy / joists->fix;
}
