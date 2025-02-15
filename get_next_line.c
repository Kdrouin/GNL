/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:27:02 by kadrouin          #+#    #+#             */
/*   Updated: 2025/01/22 15:27:02 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *ptr, int c)
{
	char	*temp;

	if (c == 1)
	{
		free(buffer);
		free(ptr);
		buffer = NULL;
		ptr = NULL;
		return (NULL);
	}
	if (c == 2)
	{
		temp = ft_strjoin(buffer, ptr);
		free (buffer);
		buffer = NULL;
		return (temp);
	}
	return (NULL);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		bt;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	bt = 1;
	while (bt > 0)
	{
		bt = read(fd, buffer, BUFFER_SIZE);
		if (bt == -1)
		{
			free (res);
			free (buffer);
			res = NULL;
			buffer = NULL;
			return (res);
		}
		buffer[bt] = '\0';
		res = ft_free(res, buffer, 2);
		if (ft_strchr(res, '\n'))
			break ;
	}
	free (buffer);
	return (res);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i] || (buffer[i] == '\n' && !buffer[i + 1]))
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	while (buffer[++i])
		next[j++] = buffer[i];
	next[j] = 0;
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	buffer = read_file(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
