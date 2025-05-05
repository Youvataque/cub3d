/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:37:34 by yseguin           #+#    #+#             */
/*   Updated: 2025/05/05 14:40:20 by nifromon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub.h"

/* lib_ext */
int		contain(char *str, char *to_find);
int		is_ws(char c);

/* map manager */
int		get_y_max(char **map);
int		get_x_max(char **map);
int		is_spawn(char c);
void	free_tab(char **tab);
char	**add_to_tab(char **tab, char *new_line);
char	**square_map(char **map);
void	fill(char **map, t_point begin, t_point max, char *charset);
char	*inline_map(char **map);

/* str_utils */
int		count_clean(char *s);
int		check_exit(t_cubval *cubval);

#endif