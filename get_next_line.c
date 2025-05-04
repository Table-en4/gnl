/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:34:19 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/04 15:00:55 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
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

int	newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] == '\n')
			return (1);
	return (0);
}

char *read_and_build_stash(int fd, char *stash)
{
    char *buffer;
    char *tmp;
    int  rd;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    rd = 1;
    while (!newline(stash) && rd > 0)
    {
        rd = read(fd, buffer, BUFFER_SIZE);
        if (rd < 0)
            return (free(buffer), NULL);
        buffer[rd] = '\0';
        tmp = ft_strjoin(stash, buffer);
        free(stash);
        stash = tmp;
    }
    free(buffer);
    if (!stash || !*stash)
        return (free(stash), NULL);
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_and_build_stash(fd, stash);
    if (!stash)
        return (NULL);
    
    line = extract_line(stash);
    stash = update_stash(stash);
    return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	static char	*line;

	if (ac != 2)
	{
		write(2, "Usage: ./a.out <filename>\n", 27);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur ouverture fichier");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

