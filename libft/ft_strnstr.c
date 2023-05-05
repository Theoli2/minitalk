/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:09:45 by tlivroze          #+#    #+#             */
/*   Updated: 2022/11/26 14:06:11 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!big && len == 0)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = ft_strlen(little);
	while (*big != '\0' && len >= i)
	{
		if (*big == *little && ft_memcmp(big, little, i) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
