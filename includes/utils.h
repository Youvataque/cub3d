/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:37:34 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/24 17:14:27 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub.h"

/* lib_ext */
int	contain(char *str, char *to_find);

/* tab manager */
char	**add_to_tab(char **tab, char *new_line);
void	free_tab(char **tab);

# endif