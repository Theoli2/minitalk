/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:47:53 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/09 17:39:39 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conv(char a)
{
	int	i;

	i = a - 48;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			result;
	int			n;

	result = 0;
	n = 1;
	while ((*nptr >= 9 && *nptr <= 15) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			n = -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
	{
		if (*nptr > 47 && *nptr < 58)
			result = (result * 10) + conv(*nptr);
		nptr++;
	}
	result = result * n;
	return (result);
}
