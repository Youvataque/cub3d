/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:23:12 by nifromon          #+#    #+#             */
/*   Updated: 2025/05/02 22:23:58 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub.h"

// Function to free all memory
void	cub_free_manager(t_game *game)
{
	free(game->depth);
	free(game->map.map);
	free(game->minimap.map.map);
	cub_free_graphics(&game->walls, &game->sky, &game->screen, &game->joists);
	cub_free_sprites(&game->sprite);
}

// Function to free all graphics
void	cub_free_graphics(t_walls *walls, t_sky *sky, t_screen *screen,
			t_joists *joists)
{
	free(walls->tex_leave);
	free(walls->tex_door);
	free(walls->tex_west);
	free(walls->tex_east);
	free(walls->tex_south);
	free(walls->tex_north);
	free(sky->tex);
	free(screen->tex);
	free(joists->tex_leave);
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
