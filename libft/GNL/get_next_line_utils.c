/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:15:16 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/07 17:25:05 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len] != '\0')
// 		++len;
// 	return (len);
// }

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	char	*r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	r = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r)
		return (NULL);
	ft_strlcpy_gnl(r, s1, ft_strlen(s1) + 1);
	ft_strlcpy_gnl((r + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	free(s1);
	return (r);
}
