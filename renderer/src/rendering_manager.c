/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 23:54:00 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 00:50:09 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to handle the rendering of the image
int	cub_rendering_manager(void *ptr_render)
{
    t_render	*render;
    int			x;

    render = (t_render *)ptr_render;
    x = -1;
	while (++x < SCREEN_WIDTH)
	{
		cub_raycasting_manager(render, x);
		cub_draw_vertical_line(render, x);
	}
	render->frame.old = render->frame.new;
	render->frame.new = cub_get_time_ms();
    render->fps = (render->frame.new - render->frame.old) / 1000.0;
    mlx_put_image_to_window(render->mlx_ptr, render->win_ptr, render->img.ptr_img, 0, 0);
    mlx_clear_window(render->mlx_ptr, render->win_ptr);
    return (0);
}