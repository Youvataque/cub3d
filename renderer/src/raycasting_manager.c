/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:36:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 00:59:41 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to manage all functions related to raycasting
void	cub_raycasting_manager(t_render *render, int x)
{
	cub_setup_ray(render, x);
	cub_setup_dda(render);
	cub_exec_dda(render);
	cub_setup_drawing(render);
}

// Function to setup the rays
void	cub_setup_ray(t_render *render, int x)
{
	render->camera.camX = 2 * x / (double)SCREEN_WIDTH - 1;
	render->ray_vector.vectorX = render->init_gaze.vectorX \
								+ render->cam_plane.planeX \
								* render->camera.camX;
	render->ray_vector.vectorY = render->init_gaze.vectorY \
								+ render->cam_plane.planeY \
								* render->camera.camY;
	render->map_pos.mapX = (int)render->init_pos.posX;
	render->map_pos.mapY = (int)render->init_pos.posY;
	if (render->ray_vector.vectorX == 0)
		render->delta.distX = INFINITE_DISTANCE;
	else
		render->delta.distX = sqrt(1 + pow(render->ray_vector.vectorY, 2)
							/ pow(render->ray_vector.vectorX, 2));
	if (render->ray_vector.vectorY == 0)
		render->delta.distY = INFINITE_DISTANCE;
	else
		render->delta.distX = sqrt(1 + pow(render->ray_vector.vectorX, 2)
							/ pow(render->ray_vector.vectorY, 2));
}

// Function to setup the Digital Differential Analysis
void	cub_setup_dda(t_render *render)
{
	if (render->ray_vector.vectorX < 0)
	{
		render->step.stepX = -1;
		render->side.distX = (render->init_pos.posX - render->map_pos.mapX)
							* render->delta.distX;
	}
	else
	{
		render->step.stepX = 1;
		render->side.distX = (render->init_pos.posX + 1 - render->map_pos.mapX)
							* render->delta.distX;
	}
	if (render->ray_vector.vectorY < 0)
	{
		render->step.stepY = -1;
		render->side.distY = (render->init_pos.posY - render->map_pos.mapY)
								* render->delta.distY;
	}
	else
	{
		render->step.stepY = 1;
		render->side.distY = (render->init_pos.posX + 1 - render->map_pos.mapX)
								* render->delta.distX;
	}
}

// Function to execute the Digital Differential Analysis
void	cub_exec_dda(t_render *render)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (render->side.distX < render->side.distY)
		{
			render->side.distX += render->delta.distX;
			render->map_pos.mapX += render->step.stepX;
			side = 0;
		}
		else
		{
			render->side.distY += render->delta.distY;
			render->map_pos.mapY += render->step.stepY;
			side = 1;
		}
		if (*render->world[render->map_pos.mapX][render->map_pos.mapY] > 0)
			hit = 1;
	}
	if (side == 0)
		render->perp_wall_dist = (render->side.distX - render->delta.distX);
	else
		render->perp_wall_dist = (render->side.distY - render->delta.distY);
}

// Function to setup everything before drawing
void	cub_setup_drawing(t_render *render)
{
	render->line_height = (int)(SCREEN_HEIGHT / render->perp_wall_dist);
	render->draw_start = -render->line_height / 2 + SCREEN_HEIGHT / 2;
	if (render->draw_start < 0)
		render->draw_start = 0;
	render->draw_end = render->line_height / 2 + SCREEN_HEIGHT / 2;
	if (render->draw_end >= SCREEN_HEIGHT)
		render->draw_end = SCREEN_HEIGHT - 1;
	if (*render->world[render->map_pos.mapX][render->map_pos.mapY] == 1)
		render->color = 0xFF0000; // Red
	else if (*render->world[render->map_pos.mapX][render->map_pos.mapY] == 2)
		render->color = 0x00FF00; // Green
	else if (*render->world[render->map_pos.mapX][render->map_pos.mapY] == 3)
		render->color = 0x0000FF; // Blue
	else if (*render->world[render->map_pos.mapX][render->map_pos.mapY] == 4)
		render->color = 0xFFFFFF; // White
	else
		render->color = 0xFFFF00; // Yellow
}
