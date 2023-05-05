/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:55:55 by tlivroze          #+#    #+#             */
/*   Updated: 2022/11/22 08:37:58 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	bytes = nmemb * size;
	void			*pointer;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	pointer = malloc(bytes);
	if (pointer)
		ft_bzero(pointer, bytes);
	return (pointer);
}
