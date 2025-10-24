/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:32:59 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/11 15:14:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenn(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchrr(const char *s, int c)
{
	int		i;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlenn(s);
	i = 0;
	if ((char)c == '\0')
		return ((char *)(s + n));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;
	size_t	j;

	len1 = ft_strlenn(s1);
	len2 = ft_strlenn(s2);
	res = malloc(len1 + len2 + 1);
	if (res == NULL)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}
