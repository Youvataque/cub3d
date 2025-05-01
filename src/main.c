/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/01 13:08:14 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void bazard_test(t_cubval *p)
{
	int	i;

	if (!p)
	{
		printf("❌ Structure NULL\n");
		return ;
	}
	printf("Textures :\n");
	printf("%s\n", p->path_n ? p->path_n : "(null)");
	printf("%s\n", p->path_s ? p->path_s : "(null)");
	printf("%s\n", p->path_w ? p->path_w : "(null)");
	printf("%s\n", p->path_e ? p->path_e : "(null)");
	printf("%d - %d", p->nb_col, p->nb_foe);
	printf("\nCouleurs :\n");
	printf("%s\n", p->f ? p->f : "(null)");
	printf("%s\n", p->c ? p->c : "(null)");

	printf("\nMap :\n");
	if (!p->map)
		printf("  (null)\n");
	else
	{
		i = 0;
		while (p->map[i])
		{
			printf("X %s X\n", p->map[i]);
			i++;
		}
	}
}

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
		bazard_test(cubval);
		if (!cubval)
			return (1);
		cub_init_manager(&game, cubval);
		mlx_loop_hook(game.mlx, &cub_rendering_manager, &game);
		cub_interaction_manager(&game);
		mlx_loop(game.mlx);
		clean_tcubval(cubval);
		return (0);
	}
	return (printf("Error: bad args."), 1);
}
