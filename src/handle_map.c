/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:24:19 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/23 13:40:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	exit_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
}
char	**loop_map_string(int count, int fd)
{
	char	**map;
	char	*line;
	int		i;
	int		len;

	map = (char **)malloc(sizeof(char *) * (count + 1));
	if (!map)
		exit_error("Error\nallocating memory\n");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n' )
			line[--len] = '\0';
		if (len > 0 && line[len - 1] == '\r')
			line[len - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(char *mapp)
{
	int		fd;
	char	**map;
	char	*line;
	int		count;

	count = 0;
	fd = 0;
	fd = open(mapp, O_RDONLY);
	if (fd < 0)
		exit_error("Error\nOpening map\n");
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(mapp, O_RDONLY);
	if (fd < 0)
		exit_error("Error\nOpening map\n");
	map = loop_map_string(count, fd);
	close(fd);
	check_map_validate(map);
	return (map);
}
