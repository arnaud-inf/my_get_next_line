/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:05:01 by aelison           #+#    #+#             */
/*   Updated: 2024/03/23 10:42:23 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, size_t start, size_t len);
char	*get_next_line(int fd);

#endif
