/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixe_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/26 15:36:09 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// function for fix params format ("NO: 		./ex" to "./ex")
static char	*fix_params(char *param)
{
	char	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(char) * (count_clean(param) + 1));
	if (!clean)
		return (NULL);
	i = 0;
	j = 0;
	while (param[i])
	{
		if (!is_ws(param[i]))
			clean[j++] = param[i];
		i++;
	}
	clean[j] = '\0';
	return (clean);
}

///////////////////////////////////////////////////////////////////////////////
// get all args from file (notFixed args)
void	get_all(char *line, t_cubval *predat)
{
	char	*temp;

	temp = fix_params(line);
	if (contain(line, "NO"))
		predat->path_n = ft_substr(temp, 2, ft_strlen(temp));
	else if (contain(line, "SO"))
		predat->path_s = ft_substr(temp, 2, ft_strlen(temp));
	else if (contain(line, "WE"))
		predat->path_w = ft_substr(temp, 2, ft_strlen(temp));
	else if (contain(line, "EA"))
		predat->path_o = ft_substr(temp, 2, ft_strlen(temp));
	else if (contain(line, "F"))
		predat->f = ft_substr(temp, 1, ft_strlen(temp));
	else if (contain(line, "C"))
		predat->c = ft_substr(temp, 1, ft_strlen(temp));
	else if (is_map_line(line))
		predat->map = add_to_tab(predat->map, ft_strdup(line));
	free(line);
}

///////////////////////////////////////////////////////////////////////////////
// fix all argument and return for printing
t_cubval	*fix_all(t_cubval *predat)
{
	t_cubval	*result;

	if (!predat)
		return (NULL);
	result = malloc(sizeof(t_cubval));
	if (!result)
		return (NULL);
	result->path_n = ft_strdup(predat->path_n);
	result->path_s = ft_strdup(predat->path_s);
	result->path_w = ft_strdup(predat->path_w);
	result->path_o = ft_strdup(predat->path_o);
	result->c = ft_strdup(predat->c);
	result->f = ft_strdup(predat->f);
	result->map = square_map(predat->map);
	clean_tcubval(predat);
	return (result);
}
