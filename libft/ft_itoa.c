/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:15:36 by tlivroze          #+#    #+#             */
/*   Updated: 2023/03/06 16:56:06 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	intlen(long n)
{
	long	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static int	get_sign(long *nombre)
{
	int		sign;

	sign = 0;
	if (*nombre < 0)
	{
		sign = 1;
		*nombre = -(*nombre);
	}
	return (sign);
}

static char	*zero(void)
{
	char	*height;

	height = malloc(2);
	if (!height)
		return (NULL);
	height[0] = '0';
	height[1] = 0;
	return (height);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;
	int		sign;
	int		i;
	long	m;

	m = (long)n;
	i = 0;
	sign = get_sign(&m);
	if (m == 0)
		return (zero());
	len = intlen(m);
	str = malloc (sizeof(char) * (len + sign + 1));
	if (!str)
		return (NULL);
	if (sign == 1)
		str[0] = '-';
	while (m > 0)
	{
		str[len - 1 - i + sign] = m % 10 + '0';
		i++;
		m = m / 10;
	}
	return (str[i + sign] = '\0', str);
}
