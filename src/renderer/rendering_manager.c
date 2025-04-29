/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 13:09:47 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to loop and render
int	cub_rendering_manager(t_game *game)
{
	game->img.ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	if (game->status == 1)
	{
		cub_render_screens(game, &game->screen, game->tex_screens, game->status);
		game->timer += 1 * game->fps.fps;
		if (game->timer > 3000)
		{
			game->timer = 0;
			game->status = 0;
		}
	}
	else if (game->status == 0)
	{
		cub_movement_update(&game->keys, &game->player, SPEED * game->fps.fps,
			&game->map);
		cub_render_sky2d(&game->img, &game->sky, &game->player, game->tex_sky);
		cub_raycasting_manager(game, &game->rays, &game->player);
		//cub_render_map2d(&game->img, &game->map, cub_convert_glrgb(0, 1, 0, 0));
		//cub_render_player2d(game, 6, cub_convert_glrgb(1, 0.843, 0, 0));
	}
	else if (game->status == 2 || game->status == 3)
		cub_render_screens(game, &game->screen, game->tex_screens, game->status);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.ptr);
	game->fps.old_frame = game->fps.frame;
	game->fps.frame = cub_get_time_ms();
	game->fps.fps = game->fps.frame - game->fps.old_frame;
	return (0);
}

// Function to render the screens
void	cub_render_screens(t_game *game, t_screen *screen, int *texture, int status)
{
	int	tex_index;
	int	x;
	int	y;
	
	tex_index = 0;
	if (status == 0)
		return ;
	else if (status == 2)
		tex_index = SCREEN_TEX_SIZE;
	else if (status == 3)
		tex_index = SCREEN_TEX_SIZE * 2;
	y = -1;
	while (++y < SCREEN_TEX_WIDTH)
	{
		x = -1;
		while (++x < SCREEN_TEX_HEIGHT)
		{
			screen->pixel = (y * SCREEN_TEX_WIDTH + x) * 3 + tex_index;
			screen->rgb.red = texture[screen->pixel + 0] * screen->fade;
			screen->rgb.green = texture[screen->pixel + 1] * screen->fade;
			screen->rgb.blue = texture[screen->pixel + 2] * screen->fade;
			cub_draw_pixel(&game->img, x, y, cub_convert_glrgb(screen->rgb.red, screen->rgb.green, screen->rgb.blue, 1));
		}
	}
	if (screen->fade < 1)
		screen->fade += 0.1 * game->fps.fps;
	if (screen->fade > 1)
		screen->fade = 1;
}
