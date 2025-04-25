/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:59:25 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/25 17:34:18 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	(void)argv;
	if (argc != 1)
		return (write(2, RED"Incorrect Number of Arguments\n"RESET, 30), 1);
	cub_init_manager(&game);
	mlx_loop_hook(game.mlx, &cub_rendering_manager, &game);
	cub_interaction_manager(&game);
	mlx_loop(game.mlx);
	return (0);
}
