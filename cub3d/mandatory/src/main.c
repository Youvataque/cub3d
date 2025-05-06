/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/06 16:13:56 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// main of cub3D
int	main(int ac, char **av)
{
	t_cubval	*cubval;
	t_game		game;

	(void)game;
	if (ac == 2)
	{
		cubval = get_map_param(av[1]);
		if (!cubval)
			return (printf("Error: bad maps.\n"), 1);
		cub_init_game_manager(&game, cubval);
		mlx_loop_hook(game.mlx, &cub_game_manager, &game);
		cub_interaction_manager(&game);
		mlx_loop(game.mlx);
		clean_tcubval(cubval);
		return (0);
	}
	return (printf("Error: bad args.\n"), 1);
}
