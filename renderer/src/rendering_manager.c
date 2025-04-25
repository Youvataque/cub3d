/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 19:54:48 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to loop and render
int	cub_rendering_manager(t_game *game)
{
	cub_movement_update(&game->keys, &game->player, 0.2 * game->fps.fps,
		game->map);
	game->img.ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	cub_render_map2d(&game->img, game->map, MAP_BLOCK, RGB_CYAN);
	cub_raycasting_manager(game, &game->rays, &game->player);
	cub_render_player2d(&game->img, &game->player, 10, RGB_MAGENTA);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.ptr);
	game->fps.old_frame = game->fps.frame;
	game->fps.frame = cub_get_time_ms();
	game->fps.fps = game->fps.frame - game->fps.old_frame;
	return (0);
}

// Function to render the ray stripes
void	cub_render_stripes(t_img_data *img, t_rays *rays, t_player *player,
			int color)
{
	t_pos	start;
	t_pos	end;
	int		line_height;
	int		line_offset;
	int		i;

	rays->fish_eye = cub_fix_angle(player->angle - rays->angle);
	rays->dist.dist_t *= cos(cub_degree_to_radian(rays->fish_eye));
	line_height = (MAP_BLOCK * 320) / rays->dist.dist_t;
	if (line_height > 320)
		line_height = 320;
	line_offset = 160 - (line_height >> 1);
	start.x = rays->index * 8 + 530;
	start.y = line_offset;
	end.x = rays->index * 8 + 530;
	end.y = line_height + line_offset;
	i = -1;
	while (++i < 8)
	{
		cub_draw_line(img, start, end, color);
		start.x++;
		end.x++;
	}
}

// Function to draw the player in 2D
void	cub_render_player2d(t_img_data *img, t_player *player, int size,
			int color)
{
	t_pos	vector;

	vector.x = player->pos.x + player->delta.x * 5;
	vector.y = player->pos.y + player->delta.y * 5;
	cub_draw_square(img, player->pos, size, color);
	cub_draw_line(img, player->pos, vector, color);
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
			if (map[(int)mp] == '1')
			{
				pos_screen.x = pos_map.x * block_size;
				pos_screen.y = pos_map.y * block_size;
				cub_draw_square(img, pos_screen, block_size, color);
			}
		}
	}
}
