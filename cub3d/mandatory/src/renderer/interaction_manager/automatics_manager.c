/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automatics_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:27:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 01:46:01 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to automatically close the door behind the player
void	cub_automatics_close_door(t_player *player, t_map *map, t_map *minimap)
{
	t_point pos_map;
	int		mp_up;
	int		mp_down;
	int		mp_right;
	int		mp_left;
	int		mp_player;

	if (map->door_opened == 0)
		return ;
	pos_map.y = -1;
	while (++pos_map.y < map->height)
	{
		pos_map.x = -1;
		while (++pos_map.x < map->width)
		{
			if (minimap->map[(int)(pos_map.y * map->width + pos_map.x)] == 'D' 
				&& map->map[(int)(pos_map.y * map->width  + pos_map.x)] == '0')
			{
				mp_player = (int)(player->pos.y / 64) * map->width + (int)(player->pos.x / 64);
				mp_up = (int)((pos_map.y - 1) * map->width + pos_map.x);
				mp_down = (int)((pos_map.y + 1) * map->width + pos_map.x);
				mp_right = (int)(pos_map.y * map->width + (pos_map.x + 1));
				mp_left = (int)(pos_map.y * map->width + (pos_map.x - 1));
				if (mp_player != pos_map.y * map->width + pos_map.x
					&& mp_player != mp_up && mp_player != mp_down
					&& mp_player != mp_right && mp_player != mp_left)
				{
					map->map[pos_map.y * map->width + pos_map.x] = 'D';
					map->door_opened = 0;
				}
			}
		}
	}
}
