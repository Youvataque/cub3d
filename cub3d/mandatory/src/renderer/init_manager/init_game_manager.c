/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 03:59:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to init game
void	cub_init_game_manager(t_game *game, t_cubval *cubval)
{
	ft_memset((void *)game, 0, sizeof(t_game));
	cub_init_graphics_manager(game, cubval);
	game->map = cub_init_map(cubval->map_str, cubval->max_xy, &game->player, &game->sprite);
	game->minimap.map = cub_init_map(cubval->map_str, cubval->max_xy, &game->player, &game->sprite);
	cub_init_minimap(&game->minimap);
	game->status = 1;
	game->fps.fps = 0;
	game->player.collected = 0;
	game->fps.frame = cub_get_time_ms();
	game->joists.rgb_floor = cub_init_colors(cubval->f);
	game->joists.rgb_ceiling = cub_init_colors(cubval->c);
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
