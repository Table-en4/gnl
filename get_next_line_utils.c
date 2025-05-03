/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:35:19 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/03 19:47:01 by molapoug         ###   ########.fr       */
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

char	*ft_strjoin(char *first, char *second)
{
	int		i;
	int		j;
	char	*str;

	if (!first || !second)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(second) + 1));
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
	return (str);
}

char	*get_lines(char *str)
{
	int		len;
	char	*line;

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
	return (line);
}
