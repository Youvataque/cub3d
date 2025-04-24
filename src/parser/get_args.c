/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/24 18:46:22 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// get all args from file (notFixed args)
void	get_all(char *line, t_predatas *predat)
{
	if (contain(line, "NO"))
		predat->path_n = ft_substr(line, 2, ft_strlen(line));
	else if (contain(line, "SO"))
		predat->path_s = ft_substr(line, 2, ft_strlen(line));
	else if (contain(line, "WE"))
		predat->path_w = ft_substr(line, 2, ft_strlen(line));
	else if (contain(line, "EA"))
		predat->path_o = ft_substr(line, 2, ft_strlen(line));
	else if (contain(line, "F"))
		predat->f = ft_substr(line, 1, ft_strlen(line));
	else if (contain(line, "C"))
		predat->c = ft_substr(line, 1, ft_strlen(line));
	else if (is_map_line(line))
		predat->map = add_to_tab(predat->map, ft_strdup(line));
}
