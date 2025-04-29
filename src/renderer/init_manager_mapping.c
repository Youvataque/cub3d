/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager_mapping.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:38:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 12:24:25 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to init a map
t_map	cub_init_map(char *source, t_point max, t_player *player)
{
	t_map	dest;
	int		i;

	dest.width = max.x;
	dest.height = max.y;
	dest.map = (char *)malloc(((max.x * max.y) + 1) * sizeof(char));
	if (!dest.map)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), dest);
	i = -1;
	while (++i < (max.x * max.y))
	{
		if (source[i] == 'N' || source[i] == 'S'
			|| source[i] == 'W' || source[i] == 'E')
		{
			cub_init_player_position(i, max.x, source[i], player);
			dest.map[i] = '0';
		}
		else
			dest.map[i] = source[i];
		// if (i == 5 * max.x + 26)
		// 	dest.map[i] = 'D';
	}
	dest.map[i] = '\0';
	return (dest);
}

// Function to init the player position
void	cub_init_player_position(int pos, int width, char orientation,
			t_player *player)
{
	player->pos.x = ((pos % width) * 64) + 0.1;
	player->pos.y = ((pos / width) * 64) + 0.1;
	if (orientation == 'N')
		player->angle = 0;
	else if (orientation == 'S')
		player->angle = 180;
	else if (orientation == 'W')
		player->angle = 270;
	else if (orientation == 'E')
		player->angle = 90;
	player->delta.x = cos(player->angle) * 5;
	player->delta.y = sin(player->angle) * 5;
}
