/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:36:40 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 17:23:37 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to manage all functions related to raycasting
void	cub_raycasting_manager(t_render *render, int x)
{
	cub_setup_ray(&render->ray, &render->cam, x);
	cub_setup_dda(&render->ray, &render->cam);
	cub_exec_dda(render, &render->ray);
	cub_setup_drawing(render, &render->ray);
}

// Function to setup the rays
void	cub_setup_ray(t_ray *ray, t_camera *cam, int x)
{
	ray->cam_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dir.x = cam->dir.x + cam->plane.x * ray->cam_x;
	ray->dir.y = cam->dir.y + cam->plane.y * ray->cam_x;
	ray->map.x = (int)cam->pos.x;
	ray->map.y = (int)cam->pos.y;
	if (ray->dir.x == 0)
		ray->delta_dist.x = INFINITE_DISTANCE;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = INFINITE_DISTANCE;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

// Function to setup the Digital Differential Analysis
void	cub_setup_dda(t_ray *ray, t_camera *cam)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (cam->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (cam->pos.x + 1.0 - ray->map.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (cam->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (cam->pos.y + 1.0 - ray->map.y) * ray->delta_dist.y;
	}
}

// Function to execute the Digital Differential Analysis
void	cub_exec_dda(t_render *render, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (render->world[ray->map.y][ray->map.x] > 0)
			hit = 1;
	}
}

// Function to setup everything before drawing
void	cub_setup_drawing(t_render *render, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	ray->line_height = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw_end >= SCREEN_HEIGHT)
		ray->draw_end = SCREEN_HEIGHT - 1;
	if (render->world[ray->map.y][ray->map.x] == 1)
		ray->color = 0xFF0000; // Red
	else if (render->world[ray->map.y][ray->map.x] == 2)
		ray->color = 0x00FF00; // Green
	else if (render->world[ray->map.y][ray->map.x] == 3)
		ray->color = 0x0000FF; // Blue
	else if (render->world[ray->map.y][ray->map.x] == 4)
		ray->color = 0xFFFFFF; // White
	else
		ray->color = 0xFFFF00; // Yellow
	if (ray->side == 1)
		ray->color /= 2;
}
