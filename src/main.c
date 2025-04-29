/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/29 13:43:20 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	bazard_test(t_cubval *p)
{
	int	i;

	if (!p)
	{
		printf("❌ Structure NULL\n");
		return ;
	}
	printf("\n Map :\n");
	if (!p->map)
		printf("  (null)\n");
	else
	{
		i = 0;
		while (p->map[i])
		{
			printf("X%sX\n", p->map[i]);
			i++;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
// main of cub3D
int	main(int ac, char **av)
{
	t_cubval	*cubval;

	if (ac == 2)
	{
		cubval = get_map_param(av[1]);
		bazard_test(cubval);
		clean_tcubval(cubval);
		return (0);
	}
	return (ft_printf("Error: bad args."), 1);
}
