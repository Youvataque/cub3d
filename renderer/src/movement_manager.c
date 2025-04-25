/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:37:13 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 13:08:30 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to handle movements
void	cub_movement_manager(t_player *player, int move)
{
	if (move == MOVE_FORWARD)
		cub_move_forward(player);
	else if (move == MOVE_BACKWARD)
		cub_move_backward(player);
	else if (move == ROTATE_RIGHT)
		cub_rotate_right(player);
	else if (move == ROTATE_LEFT)
		cub_rotate_left(player);
}

// Function to move forward
void	cub_move_forward(t_player *player)
{
	player->pos.x += player->delta.x;
	player->pos.y += player->delta.y;
}

// Function to move backward
void	cub_move_backward(t_player *player)
{
	player->pos.x -= player->delta.x;
	player->pos.y -= player->delta.y;
}

// Function to rotate right
void	cub_rotate_right(t_player *player)
{
	player->angle -= 1;
	player->angle = cub_fix_angle(player->angle);
	player->delta.x = cos(cub_degree_to_radian(player->angle));
	player->delta.y = -sin(cub_degree_to_radian(player->angle));
}

// Function to rotate left
void	cub_rotate_left(t_player *player)
{
	player->angle += 1;
	player->angle = cub_fix_angle(player->angle);
	player->delta.x = cos(cub_degree_to_radian(player->angle));
	player->delta.y = -sin(cub_degree_to_radian(player->angle));
}
