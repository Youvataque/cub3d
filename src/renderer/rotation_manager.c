/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:24:48 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 08:25:30 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to rotate right
void	cub_rotate_right(t_player *player, float speed)
{
	player->angle -= speed / 1.5;
	player->angle = cub_fixang(player->angle);
	player->delta.x = cos(cub_degtorad(player->angle));
	player->delta.y = -sin(cub_degtorad(player->angle));
}

// Function to rotate left
void	cub_rotate_left(t_player *player, float speed)
{
	player->angle += speed / 1.5;
	player->angle = cub_fixang(player->angle);
	player->delta.x = cos(cub_degtorad(player->angle));
	player->delta.y = -sin(cub_degtorad(player->angle));
}
