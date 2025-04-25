/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:46:06 by yseguin           #+#    #+#             */
/*   Updated: 2025/04/24 19:01:59 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub.h"

/* structure des infos en sortie de .cub */
typedef struct s_cubval
{
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_o;
	char	*f;
	char	*c;
	char	**map;
}	t_cubval;

#endif