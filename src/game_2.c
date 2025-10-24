/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqadah <mqadah@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:00:00 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/22 13:00:00 by mqadah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_game(t_game *game, char *cause)
{
	if (game->map)
		free_all(game->map);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit_error(cause);
}

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	if (!game->wall)
		free_game(game, "Error\nin file to image(wall)\n");
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&img_width, &img_height);
	if (!game->floor)
		free_game(game, "Error\nin file to image(floor)\n");
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&img_width, &img_height);
	if (!game->player)
		free_game(game, "Error\nin file to image(player)\n");
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&img_width, &img_height);
	if (!game->exit)
		free_game(game, "Error\nin file to image(exit)\n");
	game->collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&img_width, &img_height);
	if (!game->collect)
		free_game(game, "Error\nin file to image(collect)\n");
}

void	draw_map(t_game *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->floor, game->x
				* 32, game->y * 32);
			if (game->map[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall,
					game->x * 32, game->y * 32);
			else if (game->map[game->y][game->x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect,
					game->x * 32, game->y * 32);
			else if (game->map[game->y][game->x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit,
					game->x * 32, game->y * 32);
			else if (game->map[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player,
					game->x * 32, game->y * 32);
			game->x++;
		}
		game->y++;
	}
}

void	game_alloc_fail(char **map, void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
	free_all(map);
	exit_error("Error\nFailed to allocate game\n");
}

int	count_collectables(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
