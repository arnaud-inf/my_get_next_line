/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelison <aelison@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:09:17 by aelison           #+#    #+#             */
/*   Updated: 2024/03/23 10:45:30 by aelison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(size * nmemb);
	if (!result)
		return (NULL);
	while (i < nmemb * size)
	{
		result[i] = 0;
		i = i + 1;
	}
	return ((void *)result);
}

static char	*ft_only_read(char *buffer, int read_val)
{
	char	*result;

	if (read_val <= BUFFER_SIZE)
	{
		result = ft_substr(buffer, 0, read_val);
		return (result);
	}
	return (NULL);
}

static char	*get_line(char *result, int indice)
{
	char	*res;

	if (indice != -1)
	{
		res = ft_substr(result, 0, indice + 1);
		return (res);
	}
	return (NULL);
}

static char	*read_file(int fd, char *join, char *buffer, char **stock)
{
	int		read_val;
	char	*result;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	read_val = 1;
	while (read_val != 0)
	{
		read_val = read(fd, buffer, BUFFER_SIZE);
		if (read_val == -1)
			break ;
		join = ft_strjoin(join, ft_only_read(buffer, read_val));
		result = get_line(join, ft_strchr(join, '\n'));
		if (result != NULL)
		{
			*stock = ft_substr(join, ft_strchr(join, '\n') + 1, read_val);
			return (result);
		}
		free(buffer);
	}
	if (join[0] == 0 || read_val == -1)
		return (NULL);
	return (join);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*join;
	char		*result;
	static char	*stock;

	join = ft_strdup("\0");
	buffer = (char *)ft_calloc(BUFFER_SIZE, 1);
	if (stock != NULL)
	{
		join = ft_strjoin(join, stock);
		free(stock);
		stock = NULL;
	}
	result = get_line(join, ft_strchr(join, '\n'));
	if (result != NULL)
	{
		stock = ft_substr(join, ft_strchr(join, '\n') + 1, ft_strlen(join));
		return (result);
	}
	free(result);
	result = read_file(fd, join, buffer, &stock);
	return (free(join), result);
}
