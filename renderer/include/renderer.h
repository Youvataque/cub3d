/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:52:59 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/23 14:54:59 by nifromon         ###   ########.fr       */
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
	// main.c

	// init_manager.c
void	cub_init_rendering(t_render *render);

#endif