/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:23:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/03 08:26:28 by nifromon         ###   ########.fr       */
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
