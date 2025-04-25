/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/25 17:01:32 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void bazard_test(t_cubval *p)
{	
	int	i;

	if (!p)
	{
		printf("❌ Structure NULL\n");
		return ;
	}
	printf("Textures :\n");
	printf("%s\n", p->path_n ? p->path_n : "(null)");
	printf("%s\n", p->path_s ? p->path_s : "(null)");
	printf("%s\n", p->path_w ? p->path_w : "(null)");
	printf("%s\n", p->path_o ? p->path_o : "(null)");

	printf("\nCouleurs :\n");
	printf("%s\n", p->f ? p->f : "(null)");
	printf("%s\n", p->c ? p->c : "(null)");

	printf("\n Map :\n");
	if (!p->map)
		printf("  (null)\n");
	else
	{
		i = 0;
		while (p->map[i])
		{
			printf("X %s X\n", p->map[i]);
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
		return (0);
	}
	return (ft_printf("Error: bad args."), 1);
}
