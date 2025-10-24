/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:23:58 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/23 12:41:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_first_last(char **map)
{
	int	i;
	int	len;

	i = 0;
	check_first_string(map);
	len = 0;
	while (map[len])
		len++;
	len--;
	while (map[len][i])
	{
		if (map[len][i] != '1')
		{
			free_all(map);
			exit_error("Error\nnot a valid map\n");
		}
		i++;
	}
}

void	check_new_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n')
		{
			free_all(map);
			exit_error("Error\nEmpty line inside the map\n");
		}
		i++;
	}
}

void	handle_cpy(char **map, char **map_cpy)
{
	free_all(map);
	free_all(map_cpy);
	exit_error("Error\nCreating the copy for the map\n");
}

char	**copy_map(char **map)
{
	int		i;
	char	**map_cpy;

	i = 0;
	while (map[i])
		i++;
	map_cpy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map_cpy)
	{
		free_all(map);
		exit_error("Error\ncreating the copy for the map\n");
	}
	i = 0;
	while (map[i])
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			map_cpy[i] = NULL;
			handle_cpy(map, map_cpy);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

void	player_pos(char **map, int *y, int *x)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == 'P')
			{
				*y = row;
				*x = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
