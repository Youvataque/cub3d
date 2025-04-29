/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:34:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 02:59:04 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to move left
void cub_move_left(t_player *player, double speed, t_map *map)
{
    t_collision sensor;

    sensor.xo = player->delta.y * 20;
    sensor.yo = -player->delta.x * 20;
    if (sensor.xo < 0)
        sensor.xo = -20;
    else
        sensor.xo = 20;
    if (sensor.yo < 0)
        sensor.yo = -20;
    else
        sensor.yo = 20;
    sensor.ipx = (int)player->pos.x >> 6;
    sensor.ipy = (int)player->pos.y >> 6;
    sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
    sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
    if (map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == '0')
        player->pos.x += player->delta.y * speed;
    if (map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == '0')
        player->pos.y -= player->delta.x * speed;
}


// Function to move right
void cub_move_right(t_player *player, double speed, t_map *map)
{
    t_collision sensor;

    sensor.xo = -player->delta.y * 20;
    sensor.yo = player->delta.x * 20;
    if (sensor.xo < 0)
        sensor.xo = -20;
    else
        sensor.xo = 20;
    if (sensor.yo < 0)
        sensor.yo = -20;
    else
        sensor.yo = 20;
    sensor.ipx = (int)player->pos.x >> 6;
    sensor.ipy = (int)player->pos.y >> 6;
    sensor.ipx_plus_xo = ((int)player->pos.x + sensor.xo) >> 6;
    sensor.ipy_plus_yo = ((int)player->pos.y + sensor.yo) >> 6;
    if (map->map[sensor.ipy * map->width + sensor.ipx_plus_xo] == '0')
        player->pos.x -= player->delta.y * speed;
    if (map->map[sensor.ipy_plus_yo * map->width + sensor.ipx] == '0')
        player->pos.y += player->delta.x * speed;
}


