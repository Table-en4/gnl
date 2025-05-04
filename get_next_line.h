/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:26:37 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/04 14:29:04 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str);
void	ft_putstr_fd(char *str, int fd);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *first, char *second);
int	has_newline(char *s);
char	*ft_strdup(char *s);
char	*update_stash(char *stash);
char	*extract_line(char *s);
