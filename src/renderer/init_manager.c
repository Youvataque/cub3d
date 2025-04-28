/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/28 15:54:31 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to print a map
void	cub_print_map(const char *map)
{
	int	i;
	int	div;

	i = -1;
	div = 1;
	while (++i < MAP_WIDTH * MAP_HEIGHT)
	{
		if (i / div == MAP_WIDTH)
		{
			printf("\n");
			div++;
		}
		printf("%c", map[i]);
	}
}


// Function to init all
void	cub_init_manager(t_game *game, t_cubval *cubval)
{
	ft_memset((void *)game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->player.pos.x = 300;
	game->player.pos.y = 300;
	game->player.delta.x = cos(game->player.angle) * 5;
	game->player.delta.y = sin(game->player.angle) * 5;
	game->map_walls = cubval->map_str;
	game->map_ceilings = cubval->map_str;
	game->map_floors = cubval->map_str;
	game->textures = (int **)malloc(5 * sizeof(int *));
	if (!game->textures)
		return ((void)write(2, RED"Failed to allocate memory\n"RESET, 27));
	game->textures[0] = cub_create_textures(cubval->path_n, (32 * 32) * 3);
	game->textures[1] = cub_create_textures(cubval->path_o, (32 * 32) * 3);
	game->textures[2] = cub_create_textures(cubval->path_s, (32 * 32) * 3);
	game->textures[3] = cub_create_textures(DOOR, (32 * 32) * 3);
	game->textures[4] = cub_create_textures(cubval->path_w, (32 * 32) * 3);
	game->all_textures = cub_join_textures(game->textures, (32 * 32) * 3, 5);
	game->tex_sky = cub_create_textures(SKY, (120 * 80) * 3);
	// printf("========== MAP WALLS ==========\n\n");
	// cub_print_map(game->map_walls);
	// printf("\n\n========== MAP FLOORS ==========\n\n");
	// cub_print_map(game->map_floors);
	// printf("\n\n========== MAP CEILINGS ==========\n\n");
	// cub_print_map(game->map_ceilings);
	// exit(0);
}

// Function to extract a map
void	cub_extract_map(const char *file, char *map)
{
	char	*line;
	int		fd;
	int		i;
	int		m;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ((void)write(2, RED"Couldn't open file\n"RESET, 20));
	m = -1;
	while (1)
	{
		i = -1;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line && line[++i])
		{
			if (line[i] != '\n')
				map[++m] = line[i];
		}
		free(line);
	}
	map[++m] = '\0';
	close(fd);
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
	j = -1;
	k = -1;
	while (++j < nbr)
	{
		i = -1;
		while (++i < size)
		{
			joined[++k] = textures[j][i];
		}
	}
	return (joined);
}

// Function to create al textures
int *cub_create_textures(const char *file, int size)
{
	int *texture;
	int	fd;

	texture = (int *)malloc(size * sizeof(int));
	if (!texture)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), texture);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (write(2, RED"Couldn't open file\n"RESET, 20), texture);
	cub_extract_texture(fd, &(texture));
	close(fd);
	return (texture);
}

void	cub_extract_texture(int fd, int **texture)
{
	char	*line;
	int		t;

	t = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		(*texture)[++t] = ft_atoi(line);
		free(line);
	}
}
