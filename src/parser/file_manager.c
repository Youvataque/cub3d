/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:14:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/25 16:57:42 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// Check if the path point to .cub file 
static int	is_cub_file(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 4)
		return (0);
	return (ft_strcmp(path + len - 4, ".cub") == 0);
}

///////////////////////////////////////////////////////////////////////////////
// Open map and set predatas (unFixed datas)
t_cubval	*open_and_conf(char *path)
{
	char		*line;
	int			fd;
	t_cubval	*predat;

	if (!is_cub_file(path))
		return (ft_printf("Error: file is not .cub\n"), NULL);
	predat = malloc(sizeof(t_cubval));
	if (!predat)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: file can't be open.\n"), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_valid_cub(line))
			return (ft_printf("Error: format is not valid !\n"), NULL);
		get_all(line, predat);
		line = get_next_line(fd);
	}
	return (predat);
}
