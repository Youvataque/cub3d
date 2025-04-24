NAME = cub3D
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra

SRC = $(wildcard src/*.c) \
      $(wildcard src/printer/*.c) \
      $(wildcard src/parser/*.c)

OBJ = $(patsubst src/%,obj/%, $(SRC:.c=.o))

LIBFT_PATH = libft
LIBFT_FILE = $(LIBFT_PATH)/libft.a

MLX_PATH = minilibx-linux
MLX_FILE = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L/usr/X11R6/lib -lX11 -lXext

MATH_FLAGS = -lm

all: $(NAME)

$(NAME): $(LIBFT_FILE) $(MLX_FILE) $(OBJ)
	make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FILE) $(MLX_FILE) $(MLX_FLAGS) $(MATH_FLAGS) -o $(NAME)

$(LIBFT_FILE):
	make -C $(LIBFT_PATH)

$(MLX_FILE):
	make -C $(MLX_PATH)

clean:
	rm -rf obj
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re