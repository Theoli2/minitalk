/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:45:29 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/09 14:12:50 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) != NULL && s1[start] != '\0')
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end]) != NULL && end > 0)
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}
