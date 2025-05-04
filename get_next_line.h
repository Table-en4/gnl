#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	count_lines(char *str);
int	ft_strlen(char *str);
char	*get_lines(char *str);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *first, char *second);
