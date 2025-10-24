/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:23:52 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/23 11:52:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_side_walls(char **map)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
		{
			free_all(map);
			exit_error("Error\nThe map must be enclosed/surrounded by walls\n");
		}
		i++;
	}
}

void	check_if_all_count(char **map, int count_exit, int count_collectables,
		int count_player)
{
	if (count_exit == 0)
	{
		free_all(map);
		exit_error("Error\nno exit\n");
	}
	if (count_exit > 1)
	{
		free_all(map);
		exit_error("Error\nmultiple exits\n");
	}
	if (count_player == 0)
	{
		free_all(map);
		exit_error("Error\nno player\n");
	}
	if (count_player > 1)
	{
		free_all(map);
		exit_error("Error\nmultiple players\n");
	}
	if (count_collectables == 0)
	{
		free_all(map);
		exit_error("Error\nno collectables\n");
	}
}

void	check_if_all_exist(char **map, int count_exit, int count_collectables,
		int count_player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				count_player++;
			else if (map[i][j] == 'C')
				count_collectables++;
			else if (map[i][j] == 'E')
				count_exit++;
			j++;
		}
		i++;
	}
	check_if_all_count(map, count_exit, count_collectables, count_player);
}

void	check_all_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'E'
				|| map[i][j] == 'C' || map[i][j] == 'P')
				j++;
			else
			{
				free_all(map);
				exit_error("Error\nnot a valid map\n");
			}
		}
		i++;
	}
}

void	check_first_string(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			free_all(map);
			exit_error("Error\nnot a valid map\n");
		}
		i++;
	}
}
