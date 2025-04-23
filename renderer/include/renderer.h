/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:52:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/24 00:36:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

// Libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <fcntl.h>
# include <math.h>

// Includes
	// MLX
# include "../../mlx/mlx.h"
# include "../../mlx/mlx_int.h"
	// LIBFT
# include "../../libft/headers/get_next_line_H/get_next_line.h"
# include "../../libft/headers/libft_H/libft.h"
	// OTHERS
# include "renderer_define.h"
# include "renderer_typedef.h"

// Functions
	// renderer.c

	// init_manager.c
void	cub_init_rendering(t_render *render, int world[MAP_WIDTH][MAP_HEIGHT], void *mlx, void *win);
	// pixel_manager.c
void	cub_draw_pixel(t_img_data *img, int x, int y, int color);
void	cub_draw_vertical_line(t_render *render, int x);
void	cub_draw_horizontal_line(t_render *render, int y);
	// raycasting_manager.c
void	cub_raycasting_manager(t_render *render, int x);
void	cub_setup_ray(t_render *render, int x);
void	cub_setup_dda(t_render *render);
void	cub_exec_dda(t_render *render);
void	cub_setup_drawing(t_render *render);
	// rendering_manager.c
int		cub_rendering_manager(void *ptr_render);
	// time_manager.c
int		cub_get_time_ms(void);
#endif