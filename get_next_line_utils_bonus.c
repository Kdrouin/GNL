/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:07:32 by kadrouin          #+#    #+#             */
/*   Updated: 2025/01/23 11:07:32 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (size + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[size] = 0;
	return (res);
}

char	*ft_strchr(const char *string, int c )
{
	char	*temp;

	temp = (char *)string;
	while (*temp != c && *temp != 0)
		temp++;
	if (*temp == c)
		return (temp);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}
