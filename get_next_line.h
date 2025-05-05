/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:26:37 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/05 10:51:07 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int			ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
char		*ft_strjoin(char *first, char *second);
char		*ft_strdup(char *s);
char		*read_stash(int fd, char *stash);
char		*update_stash(char *stash);
char		*extract_line(char *s);
int			newline(char *s);
char		*get_next_line(int fd);

#endif
