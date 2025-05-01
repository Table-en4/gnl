#include "get_next_line.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[i++])
		write(fd, &str[i], 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *first, const char *second)
{
	unsigned int	j;
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
	str[j] = '\0';
	return (str);
}
