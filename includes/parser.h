/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:11 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/24 19:15:54 by yseguin          ###   ########.fr       */
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

/* get_args */
void		get_all(char *line, t_cubval *predat);

/* fix args */
char		*fix_params(char *param);

#endif