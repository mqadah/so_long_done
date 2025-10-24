#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
	int		total_collect;
	int		collected;
	int		moves;
	int		x;
	int		y;
	int		flag;
	int		new_y;
	int		new_x;
}	t_game;

//map read
char	**loop_map_string(int count, int fd);
char	**read_map(char *map);
void	check_len(char **map);
void	check_side_walls(char **map);
void	check_first_string(char **map);
void	check_if_all_count(char **map, int count_exit,
			int count_collectables, int count_player);
void	check_if_all_exist(char **map, int count_exit,
			int count_collectables, int count_player);
void	check_all_valid(char **map);
void	check_first_last(char **map);
void	check_map_validate(char **map);
void	player_pos(char **map, int *y, int *x);
char	**copy_map(char **map);
void	check_new_line(char **map);

//game
t_game	*init_data(char **map, void *mlx);
void	free_game(t_game *game, char *cause);
void	game_alloc_fail(char **map, void *mlx);
void	load_images(t_game *game);
void	draw_map(t_game *game);
void	print_moves(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		key_movement(int key, t_game *game);
int		handle_close(t_game *game);

//helpers
int		count_collectables(char **map);
void	free_all(char **d);
void	exit_error(char *err);

void	Exit_pos(t_game *game);

#endif
