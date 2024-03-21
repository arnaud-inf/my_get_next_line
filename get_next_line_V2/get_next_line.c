/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:09:17 by aelison           #+#    #+#             */
/*   Updated: 2024/03/21 15:39:14 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_only_read(char *buffer, int read_val)
{
    char *result;

    if (read_val <= BUFFER_SIZE)
    {
        result = ft_substr(buffer, 0, read_val);
        return (result);
    }
    return (NULL);
}

char *get_line(char *result, int indice)
{
    char    *res;

    if (indice != -1)
    {
        res = ft_substr(result, 0, indice + 1);
        return (res);
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *join;
    char *result;
    int read_val;
    int indice;

    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    join = ft_strdup("\0");
    if (buffer)
    {
        join = ft_strjoin(join, buffer);
        result = get_line(join, ft_strchr(join, '\n'));
        if (result != NULL)
        {
            buffer = ft_substr(join, ft_strchr(join, (int)'\n') + 1, ft_strlen(join));
            return (result);
        }
    }
    else
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE);
        if (!buffer)
            return (NULL);
    }
    read_val = 1;
    while (read_val != 0)
    {
        read_val = read(fd, buffer, BUFFER_SIZE);
        if (read_val == -1 || read_val == 0)
            break;
        join = ft_strjoin(join, ft_only_read(buffer, read_val));
        result = get_line(join, ft_strchr(join, '\n'));
        if (result != NULL)
        {
            buffer = ft_substr(join, ft_strchr(join, (int)'\n') + 1, ft_strlen(join));
            return (result);
        }
        free(buffer);
    }
    if (join[0] == '\0')
        join = NULL;
    return (join);
}
