/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:36:35 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 17:54:26 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to handle all interactions
void	cub_interaction_manager(t_render *render)
{
	mlx_hook(render->win_ptr, 3, (1L << 1), &cub_handle_keys, render);
	mlx_hook(render->win_ptr, 17, (1L << 17), &cub_handle_cross, render);
}

// Function to handle keys
int	cub_handle_keys(int key, t_render *render)
{
	printf("KEY PRESSED: [%d]\n", key);
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		cub_movement_manager(MOVE_FORWARD, render, &render->cam);
	else if (key == KEY_S)
		cub_movement_manager(MOVE_BACKWARD, render, &render->cam);
	else if (key == KEY_D)
		cub_movement_manager(ROTATE_RIGHT, render, &render->cam);
	else if (key == KEY_A)
		cub_movement_manager(ROTATE_LEFT, render, &render->cam);
	cub_rendering_manager((void *)render);
	return (0);
}

// Function to handle cross
int	cub_handle_cross(t_render *render)
{
	(void)render;
	exit(0);
	return (0);
}
