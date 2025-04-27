/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager_walls.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 04:24:33 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 11:16:44 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to render the walls
void	cub_rays_draw_walls(t_img_data *img, t_rays *rays, t_walls *walls,
			int *texture)
{
	int		i;
	int		color;
	double	c;

	i = -1;
	while (++i < 8)
	{
		rays->draw_index = -1;
		walls->ty = walls->offset * walls->step + (rays->tex_index * 32);
		while (++rays->draw_index < rays->line_height)
		{
			c = texture[(int)walls->ty * 32 + (int)walls->tx] * rays->shade;
			color = cub_rays_switch_colors_walls(rays, c);
			cub_draw_pixel(img, rays->draw.x, rays->draw_index + rays->draw.y,
				color);
			walls->ty += walls->step;
		}
		rays->draw.x++;
	}
}

// Function to color different walls
int	cub_rays_switch_colors_walls(t_rays *rays, double c)
{
	int	color;
	
	if (rays->tex_index == 0)
		color = cub_convert_glrgb(c, c, c / 2.0, 0); // Checkerboard YELLOW
	else if (rays->tex_index == 1)
		color = cub_convert_glrgb(c, c / 2.0, c / 2.0, 0); // Brick RED
	else if (rays->tex_index == 2)
		color = cub_convert_glrgb(c / 2.0, c / 2.0, c, 0); // Window BLUE
	else if (rays->tex_index == 3)
		color = cub_convert_glrgb(c / 2.0, c, c, 0);	// Door CYAN
	return (color);
}