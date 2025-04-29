/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager_graphics.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 08:37:09 by nifromon          #+#    #+#             */
/*   Updated: 2025/04/29 08:46:42 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// Function to create al textures
int	*cub_create_textures(const char *file, int size)
{
	int		*texture;
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

// Function to join all textures in one
int	*cub_join_textures(int **textures, int size, int nbr)
{
	int	*joined;
	int	i;
	int	j;
	int	k;

	joined = (int *)malloc((size * nbr) * sizeof(int));
	if (!joined)
		return (write(2, RED"Failed to allocate memory\n"RESET, 27),
			textures[0]);
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
