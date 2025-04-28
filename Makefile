# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nifromon <nifromon@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 19:12:12 by nifromon          #+#    #+#              #
#    Updated: 2025/04/28 15:56:53 by nifromon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Argument
NAME =		cub3d

# Compilation
CC =					@gcc -g
CFLAGS =				-Wall -Werror -Wextra -L $(LIBFT_DIR)/
MFLAGS = 				-L $(MLX_DIR)/ -L /usr/include/X11/ \
						-L /usr/lib/x86_64-linux-gnu/ \
						-lmlx -lXext -lX11 -lXrandr -lm -lbsd -lXfixes

INCLUDES = 				-I $(HEADER_DIR)/ -I $(LIBFT_DIR)/headers/ \
						-I $(MLX_DIR)/ -I /usr/include/X11/ \
						-I /usr/include/X11/extensions/ \
						-I /usr/lib/x86_64-linux-gnu/

# Directories
SRC_DIR =				./src
UTILS_DIR =				./src/utils
HEADER_DIR =			./includes

OBJ_DIR =				obj
OBJ_SRC_DIR =			$(OBJ_DIR)/src
OBJ_UTILS_DIR =			$(OBJ_DIR)/src/utils

MLX_DIR =				mlx
MLX =					$(MLX_DIR)/libmlx.a

LIBFT_DIR =				libft
LIBFT =					$(LIBFT_DIR)/libft_inc.a

# Utils
RM =					@rm -rf

# Colors
BLACK_ON_GREEN =		\033[30;42m
BLACK_ON_RED =			\033[30;41m
YELLOW =				\033[1;33m
GREEN =					\033[1;32m
RED =					\033[1;31m
RESET =					\033[1;0m

# Sources and Objects
SRC =					\
						$(SRC_DIR)/main.c \
						$(SRC_DIR)/renderer/init_manager.c \
						$(SRC_DIR)/renderer/pixel_manager.c \
						$(SRC_DIR)/renderer/raycasting_manager.c \
						$(SRC_DIR)/renderer/raycasting_manager_2.c \
						$(SRC_DIR)/renderer/raycasting_manager_walls.c \
						$(SRC_DIR)/renderer/raycasting_manager_joists.c \
						$(SRC_DIR)/renderer/rendering_manager.c \
						$(SRC_DIR)/renderer/interaction_manager.c \
						$(SRC_DIR)/renderer/movement_manager.c \
						$(SRC_DIR)/renderer/action_manager.c \
						\
						$(SRC_DIR)/parser/check_cub.c \
						$(SRC_DIR)/parser/check_map.c \
						$(SRC_DIR)/parser/file_manager.c \
						$(SRC_DIR)/parser/fix_args.c

OBJ_SRC =				$(SRC:$(SRC_DIR)/%.c=$(OBJ_SRC_DIR)/%.o)

UTILS =					\
						$(UTILS_DIR)/time_manager.c \
						$(UTILS_DIR)/calculation_manager.c \
						\
						$(UTILS_DIR)/map_manager.c \
						$(UTILS_DIR)/map_manager2.c \
						$(UTILS_DIR)/lib_ext.c \
						$(UTILS_DIR)/str_utils.c

OBJ_UTILS =				$(UTILS:$(UTILS_DIR)/%.c=$(OBJ_UTILS_DIR)/%.o)

# Rules and dependencies
all:					$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
						@make -s -C $(LIBFT_DIR) all

$(MLX):
						@echo "$(YELLOW)Building $(MLX)...$(RESET)"
						@make -s -C $(MLX_DIR) all >/dev/null 2>&1
						@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(MLX) \*$(RESET)"

$(NAME):				$(LIBFT) $(MLX) $(OBJ_SRC) $(OBJ_UTILS)
						@echo "$(YELLOW)Building $(NAME)...$(RESET)"
						$(CC) $(OBJ_SRC) $(OBJ_UTILS) $(LIBFT) $(MLX) -o $(NAME) $(CFLAGS) $(INCLUDES) $(MFLAGS)
						@echo "$(BLACK_ON_GREEN)\t\t\t\t\t*/ $(NAME) \*$(RESET)"

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c
						@mkdir -p $(OBJ_DIR)
						@mkdir -p $(OBJ_SRC_DIR)
						@mkdir -p $(OBJ_SRC_DIR)/renderer/
						@mkdir -p $(OBJ_SRC_DIR)/parser/
						$(CC) -s -c $(CFLAGS) $(INCLUDES) $(MFLAGS) $< -o $@

$(OBJ_UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
						@mkdir -p $(OBJ_DIR)
						@mkdir -p $(OBJ_UTILS_DIR)
						$(CC) -s -c $(CFLAGS) $(INCLUDES) $(MFLAGS) $< -o $@

clean:
						@make -s -C $(LIBFT_DIR) clean
						@echo "$(YELLOW)Cleaning $(MLX_DIR)...$(RESET)"
						@make -s -C $(MLX_DIR) clean >/dev/null 2>&1
						@echo "$(RED)Cleaned $(MLX_DIR)$(RESET)"
						@echo "$(YELLOW)Cleaning $(OBJ_DIR)...$(RESET)"
						$(RM) $(OBJ_DIR)
						@echo "$(RED)Cleaned $(OBJ_DIR)$(RESET)"

fclean:
						@make -s -C $(LIBFT_DIR) fclean
						@make -s -C $(LIBFT_DIR) clean >/dev/null 2>&1
						@echo "$(YELLOW)Cleaning $(MLX_DIR)...$(RESET)"
						@make -s -C $(MLX_DIR) clean >/dev/null 2>&1
						@echo "$(RED)Cleaned $(MLX_DIR)$(RESET)"
						@echo "$(YELLOW)Forcefully cleaning $(MLX)...$(RESET)"
						@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(MLX) \*$(RESET)"
						@echo "$(YELLOW)Cleaning $(OBJ_DIR)...$(RESET)"
						$(RM) $(OBJ_DIR)
						@echo "$(RED)Cleaned $(OBJ_DIR)$(RESET)"
						@echo "$(YELLOW)Forcefully cleaning $(NAME)...$(RESET)"
						$(RM) $(NAME)
						@echo "$(BLACK_ON_RED)\t\t\t\t\t*/ $(NAME) \*$(RESET)"

re:						fclean all

.PHONY:					all clean fclean re