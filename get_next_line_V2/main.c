/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:15:56 by aelison           #+#    #+#             */
/*   Updated: 2024/03/20 11:56:21 by aelison          ###   ########.fr       */
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
        printf("DEBUT:\t%sFIN\t", res);
    }
    return (0);
}