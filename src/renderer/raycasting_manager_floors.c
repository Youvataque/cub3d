/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager_floors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:11:19 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 09:00:09 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to draw the floors
void	cub_rays_draw_floors_rgb(t_img_data *img, t_rays *rays, t_rgb color)
{
	cub_draw_pixel(img, rays->draw.x - 8, rays->draw_index,
		cub_convert_glrgb(color.red, color.green, color.blue, 1));
}

// Function to draw the floors with texture
void	cub_rays_draw_floors_tex(t_game *game, t_rays *rays, t_joists *joists,
			int *texture)
{
	int	mp;

	mp = (game->map.map[(int)(joists->ty / 32.0) * game->map.width
			+ (int)(joists->tx / 32.0)] - 48) * 32 * 32;
	joists->pixel = (((int)joists->ty & 31) * 32 + ((int)joists->tx & 31)) * 3
		+ mp * 3;
	joists->rgb.red = texture[joists->pixel + 0] * 0.7;
	joists->rgb.green = texture[joists->pixel + 1] * 0.7;
	joists->rgb.blue = texture[joists->pixel + 2] * 0.7;
	cub_draw_pixel(&game->img, rays->draw.x, rays->draw_index,
		cub_convert_glrgb(joists->rgb.red, joists->rgb.green,
			joists->rgb.blue, 0));
}
