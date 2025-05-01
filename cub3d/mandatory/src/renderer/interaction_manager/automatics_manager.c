/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automatics_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:27:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 17:14:14 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to automatically close the door behind the player
void	cub_automatics_close_door(t_player *player, t_sprite **sprites,
			t_map *map, t_map *minimap)
{
	t_point pos_map;

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
				if (cub_automatics_detect_player(player, map, &pos_map) == 1
					&& cub_automatics_detect_foe(&((*sprites)[1]), map, &pos_map) == 1)
				{
					map->map[(int)(pos_map.y * map->width + pos_map.x)] = 'D';
					map->door_opened = 0;
				}
			}
		}
	}
}

// Function to detect if there is a player neer the door
int	cub_automatics_detect_player(t_player *player, t_map *map,
			t_point *pos_map)
{
	int		mp_player;

	mp_player = (int)(player->pos.y / 64) * map->width + (int)(player->pos.x / 64);
	if (mp_player != pos_map->y * map->width + pos_map->x
		&& mp_player != (int)((pos_map->y - 1) * map->width + pos_map->x)
		&& mp_player != (int)((pos_map->y + 1) * map->width + pos_map->x)
		&& mp_player != (int)(pos_map->y * map->width + (pos_map->x + 1))
		&& mp_player != (int)(pos_map->y * map->width + (pos_map->x - 1)))
		return (1);
	return (0);
}

// Function to detect if there is a foe neer the door
int	cub_automatics_detect_foe(t_sprite *sprite, t_map *map,
			t_point *pos_map)
{
	int		mp_foe;
		
	mp_foe = (((int)((sprite->pos.y) / 64)) * 32
		+ ((int)((sprite->pos.x) / 64)));
	printf("y: %d | x: %d | mp: %d\n", (int)(sprite->pos.y / 64), (int)(sprite->pos.x / 64), mp_foe);
	if (mp_foe != pos_map->y * map->width + pos_map->x
		&& mp_foe != (int)((pos_map->y - 1) * map->width + pos_map->x)
		&& mp_foe != (int)((pos_map->y + 1) * map->width + pos_map->x)
		&& mp_foe != (int)(pos_map->y * map->width + (pos_map->x + 1))
		&& mp_foe != (int)(pos_map->y * map->width + (pos_map->x - 1)))
		return (1);
	return (0);
}
