/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 16:51:51 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

// Function to init the rendering
void	cub_init_manager(t_render *render, int world[MAP_WIDTH][MAP_HEIGHT], void *mlx, void *win)
{
	int	x;
	int	y;
	 
	ft_memset((void *)render, 0, sizeof(t_render));
	render->cam.pos.x = 22;
	render->cam.pos.y = 12;
	render->cam.dir.x = -1;
	render->cam.plane.y = 0.66;
	y = -1;
	while (++y < MAP_WIDTH)
	{
		x = -1;
		while (++x < MAP_HEIGHT)
			render->world[y][x] = world[y][x];
	}
	render->mlx_ptr = mlx;
	render->win_ptr = win;
	return ;
}
