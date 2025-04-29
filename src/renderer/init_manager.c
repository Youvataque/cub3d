/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 20:33:51 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to init all
void	cub_init_manager(t_game *game, t_cubval *cubval)
{
	ft_memset((void *)game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->map = cub_init_map(cubval->map_str, cubval->max_xy, &game->player);
	game->twn = cub_create_textures(cubval->path_n, TEX_SIZE);
	game->tws = cub_create_textures(cubval->path_s, TEX_SIZE);
	game->twe = cub_create_textures(cubval->path_e, TEX_SIZE);
	game->tww = cub_create_textures(cubval->path_w, TEX_SIZE);
	game->tex_door = cub_create_textures(DOOR, TEX_SIZE);
	game->tex_sky_layers[0] = cub_create_textures(SKY_BACKGROUND, SKY_SIZE);
	game->tex_sky_layers[1] = cub_create_textures(SKY_MOON, SKY_SIZE);
	game->tex_sky_layers[2] = cub_create_textures(SKY_CLOUDS, SKY_SIZE);
	game->tex_sky = cub_join_textures(game->tex_sky_layers, SKY_SIZE, SKY_LAYERS);
	game->tex_screens_all[0] = cub_create_textures(SCREEN_START, SCREEN_TEX_SIZE);
	game->tex_screens_all[1] = cub_create_textures(SCREEN_LOSE, SCREEN_TEX_SIZE);
	game->tex_screens_all[2] = cub_create_textures(SCREEN_WIN, SCREEN_TEX_SIZE);
	game->tex_screens = cub_join_textures(game->tex_screens_all, SCREEN_TEX_SIZE, 3);
	game->tex_leave = cub_create_textures(LEAVE, TEX_SIZE);
	game->tex_leave_wall = cub_create_textures(LEAVE_WALL, TEX_SIZE);
	game->status = 1;
	game->timer = 0;
	game->fps.fps = 0;
	game->screen.fade = 1;
	game->fps.frame = cub_get_time_ms();
	game->color_floor = cub_init_colors(cubval->f);
	game->color_ceiling = cub_init_colors(cubval->c);
}

// Function to print a map
void	cub_print_map(t_map *map)
{
	int	i;
	int	div;

	i = -1;
	div = 1;
	while (++i < map->width * map->height)
	{
		if (i / div == map->width)
		{
			printf("\n");
			div++;
		}
		printf("%c", map->map[i]);
	}
}
