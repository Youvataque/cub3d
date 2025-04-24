/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:14:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/24 18:48:07 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// Open map and set predatas (unFixed datas)
t_predatas	*open_and_conf(char *path)
{
	char		*line;
	int			fd;
	t_predatas	*predat;

	predat = malloc(sizeof(t_predatas));
	if (!predat)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!is_valid_cub(line))
			return (NULL);
		get_all(line, predat);
		line = get_next_line(fd);
	}
	return (predat);
}
