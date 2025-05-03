/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:34:19 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/03 14:28:02 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int	count_lines(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	//buffer[bytes_read] = '\0';
	while (buffer[bytes_read] != '\0')
	{
		line = get_lines(buffer);
		bytes_read++;
	}
	buffer[bytes_read] = '\0';
	return (line);
}

int main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (printf("fais : %s +nom gros debile\n", av[0]), 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (perror("erreur ouverture fichier"), 1);
	line = get_next_line(fd);
	if (line)
	{
		//ft_putstr_fd(line, fd);
		printf("%s", line);
		free(line);
	}
	else
		printf("get_next_line a find NULL.\n");
	close(fd);
}

