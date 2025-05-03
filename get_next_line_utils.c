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
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char *first, char *second)
{
	int	j;
	int		i;
	char		*str;

	if (!first && second)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(second) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (first[++i])
		str[j++] = first[i];
	str[j] = '\n';
	i = -1;
	while (second[++i])
		str[j++] = second[i];
	//str[ft_strlen(first) + ft_strlen(second)] = '\0';
	return (str[j] = '\0', str);
}

char	*get_lines(char *str)
{
	int	sizeof_str_line;
	char	*dst;

	sizeof_str_line = 0;
	while (str[sizeof_str_line] != '\n')
		sizeof_str_line++;
	if (sizeof_str_line == '\n')
		sizeof_str_line++;
	dst = malloc(sizeof(char) * (sizeof_str_line + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, str, sizeof_str_line + 1);
	return (dst);
}
