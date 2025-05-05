/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:23:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/05 15:54:07 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to free all memory
void	cub_free_manager(t_game *game)
{
	free(game->depth);
	free(game->map.map);
	free(game->minimap.map.map);
	cub_free_graphics(game);
	cub_free_sprites(&game->sprite);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

// Function to free all graphics
void	cub_free_graphics(t_game *game)
{
	free(game->walls.tex_leave);
	free(game->walls.tex_door);
	free(game->walls.tex_west);
	free(game->walls.tex_east);
	free(game->walls.tex_south);
	free(game->walls.tex_north);
	free(game->sky.tex);
	free(game->screen.tex);
	free(game->joists.tex_leave);
	free(game->glock.texture);
}

// Function to free all sprites
void	cub_free_sprites(t_sprite **sprites)
{
	int	i;

	i = -1;
	while (++i < (*sprites)[0].nbr_sprites)
	{
		if ((*sprites)[i].texture)
			free((*sprites)[i].texture);
	}
	free((*sprites));
}
