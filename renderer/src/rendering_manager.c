/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 14:50:50 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to loop and render
int	cub_rendering_manager(t_game *game)
{
	cub_movement_update(&game->keys, &game->player, 0.2 * game->fps.fps,
		game->map_walls);
	game->img.ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	cub_render_map2d(&game->img, game->map_walls, MAP_BLOCK, cub_convert_glrgb(1, 1, 1, 0));
	cub_render_player2d(&game->img, &game->player, 8, cub_convert_glrgb(1, 1, 0, 0));
	// cub_raycasting_manager(game, &game->rays, &game->player);
	// cub_render_texture2d(&game->img, game->textures[4]);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.ptr);
	game->fps.old_frame = game->fps.frame;
	game->fps.frame = cub_get_time_ms();
	game->fps.fps = game->fps.frame - game->fps.old_frame;
	return (0);
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
			cub_draw_point(img, draw, 8, cub_convert_glrgb(rgb.red, rgb.green, 
				rgb.blue, 1));
		}
	}
}

// Function to draw the player in 2D
void	cub_render_player2d(t_img_data *img, t_player *player, int size,
			int color)
{
	t_segment	segment;
	t_pos		vector;

	vector.x = player->pos.x + player->delta.x * 20;
	vector.y = player->pos.y + player->delta.y * 20;
	player->pos.x /= size;
	player->pos.y /= size;
	cub_draw_point(img, player->pos, size, color);
	player->pos.x *= size;
	player->pos.y *= size;
	segment.start = player->pos;
	segment.end = vector;
	cub_draw_thick_line(img, &segment, 4, color);
}

// Function to draw the map
void	cub_render_map2d(t_img_data *img, char *map, int block_size, int color)
{
	t_pos	pos_map;
	t_pos	pos_screen;
	double	mp;

	pos_map.y = -1;
	while (++pos_map.y < MAP_WIDTH)
	{
		pos_map.x = -1;
		while (++pos_map.x < MAP_HEIGHT)
		{
			mp = pos_map.y * MAP_WIDTH + pos_map.x;
			if (map[(int)mp] > '0')
			{
				pos_screen.x = pos_map.x * block_size;
				pos_screen.y = pos_map.y * block_size;
				cub_draw_square(img, pos_screen, block_size, color);
			}
		}
	}
}
