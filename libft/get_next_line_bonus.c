/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:34:22 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/11 15:14:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fix_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	i = 0;
	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && buffer[i])
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*free_buffer(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*new_buffer(char *buffer)
{
	int		i;
	int		j;
	int		len;
	char	*newbuffer;

	i = 0;
	j = 0;
	if (buffer == NULL)
		return (free_buffer(buffer));
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free_buffer(buffer));
	i++;
	if (buffer[i] == '\0')
		return (free_buffer(buffer));
	len = ft_strlenn(buffer + i);
	newbuffer = malloc(sizeof(char) * (1 + len));
	if (!newbuffer)
		return (free_buffer(buffer));
	while (buffer[i])
		newbuffer[j++] = buffer[i++];
	newbuffer[j] = '\0';
	free(buffer);
	return (newbuffer);
}

char	*get_buffer(char *buffer, ssize_t bytes, char *temp, int fd)
{
	while (1)
	{
		if (ft_strlenn(buffer) && ft_strchrr(buffer, '\n'))
			break ;
		bytes = read(fd, temp, 4);
		if (bytes < 0)
		{
			if (buffer)
				free(buffer);
			buffer = NULL;
			return (NULL);
		}
		if (bytes == 0)
			break ;
		temp[bytes] = '\0';
		buffer = ft_strjoinn(buffer, temp);
		if (buffer == NULL)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	ssize_t		bytes;
	char		*line;

	bytes = 0;
	temp = (char *)malloc(sizeof(char) * (4 + 1));
	if (temp == NULL)
		return (NULL);
	buffer = get_buffer(buffer, bytes, temp, fd);
	if (buffer == NULL)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	line = fix_line(buffer);
	buffer = new_buffer(buffer);
	if (temp)
		free(temp);
	return (line);
}
