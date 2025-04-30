/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager_2d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:03:53 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/30 18:46:23 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to render the sky 2D
void	cub_render_sky2d(t_img_data *img, t_sky *sky, t_player *player,
			int *texture)
{
	t_pos	pos;

	pos.y = -1;
	while (++pos.y < SKY_HEIGHT)
	{
		pos.x = -1;
		while (++pos.x < SKY_WIDTH)
		{
			sky->offset = (int)player->angle * 0.5 - pos.x;
			if (sky->offset < 0)
				sky->offset += SKY_WIDTH;
			sky->offset %= SKY_WIDTH;
			sky->pixel = (pos.y * SKY_WIDTH + sky->offset) * 3
				+ (0 * SKY_WIDTH * SKY_HEIGHT * 3);
			cub_render_sky2d_layers(img, sky, pos, texture);
			sky->pixel = (pos.y * SKY_WIDTH + pos.x) * 3
				+ (1 * SKY_WIDTH * SKY_HEIGHT * 3);
			cub_render_sky2d_layers(img, sky, pos, texture);
			sky->pixel = (pos.y * SKY_WIDTH + sky->offset) * 3
				+ (2 * SKY_WIDTH * SKY_HEIGHT * 3);
			cub_render_sky2d_layers(img, sky, pos, texture);
		}
	}
}

// Function to render different layers of the sky
void	cub_render_sky2d_layers(t_img_data *img, t_sky *sky, t_pos pos,
			int *texture)
{
	sky->rgb.red = texture[sky->pixel + 0];
	sky->rgb.green = texture[sky->pixel + 1];
	sky->rgb.blue = texture[sky->pixel + 2];
	pos.x = (pos.x * SKY_OFFSET) + SKY_OFFSET_PLUS;
	pos.y = (pos.y * SKY_OFFSET) - SCREEN_HEIGHT / SKY_OFFSET_SCREEN;
	if (cub_convert_glrgb(sky->rgb.red, sky->rgb.green, sky->rgb.blue, 1)
		!= cub_convert_glrgb(255, 0, 255, 1))
		cub_draw_point(img, pos, SKY_OFFSET,
			cub_convert_glrgb(sky->rgb.red, sky->rgb.green, sky->rgb.blue, 1));
	pos.x = (pos.x - SKY_OFFSET_PLUS) / SKY_OFFSET;
	pos.y = (pos.y + SCREEN_HEIGHT / SKY_OFFSET_SCREEN) / SKY_OFFSET;
}

// Function to render textures in 2D
void	cub_render_texture2d(t_img_data *img, int *texture)
{
	t_pos	draw;
	int		pixel;
	t_rgb	rgb;

	pixel = 0;
	draw.y = -1;
	while (++draw.y < 32)
	{
		draw.x = -1;
		while (++draw.x < 32)
		{
			pixel = ((draw.y * 32) + draw.x) * 3;
			rgb.red = texture[pixel + 0];
			rgb.green = texture[pixel + 1];
			rgb.blue = texture[pixel + 2];
			draw.x *= 8;
			draw.y *= 8;
			cub_draw_point(img, draw, 8, cub_convert_glrgb(rgb.red, rgb.green,
					rgb.blue, 1));
			draw.x /= 8;
			draw.y /= 8;
		}
	}
}

