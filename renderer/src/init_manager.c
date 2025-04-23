/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/23 14:54:14 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to init the rendering
void	cub_init_rendering(t_render *render)
{
	render->spawn_pos.posX = 22;
	render->spawn_pos.posY = 12;
	render->spawn_dir.directionX = -1;
	render->spawn_dir.directionY = 0;
	render->cam_plane.cam_planeX = 0;
	render->cam_plane.cam_planeY = 0.66;
	render->frame.new = 0;
	render->frame.old = 0;
	render->camera.cameraX = 0;
	render->camera.cameraY = 0;
	render->ray_dir.directionX = 0;
	render->ray_dir.directionY = 0;
	render->delta.distanceX = 0;
	render->delta.distanceY = 0;
	render->map_pos.posX = 0;
	render->map_pos.posY = 0;
	render->side.distanceX = 0;
	render->side.distanceY = 0;
	render->step.stepX = 0;
	render->step.stepY = 0;
	return ;
}
