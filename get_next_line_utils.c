/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:24:51 by kadrouin          #+#    #+#             */
/*   Updated: 2025/01/21 10:25:07 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *string)
{
	int	count;

	count = 0;
	while (string[count])
		count++;
	return (count);
}

char	*ft_strdup(char *string)
{
	int		i;
	int		size;
	char	*duplicate;

	i = 0;
	size = ft_strlen(string);
	duplicate = malloc(sizeof(char) * (size + 1));
	if (!duplicate)
		return (0);
	while (string[i])
	{
		duplicate[i] = string[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
