/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:09:17 by aelison           #+#    #+#             */
/*   Updated: 2024/03/20 13:26:14 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_indice(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char *ft_only_read(char *buffer, int read_val)
{
    char *result;

    if (read_val <= BUFFER_SIZE)
    {
        result = ft_substr(buffer, 0, read_val);
        return (result);
    }
    return (buffer);
}

void get_line(char *result, char *stock)
{
    result = ft_substr(result, 0, ft_indice(result) + 1);
    stock = ft_substr(result, ft_indice(result) + 1, ft_strlen(result));
}

char *get_next_line(int fd)
{
    static char *stock;
    static int read_val;
    static int status;
    char *buffer;
    char *result;

    if (BUFFER_SIZE <= 0 || fd < 0)
       return (NULL);
    if (status == 0)
        read_val = -1;
    status = 1;

    result = ft_strdup("\0");
    if (stock) 
    {
        result = ft_strjoin(result, stock);
        if (ft_strchr(result, (int)'\n') != NULL)
        {
            get_line(result, stock);
            return (result);
        }
    }
        
    while (read_val != 0)
    {
        buffer = malloc(sizeof(char) * BUFFER_SIZE);
        if (!buffer)
            return (NULL);
        read_val = read(fd, buffer, BUFFER_SIZE);
        result = ft_strjoin(result, ft_only_read(buffer, read_val));
        if (ft_strchr(result, (int)'\n') != NULL)
        {
            get_line(result, stock);
            return (result);
        }
        if (read_val == 0)
            return (result);
        free(buffer);
    }
    

    return (NULL);
}