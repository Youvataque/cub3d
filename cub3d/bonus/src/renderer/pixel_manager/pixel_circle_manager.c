/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_circle_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:20:14 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/30 22:50:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Draw the circle of the minimap border
void	cub_draw_empty_circle(t_img_data *img, t_pos center, int radius,
			int color)
{
	int x, y;
	int dx, dy;
	int r2 = radius * radius;
	int thickness = 2;

	for (y = -radius; y <= radius; y++)
	{
		for (x = -radius; x <= radius; x++)
		{
			dx = center.x + x;
			dy = center.y + y;
			int dist2 = x * x + y * y;
			if (dist2 >= r2 - thickness * radius && dist2 <= r2 + thickness * radius)
				cub_draw_pixel(img, dx, dy, color);
		}
	}
}
