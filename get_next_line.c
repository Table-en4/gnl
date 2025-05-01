/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:34:19 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/01 17:31:50 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str = malloc(sizeof(char *) * (i + 1));
	if (!str)
		return (NULL);
	str = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(line);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	//if (buffer[i] == '\n')
	//	line[i++] = '\n';
	get_line(buffer);
	line[i] = '\0';
	return (line);
}

int main(int ac, char **av)
{
	int	fd;
	char	*line;

	if (ac != 2)
		return (printf("fais : %s +nom gros debile\n", av[0]), 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (perror("erreur ouverture fichier"), 1);
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	else
		printf("get_next_line a find NULL.\n");
	close(fd);
}

