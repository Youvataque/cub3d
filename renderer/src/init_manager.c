/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/26 17:06:00 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to init all
void	cub_init_manager(t_game *game)
{
	ft_memset((void *)game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->player.pos.x = 300;
	game->player.pos.y = 300;
	game->player.delta.x = cos(game->player.angle) * 5;
	game->player.delta.y = sin(game->player.angle) * 5;
	game->map = cub_create_map();
}

// Function to create a map
char	*cub_create_map(void)
{
	char	*map;

	map = "1111111110100001101000011010000110000001100001011000000111111111";
	// map = "11111111
	// 	      10100001
	// 	      10100001
	// 	      10100001
	// 	      10000001
	// 	      10000101
	// 	      10000001
	// 	      11111111";
	return (map);
}
