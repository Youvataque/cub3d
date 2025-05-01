/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_foe_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:22:38 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/01 11:58:58 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to make the foe follow the player
void	cub_foe_pursuit(t_game *game, t_sprite *sprite, t_player *player)
{
	t_point	pos;
	t_point	offset_add;
	t_point	offset_sub;
	
	if (sprite->type != 'A')
		return ;
	pos.x = (int)sprite->pos.x >> 6;
	pos.y = (int)sprite->pos.y >> 6;
	offset_add.x = ((int)sprite->pos.x + 15) >> 6;
	offset_add.y = ((int)sprite->pos.y + 15) >> 6;
	offset_sub.x = ((int)sprite->pos.x - 15) >> 6;
	offset_sub.y = ((int)sprite->pos.y - 15) >> 6;
	if (game->map.map[pos.y * game->map.width + offset_sub.x] == '0'
		&& sprite->pos.x > player->pos.x)
		sprite->pos.x -= 0.03 * game->fps.fps;
	if (game->map.map[pos.y * game->map.width + offset_add.x] == '0'
		&& sprite->pos.x < player->pos.x)
		sprite->pos.x += 0.03 * game->fps.fps;
	if (game->map.map[offset_sub.y * game->map.width + pos.x] == '0'
		&& sprite->pos.y > player->pos.y)
		sprite->pos.y -= 0.03 * game->fps.fps;
	if (game->map.map[offset_add.y * game->map.width + pos.x] == '0'
		&& sprite->pos.y < player->pos.y)
		sprite->pos.y += 0.03 * game->fps.fps;
}
