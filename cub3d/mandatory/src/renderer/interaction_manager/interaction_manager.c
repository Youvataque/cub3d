/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:36:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 02:10:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to handle interactions with the user
void	cub_interaction_manager(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), &cub_handle_key_press, game);
	mlx_hook(game->win, 3, (1L << 1), &cub_handle_key_release, game);
	mlx_hook(game->win, 17, (1L << 17), &cub_handle_cross, game);
	mlx_hook(game->win, 6, (1L << 6), &cub_handle_mouse, game);
}

// Function to handle mouse rotation
int	cub_handle_mouse(int x, int y, t_game *game)
{
	static int	old_x = SCREEN_WIDTH / 2;
	
	(void)y;
	if (x == old_x)
		return (0);
	else if (x < old_x)
		cub_rotate_manager(&game->player, ROTATE_LEFT, game->player.speed / 15);
	else if (x > old_x)
		cub_rotate_manager(&game->player, ROTATE_RIGHT, game->player.speed / 15);
	old_x = x;
	return (0);
}

// Function to update movement of the player
void	cub_movement_update(t_keys *keys, t_player *player, t_map *map)
{
	if (keys->w == 1)
		cub_movement_manager(player, MOVE_FORWARD, player->speed, map);
	if (keys->a == 1)
		cub_movement_manager(player, MOVE_LEFT, player->speed, map);
	if (keys->s == 1)
		cub_movement_manager(player, MOVE_BACKWARD, player->speed, map);
	if (keys->d == 1)
		cub_movement_manager(player, MOVE_RIGHT, player->speed, map);
	if (keys->arrow_left == 1)
		cub_rotate_manager(player, ROTATE_LEFT, player->speed);
	if (keys->arrow_right == 1)
		cub_rotate_manager(player, ROTATE_RIGHT, player->speed);
}

// Function to handle keys
int	cub_handle_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		game->keys.w = 1;
	else if (key == KEY_ARROW_LEFT)
		game->keys.arrow_left = 1;
	else if (key == KEY_S)
		game->keys.s = 1;
	else if (key == KEY_ARROW_RIGHT)
		game->keys.arrow_right = 1;
	else if (key == KEY_A)
		game->keys.a = 1;
	else if (key == KEY_D)
		game->keys.d = 1;
	else if (key == KEY_E)
		cub_action_manager(OPEN_DOOR, &game->player, &game->map);
	return (0);
}

int	cub_handle_key_release(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		game->keys.w = 0;
	else if (key == KEY_ARROW_LEFT)
		game->keys.arrow_left = 0;
	else if (key == KEY_S)
		game->keys.s = 0;
	else if (key == KEY_ARROW_RIGHT)
		game->keys.arrow_right = 0;
	else if (key == KEY_A)
		game->keys.a = 0;
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
