/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 08:05:01 by nifromon         ###   ########.fr       */
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
	cub_render_sky2d(&game->img, &game->sky, &game->player, game->tex_sky);
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
