# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 19:12:12 by nifromon          #+#    #+#              #
#    Updated: 2025/05/03 02:05:55 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
MANDATORY =				mandatory
BONUS =					bonus
EXTRA =					extra

all:
						@make -s -C $(MANDATORY) all

bonus:
						@make -s -C $(BONUS) all

extra:
						@make -s -C $(EXTRA) all

clean:
						@make -s -C $(MANDATORY) clean

clean_bonus:
						@make -s -C $(BONUS) clean

clean_extra:
						@make -s -C $(EXTRA) clean

fclean:
						@make -s -C $(MANDATORY) fclean

fclean_bonus:
						@make -s -C $(BONUS) fclean

fclean_extra:
						@make -s -C $(EXTRA) fclean

re:						fclean all

re_bonus:				fclean_bonus bonus

re_extra:				fclean_extra extra

.PHONY:					all bonus extra \
						clean clean_bonus clean_extra \
						fclean fclean_bonus fclean_extra \
						re re_bonus re_extra