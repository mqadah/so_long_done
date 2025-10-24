NAME = so_long
SRC  =	src/game.c src/handle_map.c src/handle_map_2.c src/handle_map_3.c src/handle_map_4.c \
		src/game_2.c src/game_3.c  src/handle_map_5.c
OBJ  = $(SRC:.c=.o)

CC     = cc
CFLAGS = -Wall -Wextra -Werror
INC    = -I./includes -I./libft -I./minilibx-linux

LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

MLX_DIR   = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) $(INC) -o $(NAME)

%.o: %.c includes/so_long.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re