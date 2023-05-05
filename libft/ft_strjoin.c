/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:32:43 by tlivroze          #+#    #+#             */
/*   Updated: 2022/11/22 08:39:17 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	r = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	ft_strlcpy((r + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (r);
}
