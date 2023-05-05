/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlivroze <tlivroze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:33:51 by tlivroze          #+#    #+#             */
/*   Updated: 2023/02/04 15:51:39 by tlivroze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	subprintunsigned(unsigned int u)
{
	int	count;

	count = 0;
	if (u > 0)
	{
		count += subprintunsigned(u / 10);
		count++;
		printchar((u % 10) + 48);
	}
	return (count);
}

int	printunsigned(unsigned int u)
{
	int	count;

	count = 0;
	if (u == 0)
		return (write(1, "0", 1), 1);
	count += subprintunsigned(u);
	return (count);
}
