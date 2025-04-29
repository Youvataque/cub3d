/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 07:39:19 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to init all
void	cub_init_manager(t_game *game, t_cubval *cubval)
{
	ft_memset((void *)game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->map = cub_init_map(cubval->map_str, cubval->max_xy, &game->player);
	game->tex_wall_north = cub_create_textures(cubval->path_n, (32 * 32) * 3);
	game->tex_wall_south = cub_create_textures(cubval->path_s, (32 * 32) * 3);
	game->tex_wall_east = cub_create_textures(cubval->path_e, (32 * 32) * 3);
	game->tex_wall_west = cub_create_textures(cubval->path_w, (32 * 32) * 3);
	game->tex_door = cub_create_textures(DOOR, (32 * 32) * 3);
	game->tex_sky_layers[0] = cub_create_textures(SKY_BACKGROUND, (576 * 324) * 3);
	game->tex_sky_layers[1] = cub_create_textures(SKY_MOON, (576 * 324) * 3);
	game->tex_sky_layers[2] = cub_create_textures(SKY_CLOUDS, (576 * 324) * 3);
	game->tex_sky = cub_join_textures(game->tex_sky_layers, (576 * 324) * 3, SKY_LAYERS);
	game->color_floor = cub_init_colors(cubval->f);
	game->color_ceiling = cub_init_colors(cubval->c);
}

// Function to join all textures in one
int	*cub_join_textures(int **textures, int size, int nbr)
{
	int	*joined;
	int	i;
	int	j;
	int	k;
	
	joined = (int *)malloc((size * nbr) * sizeof(int));
	if (!joined)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), textures[0]);
	j = 0;
	k = 0;
	while (j < nbr)
	{
		i = 0;
		while (i < size)
		{
			joined[k] = textures[j][i];
			i++;
			k++;
		}
		j++;
	}
	return (joined);
}

// Function to init colors
t_rgb	cub_init_colors(char *source)
{
	t_rgb	dest;
	int		i;

	i = -1;
	dest.red = 0;
	dest.green = 0;
	dest.blue = 0;
	while (source[++i] && source[i] != ',')
		dest.red = dest.red * 10 + source[i] - '0';
	while (source[++i] && source[i] != ',')
		dest.green = dest.green * 10 + source[i] - '0';
	while (source[++i] && source[i] != ',')
		dest.blue = dest.blue * 10 + source[i] - '0';
	return (dest);
}

// Function to init a map
t_map	cub_init_map(char *source, t_point max, t_player *player)
{
	t_map	dest;
	int		i;

	(void)player;
	dest.width = max.x;
	dest.height = max.y;
	dest.map = (char *)malloc(((max.x * max.y) + 1) * sizeof(char));
	if (!dest.map)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), dest);
	i = -1;
	while (++i < (max.x * max.y))
	{
		if (source[i] == ' ')
			dest.map[i] = '1';
		else if (source[i] == 'N' || source[i] == 'S' 
			|| source[i] == 'W' || source[i] == 'E')
		{
			cub_init_player_position(i, max.x, source[i], player);
			dest.map[i] = '0';
		}
		else
			dest.map[i] = source[i];
		if (i == 5 * max.x + 26)
			dest.map[i] = 'D';
	}
	dest.map[i] = '\0';
	return (dest);
}

// Function to init the player position
void	cub_init_player_position(int pos, int width, char orientation, t_player *player)
{
	player->pos.x = ((pos % width) * 64) + 0.1;
	player->pos.y = ((pos / width) * 64) + 0.1;
	if (orientation == 'N')
		player->angle = 0;
	else if (orientation == 'S')
		player->angle = 180;
	else if (orientation == 'W')
		player->angle = 270;
	else if (orientation == 'E')
		player->angle = 90;
	player->delta.x = cos(player->angle) * 5;
	player->delta.y = sin(player->angle) * 5;
}

// Function to create al textures
int *cub_create_textures(const char *file, int size)
{
	int 	*texture;
	int		fd;
	char	*line;
	int		t;

	texture = (int *)malloc(size * sizeof(int));
	if (!texture)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), texture);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(2, RED"Couldn't open file\n"RESET, 20), texture);
	t = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		texture[++t] = ft_atoi(line);
		free(line);
	}
	close(fd);
	return (texture);
}
