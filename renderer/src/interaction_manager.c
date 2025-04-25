/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:36:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 17:39:19 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to handle interactions with the user
void	cub_interaction_manager(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), &cub_handle_key_press, game);
	mlx_hook(game->win, 3, (1L << 1), &cub_handle_key_release, game);
	mlx_hook(game->win, 17, (1L << 17), &cub_handle_cross, game);
}

// Function to update movement of the player
void	cub_movement_update(t_keys *keys, t_player *player)
{
	if (keys->w == 1)
		cub_movement_manager(player, MOVE_FORWARD);
	if (keys->a == 1)
		cub_movement_manager(player, ROTATE_LEFT);
	if (keys->s == 1)
		cub_movement_manager(player, MOVE_BACKWARD);
	if (keys->d == 1)
		cub_movement_manager(player, ROTATE_RIGHT);
}

// Function to handle keys
int	cub_handle_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		game->keys.w = 1;
	else if (key == KEY_A)
		game->keys.a = 1;
	else if (key == KEY_S)
		game->keys.s = 1;
	else if (key == KEY_D)
		game->keys.d = 1;
	return (0);
}

int	cub_handle_key_release(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		game->keys.w = 0;
	else if (key == KEY_A)
		game->keys.a = 0;
	else if (key == KEY_S)
		game->keys.s = 0;
	else if (key == KEY_D)
		game->keys.d = 0;
	return (0);
}

// Function to handle the cross
int	cub_handle_cross(t_game *game)
{
	(void)game;
	exit(0);
}
