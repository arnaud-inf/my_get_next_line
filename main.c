/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:21:04 by aelison           #+#    #+#             */
/*   Updated: 2024/03/25 11:30:36 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd;
    int i;
    char *res;

    fd = open("text", O_RDONLY);
    i = 0;
    res = ft_strdup("\0");
    while (res)
    {
        free(res);
        res = get_next_line(fd);
        printf("%d\t%s", i, res);
        i++;
    }
    free(res);
    close(fd);

    return (0);
}
