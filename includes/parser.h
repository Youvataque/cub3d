/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:11 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/25 15:04:58 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub.h"
/* check_cub */
int			is_valid_cub(char *line);
int			is_map_line(char *line);

/* file_manager */
t_cubval	*open_and_conf(char *path);

/* check_map */
t_cubval	*get_map_param(char *path);

/* fix args */
char		*fix_params(char *param);
void		get_all(char *line, t_cubval *predat);
t_cubval	*fix_all(t_cubval *predat);

#endif