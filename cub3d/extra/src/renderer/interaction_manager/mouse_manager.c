/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:12:37 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/02 23:15:42 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to handle mouse rotation
int	cub_handle_mouse(int x, int y, t_game *game)
{
	static int	old_x = SCREEN_WIDTH / 2;

	(void)y;
	if (x == old_x)
		return (0);
	else if (x < old_x)
		cub_rotate_manager(&game->player, ROTATE_LEFT, game->player.speed / 15);
	else if (x > old_x)
		cub_rotate_manager(&game->player, ROTATE_RIGHT, \
			game->player.speed / 15);
	old_x = x;
	return (0);
}

// Function to handle the cross
int	cub_handle_cross(t_game *game)
{
	cub_free_manager(game);
	exit(0);
}
