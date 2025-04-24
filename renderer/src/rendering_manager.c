/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 17:06:38 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to handle the rendering of the image
int	cub_rendering_manager(void *ptr_render)
{
    t_render	*render;
    int			x;

    render = (t_render *)ptr_render;
	render->img.ptr_img = mlx_new_image(render->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	render->img.addr = mlx_get_data_addr(render->img.ptr_img,
		&render->img.bpp, &render->img.line_len, &render->img.endian);
    x = -1;
	while (++x < SCREEN_WIDTH)
	{
		cub_raycasting_manager(render, x);
		cub_draw_vertical_line(&render->img, &render->ray, x);
	}
	render->old_frame = render->frame;
	render->frame = cub_get_time_ms();
	render->fps = (render->frame - render->frame) / 1000.0;
	mlx_put_image_to_window(render->mlx_ptr, render->win_ptr, render->img.ptr_img, 0, 0);
	mlx_destroy_image(render->mlx_ptr, render->img.ptr_img);
	return (0);
}