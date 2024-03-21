/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:57:29 by aelison           #+#    #+#             */
/*   Updated: 2024/03/21 15:39:12 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i = i + 1;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	char			*result;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((const char *)s);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = s[i];
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen((const char *)s);
	while (i < len_s)
	{
		if (s[i] == (char)c)
			return ((int)i);
		i = i + 1;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t 	len_s2;
	char	*result;
	size_t 	i;

	len_s1 = ft_strlen((const char *)s1);
	len_s2 = ft_strlen((const char *)s2);
	result = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	i = 0;
    if (s1[0] == '\0')
    {
        free(result);
        return (s2);
    }
	while (i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		result[len_s1 + i] = s2[i];
		i++;
	}
	result[len_s1 + i] = '\0';
	free(s1);
	return (result);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while ((i < len) && s)
	{
		result[i] = s[start];
		start = start + 1;
		i = i + 1;
	}
	result[i] = '\0';
	return (result);
}