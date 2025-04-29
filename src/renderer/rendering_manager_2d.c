/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager_2d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:03:53 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/30 00:13:34 by nifromon         ###   ########.fr       */
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

// Function to draw the player in 2D
void	cub_render_player2d(t_game *game, t_pos center, int radius, int color)
{
	t_segment	segment;
	t_pos		player_screen;
	t_pos		draw_end;
	int			dx;
	int			dy;

	// Place player at center of minimap
	player_screen.x = center.x;
	player_screen.y = center.y;
	// Optional: draw only if inside the minimap circle
	dx = player_screen.x - center.x;
	dy = player_screen.y - center.y;
	if (dx * dx + dy * dy <= radius * radius)
		cub_draw_point(&game->img, player_screen, MINI_PLAYER, color);
	draw_end.x = center.x + game->player.delta.x * 10;
	draw_end.y = center.y + game->player.delta.y * 10;
	segment.start = center;
	segment.end = draw_end;
	cub_draw_thick_line(&game->img, &segment, MINI_PLAYER / 3, color);
}


// Function to draw the map
void	cub_render_map2d(t_game *game, t_map *map, t_map *map_const, int color)
{
	t_pos	pos_map;
	t_pos	pos_screen;
	float	mp;
	t_pos	center;
	int		radius;
	int		dx, dy;
	int		inside_circle;
	int		j;
	int		i;

	radius = 100; // Circle radius in pixels
	center.x = SCREEN_WIDTH - radius - 10; // 10px margin from top-right
	center.y = radius + 10;
	pos_map.y = -1;
	while (++pos_map.y < map->height)
	{
		pos_map.x = -1;
		while (++pos_map.x < map->width)
		{
			mp = pos_map.y * map->width + pos_map.x;
			pos_screen.x = center.x + (pos_map.x - game->player.pos.x / 64) * MINI_BLOCK;
			pos_screen.y = center.y + (pos_map.y - game->player.pos.y / 64) * MINI_BLOCK;
			inside_circle = 1;
			j = 0;
			while (j <= MINI_BLOCK)
			{
				i = 0;
				while (i <= MINI_BLOCK)
				{
					dx = pos_screen.x + j - center.x;
					dy = pos_screen.y + i - center.y;
					if (dx * dx + dy * dy > radius * radius)
						inside_circle = 0;
					i += MINI_BLOCK;
				}
				j += MINI_BLOCK;
			}
			if (inside_circle)
			{
				if (map->map[(int)mp] == '1')
					cub_draw_filled_square(&game->img, pos_screen, MINI_BLOCK, color);
				else if (map_const->map[(int)mp] == 'D' && map->map[(int)mp] == 'D')
					cub_draw_filled_square(&game->img, pos_screen, MINI_BLOCK, cub_convert_glrgb(255, 0, 0, 1));
				else if (map_const->map[(int)mp] == 'D' && map->map[(int)mp] == '0')
					cub_draw_square(&game->img, pos_screen, MINI_BLOCK, cub_convert_glrgb(0, 255, 0, 1));
				else if (map->map[(int)mp] == 'L')
					cub_draw_filled_square(&game->img, pos_screen, MINI_BLOCK, cub_convert_glrgb(255, 255, 0, 1));
			}
		}
	}
	cub_render_player2d(game, center, radius, cub_convert_glrgb(0, 255, 255, 1));
	cub_draw_circle_outline(&game->img, center, radius, cub_convert_glrgb(255, 255, 255, 1));
}

// Fraw the circle of the minimap border
void	cub_draw_circle_outline(t_img_data *img, t_pos center, int radius, int color)
{
	int x, y;
	int dx, dy;
	int r2 = radius * radius;
	int thickness = 2;

	for (y = -radius; y <= radius; y++)
	{
		for (x = -radius; x <= radius; x++)
		{
			dx = center.x + x;
			dy = center.y + y;
			int dist2 = x * x + y * y;
			if (dist2 >= r2 - thickness * radius && dist2 <= r2 + thickness * radius)
				cub_draw_pixel(img, dx, dy, color);
		}
	}
}

