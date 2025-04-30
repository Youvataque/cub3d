/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:09:49 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/30 01:53:56 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to render sprites
void	cub_render_sprites(t_game *game, t_sprite *sprite, t_player *player)
{
	t_pos	pos;

	sprite->screen.x = sprite->pos.x - player->pos.x;
	sprite->screen.y = sprite->pos.y - player->pos.y;
	sprite->screen.z = sprite->pos.z;
	sprite->cosinus = cos(cub_degtorad(player->angle));
	sprite->sinus = sin(cub_degtorad(player->angle));
	sprite->a = sprite->screen.y * sprite->cosinus + sprite->screen.x * sprite->sinus;
	sprite->b = sprite->screen.x * sprite->cosinus + sprite->screen.y * sprite->sinus;
	sprite->screen.x = sprite->a;
	sprite->screen.y = sprite->b;
	sprite->screen.x = (sprite->screen.x * (64.0 * 2) / sprite->screen.y) + (FOV / 2);
	sprite->screen.y = (sprite->screen.z * (64.0 * 2) / sprite->screen.y) + (FOV - 40 / 2);
	pos.x = sprite->screen.x * 8;
	pos.y = sprite->screen.y * 8;
	if (sprite->screen.x > 0 && sprite->screen.x < FOV && sprite->b < sprite->depth[(int)sprite->screen.x])
		cub_draw_point(&game->img, pos, 8, cub_convert_glrgb(255, 255, 0, 1));
}
