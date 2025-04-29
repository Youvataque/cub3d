/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager_joists.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:34:43 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 02:15:07 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

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
			cub_rays_draw_floors_rgb(&game->img, rays, game->color_floor);
			cub_rays_draw_ceilings_rgb(&game->img, rays, game->color_ceiling);
			joists->ty += joists->step;
		}
		rays->draw.x++;
	}
}

// Function to draw the floors
void	cub_rays_draw_floors_rgb(t_img_data *img, t_rays *rays, t_rgb color)
{
	//printf("COLOR FLOOR: R: %d | G: %d | B: %d\n", color.red, color.green, color.blue);
	cub_draw_pixel(img, rays->draw.x - 8, rays->draw_index,
		cub_convert_glrgb(color.red, color.green, color.blue, 1));
}

// Function to draw the ceilings
void	cub_rays_draw_ceilings_rgb(t_img_data *img, t_rays *rays, t_rgb color)
{
	//printf("COLOR CEILINGS: R: %d | G: %d | B: %d\n", color.red, color.green, color.blue);
	cub_draw_pixel(img, rays->draw.x - 8, SCALING - rays->draw_index,
		cub_convert_glrgb(color.red, color.green, color.blue, 1));
}

// Function to setup the drawing of floors and ceilins
void	cub_rays_setup_joists(t_rays *rays, t_player *player, t_joists *joists)
{
	joists->dy = rays->draw_index - (640 / 2.0);
	joists->deg = cub_degtorad(rays->angle);
	joists->fix = cos(cub_degtorad(cub_fixang(player->angle - rays->angle)));
	joists->tx = player->pos.x / 2 + cos(joists->deg) * 158 * 2 * 32 / joists->dy
		/ joists->fix;
	joists->ty = player->pos.y / 2 - sin(joists->deg) * 158 * 2 * 32 / joists->dy
		/ joists->fix;
}
