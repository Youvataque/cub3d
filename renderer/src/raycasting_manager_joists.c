/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager_joists.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:34:43 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 07:35:36 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to render the floors and ceilins
void	cub_rays_draw_joists(t_game *game, t_rays *rays, t_joists *joists,
			int *texture)
{
	int		i;

	i = -1;
	while (++i < 8)
	{
		rays->draw_index = (rays->line_offset + rays->line_height) - 1;
		while (++rays->draw_index < 320)
		{
			cub_rays_setup_joists(rays, &game->player, joists);
			cub_rays_draw_floors(game, rays, joists, texture);
			cub_rays_draw_ceilings(game, rays, joists, texture);
			joists->ty += joists->step;
		}
		rays->draw.x++;
	}
}

// Function to draw the floors
void	cub_rays_draw_floors(t_game *game, t_rays *rays, t_joists *joists,
			int *texture)
{
	double	c;
	int		mp;
	int		color;

	mp = (game->map_floors[(int)(joists->ty / 32.0) * MAP_WIDTH
		+ (int)(joists->tx / 32.0)] - 48) * 32 * 32;
	c = texture[((int)joists->ty & 31) * 32 + ((int)joists->tx & 31) + mp]
		* 0.7;
	color = cub_convert_glrgb(c / 1.3, c / 1.3, c);
	cub_draw_pixel(&game->img, rays->draw.x, rays->draw_index, color);
}

// Function to draw the ceilings
void	cub_rays_draw_ceilings(t_game *game, t_rays *rays, t_joists *joists,
			int *texture)
{
	double	c;
	int		mp;
	int		color;

	mp = (game->map_ceilings[(int)(joists->ty / 32.0) * MAP_WIDTH
		+ (int)(joists->tx / 32.0)] - 48) * 32 * 32;
	c = texture[((int)joists->ty & 31) * 32 + ((int)joists->tx & 31) + mp]
		* 0.7;
	color = cub_convert_glrgb(c / 2.0, c / 1.2, c / 2.0);
	cub_draw_pixel(&game->img, rays->draw.x, 320 - rays->draw_index, color);
}

// Function to setup the drawing of floors and ceilins
void	cub_rays_setup_joists(t_rays *rays, t_player *player,
			t_joists *joists)
{
	joists->dy = rays->draw_index - (320 / 2.0);
	joists->deg = cub_degtorad(rays->angle);
	joists->fix = cos(cub_degtorad(cub_fixang(player->angle - rays->angle)));
	joists->tx = player->pos.x / 2 + cos(joists->deg) * 158 * 32 / joists->dy
		/ joists->fix;
	joists->ty = player->pos.y / 2 - sin(joists->deg) * 158 * 32 / joists->dy
		/ joists->fix;
}

// Function to color different walls
int	cub_rays_switch_colors_joists(t_rays *rays, double c)
{
	int	color;
	
	if (rays->tex_index == 0)
		color = cub_convert_glrgb(c, c / 2.0, c / 2.0); // Checkerboard RED
	else if (rays->tex_index == 1)
		color = cub_convert_glrgb(c, c, c / 2.0); // Brick YELLOW
	else if (rays->tex_index == 2)
		color = cub_convert_glrgb(c / 2.0, c / 2.0, c); // Window BLUE
	else if (rays->tex_index == 3)
		color = cub_convert_glrgb(c / 2.0, c, c / 2.0);	// Door GREEN
	return (color);
}
