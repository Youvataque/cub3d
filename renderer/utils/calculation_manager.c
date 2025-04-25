/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 03:20:04 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 17:33:23 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to convert degree to radian
double	cub_degree_to_radian(int degree)
{
	return (degree * (M_PI / 180.0));
}

// Function to fix the angle
int	cub_fix_angle(int angle)
{
	if (angle > 359)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

// Function to calculate the distance between two points
double	cub_calc_dist(t_pos a, t_pos b, double angle)
{
	return (cos(cub_degree_to_radian(angle)) * (b.x - a.x)
		- sin(cub_degree_to_radian(angle)) * (b.y - a.y));
}
