/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:15:56 by aelison           #+#    #+#             */
/*   Updated: 2024/03/20 15:26:18 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    char *res;
    int i;
    int fd;

    i = 1;
    res = ft_strdup("");
    fd = open("text", O_RDONLY);
    while (res)
    {
        res = get_next_line(fd);
        printf("%d:\t%s\n", i, res);
        i++;
    }
    return (0);
}