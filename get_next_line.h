/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadrouin <kadrouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:45:59 by kadrouin          #+#    #+#             */
/*   Updated: 2025/01/23 10:45:59 by kadrouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>

char	*read_file(int fd, char *res);
char	*get_next_line(int fd);
char	*ft_free(char *buffer, char *ptr);
char	*ft_strchr(const char *string, int c);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t elementCount, size_t elementSize);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

#endif
