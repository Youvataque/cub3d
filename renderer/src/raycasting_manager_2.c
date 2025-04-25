/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:38:44 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 18:45:35 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to set and draw the scene in 3d
void	cub_rays_setup_stripes(t_game *game, t_rays *rays, t_player *player)
{
	if (rays->dist.dist_v < rays->dist.dist_h)
	{
		rays->dist.dist_t = rays->dist.dist_v;
		rays->pos.x = rays->dist.pos_v.x;
		rays->pos.y = rays->dist.pos_v.y;
		cub_draw_line(&game->img, player->pos, rays->pos, RGB_CRIMSON);
		cub_render_stripes(&game->img, rays, player, RGB_CRIMSON);
	}
	else if (rays->dist.dist_h < rays->dist.dist_v)
	{
		rays->dist.dist_t = rays->dist.dist_h;
		cub_draw_line(&game->img, player->pos, rays->pos, RGB_RED);
		cub_render_stripes(&game->img, rays, player, RGB_RED);
	}
}