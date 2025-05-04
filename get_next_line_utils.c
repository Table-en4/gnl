/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:35:19 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/04 14:41:12 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i = 0;
	if (!dst || !src)
		return (0);
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int	len = ft_strlen(s);
	char	*dup;
	int	i = 0;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int	l1 = ft_strlen(s1);
	int	l2 = ft_strlen(s2);
	int	i = 0;
	int	j = 0;

	res = malloc(l1 + l2 + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*extract_line(char *s)
{
	int	i = 0;
	char	*line;

	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, s, i + 1);
	return (line);
}

char	*update_stash(char *s)
{
	int	i = 0;
	int	j = 0;
	char	*new;

	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	i++;
	new = malloc(ft_strlen(s + i) + 1);
	if (!new)
		return (NULL);
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return (new);
}
