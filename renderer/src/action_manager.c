/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 02:38:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 03:18:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to manage actions
void	cub_action_manager(int action, t_player *player, char *map)
{
	if (action == OPEN_DOOR)
		cub_action_open_door(player, map);
}

// Function to open the door
void	cub_action_open_door(t_player *player, char *map)
{
	t_collision	sensor;

	(void)map;
	sensor.xo = 25;
	sensor.yo = 25;
	if (player->delta.x < 0)
		sensor.xo = -25;
	if (player->delta.y < 0)
		sensor.yo = -25;
	sensor.ipx = (int)player->pos.x >> 6;
	sensor.ipy = (int)player->pos.y >> 6;
	sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
	sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
	if (map[sensor.ipy_plus_yo * MAP_WIDTH + sensor.ipx_plus_xo] == '4')
		map[sensor.ipy_plus_yo * MAP_WIDTH + sensor.ipx_plus_xo] = '0';
}