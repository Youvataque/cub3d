/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 03:46:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to loop and render
int	cub_rendering_manager(t_game *game)
{
	cub_movement_update(&game->keys, &game->player, SPEED * game->fps.fps,
		&game->map);
	game->img.ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	//cub_render_sky2d(&game->img, &game->sky, &game->player, game->tex_sky);
	cub_raycasting_manager(game, &game->rays, &game->player);
	//cub_render_map2d(&game->img, &game->map, cub_convert_glrgb(0, 1, 0, 0));
	//cub_render_player2d(game, 6, cub_convert_glrgb(1, 0.843, 0, 0));
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.ptr);
	game->fps.old_frame = game->fps.frame;
	game->fps.frame = cub_get_time_ms();
	game->fps.fps = game->fps.frame - game->fps.old_frame;
	return (0);
}

// // Function to render the sky 2D
void	cub_render_sky2d(t_img_data *img, t_sky *sky, t_player *player, int *texture)
{
	t_pos	pos;

	pos.y = -1;
	while (++pos.y < 40)
	{
		pos.x = -1;
		while (++pos.x < 120)
		{
			sky->offset = (int)player->angle * 2 - pos.x;
			if (sky->offset < 0)
				sky->offset += 120;
			sky->offset %= 120;
			sky->pixel = (pos.y * 120 + sky->offset) * 3;
			sky->rgb.red = texture[sky->pixel + 0];
			sky->rgb.green = texture[sky->pixel + 1];
			sky->rgb.blue = texture[sky->pixel + 2];
			pos.x = (pos.x * 8) + 4;
			pos.y *= 8;
			cub_draw_point(img, pos, 8, cub_convert_glrgb(sky->rgb.red, sky->rgb.green, sky->rgb.blue, 1));
			pos.x = (pos.x - 4) / 8;
			pos.y /= 8;
		}
	}
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
void	cub_render_player2d(t_game *game, int size, int color)
{
	// t_segment	segment;
	// t_pos		vector;

	game->player.pos.x = (game->player.pos.x  / ((MAP_BLOCK) / (game->map.width))) * 1.12;
	game->player.pos.y = (game->player.pos.y  / ((MAP_BLOCK) / (game->map.height))) * 1.12;
	// vector.x = game->player.pos.x + player->delta.x * 10;
	// vector.y = game->player.pos.y + player->delta.y * 10;
	cub_draw_point(&game->img, game->player.pos, size, color);
	// segment.start = player->pos;
	// segment.end = vector;
	// cub_draw_thick_line(img, &segment, 2, color);
	game->player.pos.x = (game->player.pos.x / 1.12) * ((MAP_BLOCK) / (game->map.width));
	game->player.pos.y = (game->player.pos.y / 1.12) * ((MAP_BLOCK) / (game->map.height));
}

// Function to draw the map
void	cub_render_map2d(t_img_data *img, t_map *map, int color)
{
	t_pos	pos_map;
	t_pos	pos_screen;
	float	mp;

	pos_map.y = -1;
	while (++pos_map.y < map->width)
	{
		pos_map.x = -1;
		while (++pos_map.x < map->height)
		{
			mp = pos_map.y * map->width + pos_map.x;
			if (map->map[(int)mp] > '0')
			{
				pos_screen.x = pos_map.x * MAP_BLOCK;
				pos_screen.y = pos_map.y * MAP_BLOCK;
				cub_draw_square(img, pos_screen, MAP_BLOCK, color);
			}
		}
	}
}
