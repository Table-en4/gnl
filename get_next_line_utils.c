/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:35:19 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/04 11:49:04 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			break ;
		i++;
	}
	if (str[i] == (char) c)
		return ((char *) str + i);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(char *s)
{
	int		i = 0;
	char	*dup;

	while (s[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *first, char *second)
{
	int		i;
	int		j;
	char	*str;

	if (!first && !second)
		return (NULL);
	if (!first)
		return (ft_strdup(second));
	if (!second)
		return (ft_strdup(first));
	str = malloc(ft_strlen(first) + ft_strlen(second) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (first[i])
		str[j++] = first[i++];
	i = 0;
	while (second[i])
		str[j++] = second[i++];
	str[j] = '\0';
	//free(first);
	return (str);
}

char	*get_lines(char *str)
{
	int		len;
	static char	*line;

	if (!str || !str[0])
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, len + 1);
	//ft_strjoin(line, str + len);
	return (line);
}
