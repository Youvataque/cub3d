/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:14:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/28 15:41:26 by nifromon         ###   ########.fr       */
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
		return (printf("Error: file is not .cub\n"), NULL);
	predat = malloc(sizeof(t_cubval));
	if (!predat)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (printf("Error: file can't be open.\n"), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_valid_cub(line))
			return (printf("Error: format is not valid !\n"), NULL);
		get_all(line, predat);
		line = get_next_line(fd);
	}
	return (predat);
}

///////////////////////////////////////////////////////////////////////////////
// Clean t_cubVal after usage
void	clean_tcubval(t_cubval *cubval)
{
	if (!cubval)
		return ;
	if (cubval->c)
		free(cubval->c);
	if (cubval->f)
		free(cubval->f);
	if (cubval->path_n)
		free(cubval->path_n);
	if (cubval->path_s)
		free(cubval->path_s);
	if (cubval->path_o)
		free(cubval->path_o);
	if (cubval->path_w)
		free(cubval->path_w);
	if (cubval->map_str)
		free(cubval->map_str);
	free_tab(cubval->map);
	free(cubval);
}
