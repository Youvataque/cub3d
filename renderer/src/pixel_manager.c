/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:52:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 16:02:18 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to draw a pixel on the image
void	cub_draw_pixel(t_img_data *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

// Function to draw a vertical line on the image
void	cub_draw_vertical_line(t_img_data *img, t_ray *ray, int x)
{
	int	y;

	y = ray->draw_start - 1;
	while (++y <= ray->draw_end)
		cub_draw_pixel(img, x, y, ray->color);
}

// Function to draw an horizontal line on the image
void	cub_draw_horizontal_line(t_img_data *img, t_ray *ray, int y)
{
	int	x;

	x = ray->draw_start - 1;
	while (++x <= ray->draw_end)
		cub_draw_pixel(img, x, y, ray->color);
}