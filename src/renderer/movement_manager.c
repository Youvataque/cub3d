/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:13 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 02:56:42 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to handle movements
void	cub_movement_manager(t_player *player, int move, double speed,
			t_map *map)
{
	if (move == MOVE_FORWARD)
		cub_move_forward(player, speed, map);
	else if (move == MOVE_BACKWARD)
		cub_move_backward(player, speed, map);
	else if (move == MOVE_LEFT)
		cub_move_left(player, speed, map);
	else if (move == MOVE_RIGHT)
		cub_move_right(player, speed, map);
	else if (move == ROTATE_RIGHT)
		cub_rotate_right(player, speed);
	else if (move == ROTATE_LEFT)
		cub_rotate_left(player, speed);
}

// Function to move forward
void	cub_move_forward(t_player *player, double speed, t_map *map)
{
	t_collision	sensor;

	sensor.xo = 20;
	sensor.yo = 20;
	if (player->delta.x < 0)
		sensor.xo = -20;
	if (player->delta.y < 0)
		sensor.yo = -20;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
	sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
	if (map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == '0')
		player->pos.x += player->delta.x * speed;
	if (map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == '0')
		player->pos.y += player->delta.y * speed;
}

// Function to move backward
void	cub_move_backward(t_player *player, double speed, t_map *map)
{
	t_collision	sensor;

	sensor.xo = 20;
	sensor.yo = 20;
	if (player->delta.x < 0)
		sensor.xo = -20;
	if (player->delta.y < 0)
		sensor.yo = -20;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_minus_xo = ((int)player->pos.x - sensor.xo) >> 6;
	sensor.ipy_minus_yo = ((int)player->pos.y - sensor.yo) >> 6;
	if (map->map[sensor.ipy * map->width + sensor.ipx_minus_xo] == '0')
		player->pos.x -= player->delta.x * speed;
	if (map->map[sensor.ipy_minus_yo * map->width + sensor.ipx] == '0')
		player->pos.y -= player->delta.y * speed;
}

// Function to rotate right
void	cub_rotate_right(t_player *player, double speed)
{
	player->angle -= speed;
	player->angle = cub_fixang(player->angle);
	player->delta.x = cos(cub_degtorad(player->angle));
	player->delta.y = -sin(cub_degtorad(player->angle));
}

// Function to rotate left
void	cub_rotate_left(t_player *player, double speed)
{
	player->angle += speed;
	player->angle = cub_fixang(player->angle);
	player->delta.x = cos(cub_degtorad(player->angle));
	player->delta.y = -sin(cub_degtorad(player->angle));
}
