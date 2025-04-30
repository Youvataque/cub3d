/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager_minimap.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:39:01 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/30 18:52:24 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to draw the player in 2D
void	cub_render_minimap_player(t_game *game, t_pos center, int radius, int color)
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
void	cub_render_minimap(t_game *game, t_map *map, t_minimap *minimap, int color)
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
				else if (minimap->map.map[(int)mp] == 'D' && map->map[(int)mp] == 'D')
					cub_draw_filled_square(&game->img, pos_screen, MINI_BLOCK, cub_convert_glrgb(255, 0, 0, 1));
				else if (minimap->map.map[(int)mp] == 'D' && map->map[(int)mp] == '0')
					cub_draw_square(&game->img, pos_screen, MINI_BLOCK, cub_convert_glrgb(0, 255, 0, 1));
				else if (map->map[(int)mp] == 'L')
					cub_draw_filled_square(&game->img, pos_screen, MINI_BLOCK, cub_convert_glrgb(255, 255, 0, 1));
			}
		}
	}
	cub_render_player2d(game, center, radius, cub_convert_glrgb(0, 255, 255, 1));
	cub_draw_circle_outline(&game->img, center, radius, cub_convert_glrgb(255, 255, 255, 1));
}

// Function to setup the minimap
void    cub_setup_minimap()
{
    
}

// Draw the circle of the minimap border
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
