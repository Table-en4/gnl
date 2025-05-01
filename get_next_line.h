# ifndef FT_GET_NEXT_LINE_H
#define FT_GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/* my buffer for gnl */

/* fonctions with char */
char	*get_next_line(int fd);

/* fonctions with void */
void	ft_putstr(char *str, int fd);

#endif
