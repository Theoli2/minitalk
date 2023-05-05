/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:52 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/04 15:48:26 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	subprinthexa(unsigned long x, char *base)
{
	int	count;

	count = 0;
	if (x > 0)
	{
		count += subprinthexa(x / 16, base);
		printchar(base[x % 16]);
		count++;
	}
	return (count);
}

int	printhexa(unsigned long x, char *base)
{
	int	count;

	count = 0;
	if (x == 0)
		return (write(1, "0", 1), 1);
	count += subprinthexa(x, base);
	return (count);
}
