/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automatics_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:27:47 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 12:21:42 by nifromon         ###   ########.fr       */
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
int	cub_automatics_detect_foe(t_sprite **sprites, t_map *map,
			t_point *pos_map)
{
	int		mp_foe;
	int		i;

	i = -1;
	while (++i < ((*sprites)[0]).nbr_foes)
	{
		mp_foe = (int)(((*sprites)[i]).pos.y / 64) * map->width
			+ (int)(((*sprites)[i]).pos.x / 64);
		if (mp_foe != pos_map->y * map->width + pos_map->x
			&& mp_foe != (int)((pos_map->y - 1) * map->width + pos_map->x)
			&& mp_foe != (int)((pos_map->y + 1) * map->width + pos_map->x)
			&& mp_foe != (int)(pos_map->y * map->width + (pos_map->x + 1))
			&& mp_foe != (int)(pos_map->y * map->width + (pos_map->x - 1)))
			return (1);
	}
	return (0);
}
