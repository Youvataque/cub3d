/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixe_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:36:26 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/25 12:13:11 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*fix_params(char *param)
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

t_cubval	*fix_all(t_cubval *predat)
{
	t_cubval	*result;

	result = malloc(sizeof(t_cubval));
	if (!result)
		return (NULL);
	result->path_n = predat->path_n;
	result->path_s = predat->path_s;
	result->path_w = predat->path_w;
	result->path_o = predat->path_o;
	return (result);
}
