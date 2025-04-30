/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:11 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/29 14:01:52 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub.h"
/* check_cub */
int			is_map_line(char *line);
int			is_valid_cub(char *line);

/* file_manager */
t_cubval	*open_and_conf(char *path);
int			are_all_ppm(t_cubval *cubval);
void		clean_tcubval(t_cubval *cubval);

/* check_map */
t_cubval	*get_map_param(char *path);

/* fix args */
void		get_all(char *line, t_cubval *predat);
t_cubval	*fix_all(t_cubval *predat);

#endif