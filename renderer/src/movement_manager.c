/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:13 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 19:58:30 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to handle movements
void	cub_movement_manager(t_player *player, int move, double speed,
			char *map)
{
	if (move == MOVE_FORWARD)
		cub_move_forward(player, speed, map);
	else if (move == MOVE_BACKWARD)
		cub_move_backward(player, speed, map);
	else if (move == ROTATE_RIGHT)
		cub_rotate_right(player, speed);
	else if (move == ROTATE_LEFT)
		cub_rotate_left(player, speed);
}

// Function to move forward
void	cub_move_forward(t_player *player, double speed, char *map)
{
	t_pos	collision_offset;
	t_pos	i_player_pos;
	t_pos	i_add_offset;

	collision_offset.x = 0;
	collision_offset.y = 0;
	if (player->delta.x < 0)
		collision_offset.x = -20;
	else
		collision_offset.x = 20;
	if (player->delta.y < 0)
		collision_offset.y = -20;
	else
		collision_offset.y = 20;
	i_player_pos.x = (int)player->pos.x / 64.0;
	i_player_pos.y = (int)player->pos.y / 64.0;
	i_add_offset.x = (int)(player->pos.x + collision_offset.x) / 64.0;
	i_add_offset.y = (int)(player->pos.y + collision_offset.y) / 64.0;
	if (map[(int)(i_player_pos.y * MAP_WIDTH + i_add_offset.x)] == '0')
		player->pos.x += player->delta.x * speed;
	if (map[(int)(i_add_offset.y * MAP_WIDTH + i_player_pos.x)] == '0')
		player->pos.y += player->delta.y * speed;
}

// Function to move backward
void	cub_move_backward(t_player *player, double speed, char *map)
{
	t_pos	collision_offset;
	t_pos	i_player_pos;
	t_pos	i_sub_offset;

	collision_offset.x = 0;
	collision_offset.y = 0;
	if (player->delta.x < 0)
		collision_offset.x = -20;
	else
		collision_offset.x = 20;
	if (player->delta.y < 0)
		collision_offset.y = -20;
	else
		collision_offset.y = 20;
	i_player_pos.x = (int)player->pos.x / 64.0;
	i_player_pos.y = (int)player->pos.y / 64.0;
	i_sub_offset.x = (player->pos.x - collision_offset.x) / 64.0;
	i_sub_offset.y = (player->pos.y - collision_offset.y) / 64.0;
	if (map[(int)(i_player_pos.y * MAP_WIDTH + i_sub_offset.x)] == '0')
		player->pos.x -= player->delta.x * speed;
	if (map[(int)(i_sub_offset.y * MAP_WIDTH + i_player_pos.x)] == '0')
		player->pos.y -= player->delta.y * speed;
}

// Function to rotate right
void	cub_rotate_right(t_player *player, double speed)
{
	player->angle -= speed;
	player->angle = cub_fix_angle(player->angle);
	player->delta.x = cos(cub_degree_to_radian(player->angle));
	player->delta.y = -sin(cub_degree_to_radian(player->angle));
}

// Function to rotate left
void	cub_rotate_left(t_player *player, double speed)
{
	player->angle += speed;
	player->angle = cub_fix_angle(player->angle);
	player->delta.x = cos(cub_degree_to_radian(player->angle));
	player->delta.y = -sin(cub_degree_to_radian(player->angle));
}
