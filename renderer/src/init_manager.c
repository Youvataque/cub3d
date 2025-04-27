/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:42:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/27 07:03:04 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/renderer.h"

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
void	cub_init_manager(t_game *game)
{
	ft_memset((void *)game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	game->player.pos.x = 300;
	game->player.pos.y = 300;
	game->player.delta.x = cos(game->player.angle) * 5;
	game->player.delta.y = sin(game->player.angle) * 5;
	game->map_walls = (char *)malloc(((MAP_WIDTH * MAP_HEIGHT) + 1) * sizeof(char));
	if (!game->map_walls)
		return ((void)write(2, RED"Failed to allocate memory\n"RESET, 27));
	cub_extract_map(WALLS, game->map_walls);
	game->map_floors = (char *)malloc(((MAP_WIDTH * MAP_HEIGHT) + 1) * sizeof(char));
	if (!game->map_floors)
		return ((void)write(2, RED"Failed to allocate memory\n"RESET, 27));
	cub_extract_map(FLOORS, game->map_floors);
	game->map_ceilings = (char *)malloc(((MAP_WIDTH * MAP_HEIGHT) + 1) * sizeof(char));
	if (!game->map_ceilings)
		return ((void)write(2, RED"Failed to allocate memory\n"RESET, 27));
	cub_extract_map(CEILINGS, game->map_ceilings);
	game->textures = (int **)malloc(4 * sizeof(int *));
	if (!game->textures)
		return ((void)write(2, RED"Failed to allocate memory\n"RESET, 27));
	game->textures[0] = cub_create_textures("./textures/Checkerboard", 32 * 32);
	game->textures[1] = cub_create_textures("./textures/Brick", 32 * 32);
	game->textures[2] = cub_create_textures("./textures/Window", 32 * 32);
	game->textures[3] = cub_create_textures("./textures/Door", 32 * 32);
	game->all_textures = cub_join_textures(game->textures, (32 * 32));
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
int	*cub_join_textures(int **textures, int size)
{
	int	*joined;
	int	i;
	int	j;
	int	k;
	
	joined = (int *)malloc((size * 4) * sizeof(int));
	if (!joined)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), textures[0]);
	j = 0;
	k = 0;
	while (j < 4)
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

// Function to create al textures
int *cub_create_textures(const char *file, int size)
{
	int *texture;
	
	texture = (int *)malloc(size * sizeof(int));
	if (!texture)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27), texture);
	cub_extract_texture(file, &(texture));
	return (texture);		   				   
}

void	cub_extract_texture(const char *file, int **texture)
{
	char	*line;	
	int		fd;
	int		i;
	int		t;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ((void)write(2, RED"Couldn't open file\n"RESET, 20));
	t = -1;
	while (1)
	{
		i = -1;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line && line[++i] != '\0')
		{
			if (line[i] == '0' || line[i] == '1')
				(*texture)[++t] = line[i] - 48;
		}
		free(line);
	}
	close(fd);
}
