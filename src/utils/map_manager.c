/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:08:03 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/25 12:13:58 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

///////////////////////////////////////////////////////////////////////////////
// Function for clean a char **
void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

///////////////////////////////////////////////////////////////////////////////
// function for add a char * to a char ** (.add in javascript)
char	**add_to_tab(char **tab, char *new_line)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 2));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = new_line;
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}
