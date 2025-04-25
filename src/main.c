/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:01 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/24 19:09:38 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// main of cub3D
int	main(void)
{
	t_cubval *p = open_and_conf("maps/ex1.cub");
	
	int	i;

	if (!p)
	{
		printf("❌ Structure NULL\n");
		return 1;
	}
	printf("🧭 Textures :\n");
	printf("%s\n", p->path_n ? p->path_n : "(null)");
	printf("%s\n", p->path_s ? p->path_s : "(null)");
	printf("%s\n", p->path_w ? p->path_w : "(null)");
	printf("%s\n", p->path_o ? p->path_o : "(null)");

	printf("\n🎨 Couleurs :\n");
	printf("%s\n", p->f ? p->f : "(null)");
	printf("%s\n", p->c ? p->c : "(null)");

	printf("\n🗺️  Map :\n");
	if (!p->map)
		printf("  (null)\n");
	else
	{
		i = 0;
		while (p->map[i])
		{
			printf("  %s\n", p->map[i]);
			i++;
		}
	}
	return 0;
}
