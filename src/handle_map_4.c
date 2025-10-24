/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:24:05 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/24 13:17:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(char **map, int x, int y)//Dfs
{
	if (map[y][x] == '1' || map[y][x] == 'G')
		return ;
	map[y][x] = 'G';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	if_found(char **map, char **map_cpy)
{
	free_all(map);
	free_all(map_cpy);
	exit_error("Error\nmap is not valid\n");
}

void	check_the_path(char **map)
{
	char	**map_cpy;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map_cpy = copy_map(map);
	player_pos(map, &y, &x);
	flood_fill(map_cpy, x, y);
	y = 0;
	while (map_cpy[y])
	{
		x = 0;
		while (map_cpy[y][x])
		{
			if (map_cpy[y][x] == 'C' || map_cpy[y][x] == 'E')
				if_found(map, map_cpy);
			x++;
		}
		y++;
	}
	free_all(map_cpy);
}

void	check_map_validate(char **map)
{
	int	count_exit;
	int	count_collectables;
	int	count_player;

	count_exit = 0;
	count_collectables = 0;
	count_player = 0;
	if (map[0] == NULL)
	{
		free_all(map);
		exit_error("Error\nEmpty map\n");
	}
	check_new_line(map);
	check_len(map);
	check_side_walls(map);
	check_if_all_exist(map, count_exit, count_collectables, count_player);
	check_first_last(map);
	check_all_valid(map);
	check_the_path(map);
}
