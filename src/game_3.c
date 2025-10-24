/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:23:26 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/23 12:39:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*init_data(char **map, void *mlx)
{
	int		height;
	int		width;
	t_game	*game;

	height = 0;
	width = ft_strlen(map[0]);
	while (map[height])
		height++;
	if (width == 80 || height == 80)
	{
		free_all(map);
		exit_error("Error\nExceeded the limit\n");
	}
	game = malloc(sizeof(t_game));
	if (!game)
		game_alloc_fail(map, mlx);
	game->mlx = mlx;
	game->map = map;
	game->height = height;
	game->width = width;
	game->collected = 0;
	game->total_collect = count_collectables(map);
	game->moves = 0;
	game->flag = 0;
	return (game);
}

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	if (!moves)
		free_game(game, "Error\n in itoa allocation\n");
	mlx_string_put(game->mlx, game->win, 10, 20, 0x000000, moves);
	write(1, "number of movements ", 21);
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	free(moves);
}

int	check_exit(t_game *game, int y, int x)
{
	if (game->map[game->new_y][game->new_x] == 'E')
	{
		if (game->collected == game->total_collect)
		{
			game->moves++;
			print_moves(game);
			free_game(game, "Winner!!!!\n");
		}
		else
		{
			game->map[y][x] = '0';
			game->map[game->new_y][game->new_x] = 'P';
			game->flag = 1;
			draw_map(game);
			print_moves(game);
			return (1);
		}
	}
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	player_pos(game->map, &y, &x);
	game->new_y = y + dy;
	game->new_x = x + dx;
	if (game->map[game->new_y][game->new_x] == '1')
		return ;
	if (game->map[game->new_y][game->new_x] == 'C')
		game->collected++;
	if (check_exit(game, y, x))
		return ;
	if (game->flag == 1)
	{
		game->map[y][x] = 'E';
		game->flag = 0;
	}
	else
		game->map[y][x] = '0';
	game->map[game->new_y][game->new_x] = 'P';
	game->moves++;
	draw_map(game);
	print_moves(game);
}

int key_movement(int key, t_game *game)
{
	if (key == 65307) // ESC
		free_game(game, "game closed\n");
	else if (key == 119 || key == 65362)
		move_player(game, 0, -1);
	else if (key == 115 || key == 65364)
		move_player(game, 0, 1);
	else if (key == 97 || key == 65361)
		move_player(game, -1, 0);
	else if (key == 100 || key == 65363)
		move_player(game, 1, 0);
	return (0);
}

