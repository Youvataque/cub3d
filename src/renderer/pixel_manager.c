/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:52:02 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/28 15:34:08 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to draw a pixel on the image
void	cub_draw_pixel(t_img_data *img, int x, int y, int color)
{
	int	pixel;

	if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT || x < 0 || y < 0)
		return ;
	pixel = y * img->line_len + x * (img->bpp / 8);
	img->addr[pixel] = color & 0xFF;
	img->addr[pixel + 1] = (color >> 8) & 0xFF;
	img->addr[pixel + 2] = (color >> 16) & 0xFF;
}

// Function to draw lines with thickness
void	cub_draw_thick_line(t_img_data *img, t_segment *segment, int size,
			int color)
{
	t_pos	start;
	t_pos	end;
	int	i;
	int	j;
	int	half_size;

	half_size = size / 2;
	j = -half_size - 1;
	while (++j <= half_size)
	{
		i = -half_size - 1;
		while (++i <= half_size)
		{
			start.x = segment->start.x + i;
			start.y = segment->start.y + j;
			end.x = segment->end.x + i;
			end.y = segment->end.y + j;
			cub_draw_line(img, start, end, color);
		}
	}
}

// Function to draw a point of fixed size
void	cub_draw_point(t_img_data *img, t_pos pos, int size, int color)
{
	int	half_size;
	int	i;
	int	j;

	half_size = size / 2;
	j = -half_size - 1;
	while (++j <= half_size)
	{
		i = -half_size - 1;
		while (++i <= half_size)
			cub_draw_pixel(img, pos.x + i, pos.y + j, color);
	}
}

// Function to draw a line between two points using bresenham's line algorithm
void	cub_draw_line(t_img_data *img, t_pos start, t_pos end, int color)
{
	t_pos	delta;
	t_pos	pixel;
	int		lenght;

	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	lenght = sqrt(pow(delta.x, 2) + pow(delta.y, 2));
	delta.x /= lenght;
	delta.y /= lenght;
	pixel.x = start.x;
	pixel.y = start.y;
	while (lenght)
	{
		cub_draw_pixel(img, pixel.x, pixel.y, color);
		pixel.x += delta.x;
		pixel.y += delta.y;
		lenght--;
	}
}

// Function to draw a square
void	cub_draw_square(t_img_data *img, t_pos pos, int size, int color)
{
	int	i;

	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x + i, pos.y, color);
	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x, pos.y + i, color);
	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x + size, pos.y + i, color);
	i = -1;
	while (++i < size)
		cub_draw_pixel(img, pos.x + i, pos.y + size, color);
}
